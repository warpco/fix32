
        .syntax     unified
        .arch       armv7e-m
        .cpu        cortex-m4
        .thumb

        .global     fix32_isqrt
        .type       fix32_isqrt, "function"


@ Returns the inverse square root of a fixed-point number specified in the
@ the first argument. The second argument specifies the fixed-point format
@ of the first argument. For more information, see the function description
@ in the header file.
@
@ Execution time: 29-31 cycles
@ Absolute error: 2.0 LSB

        .section   .fix32_isqrt, "x"
        .align

@ Calculates the normalization shift and normalizes the given number to the
@ range from one-half to one at the Q32 fixed-point representation.

fix32_isqrt:
        clz         ip, r0
        lsl         r0, ip

@ Calculates the denormalization shift that will be used to scale the result
@ to the required fixed-point representation.

        sub         r1, r1, r1, lsl #2
        rsb         ip, ip, #94
        add         ip, ip, r1
        lsrs        ip, ip, #1

@ Looks up on the eight most significant bits of the input value to determine
@ the initial ten-bit Q10 estimate to its inverse square root.

        ldr         r1, =fix32_isqrt_table
        lsr         r2, r0, #24
        sub         r2, r2, #128
        ldrh        r1, [r1, r2, lsl #1]

@ Performs the first Newton-Raphson iteration, which gives an inaccurate Q31
@ estimate to the inverse square root of the specified number.

        mul         r2, r1, r1
        umull       r3, r2, r0, r2
        rsb         r2, r2, #0x300000
        mul         r1, r2, r1

@ Performs the second Newton-Raphson iteration, which improves the accuracy
@ of the previous estimate up to an acceptable level. The result will be in
@ the same Q31 fixed-point representation.

        umull       r3, r2, r1, r1
        umull       r3, r2, r0, r2
        rsb         r2, r2, #0xc0000000
        umull       r3, r2, r1, r2
        lsl         r0, r2, #1

@ Since the denormalization shift is rounded down, we must take into account
@ its fractional part, which can be equal to one-half or zero. If it is not
@ zero, the estimate received on the previous step is corrected by square
@ root of two. The last instuction also clears the carry flag to avoid an
@ incorrect rounding in the next step.

        movw        r1, #0xf334
        movt        r1, #0xb504
        umullcs     r1, r0, r1, r0
        addscs      r0, r0, r1, lsr #31

@ Denormalizes the estimate to the required fixed-point representation and
@ rounds the result. If the denormalization shift is zero, the carry flag
@ is not updated by the shift instruction, which can cause an incorrect
@ rounding. That is why we had to clear the flag in the previous step.

        lsrs        r0, r0, ip
        adc         r0, r0, #0
        bx          lr


        .end
