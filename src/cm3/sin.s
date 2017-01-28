
        .syntax     unified
        .arch       armv7-m
        .cpu        cortex-m3
        .thumb

        .global     fix32_sin
        .type       fix32_sin, "function"


@ Returns the sine of a fixed-point angle. The first argument specifies
@ a number representing an angle. The format of the number is specified
@ in the second argument. For more details, see the function description
@ in the header file.
@
@ Execution time: 46-56 cycles
@ Absolute error: 2.1 LSB

        .section   .fix32_sin, "x"
        .align

fix32_sin:
        push        {lr}

@ Normalizes the angle to the range from zero to one-half at the Q33 fixed
@ point representation. The carry flag will indicate whether the angle was
@ in the first or the second semicircle. The obtained normalization shift
@ will be used to scale the result back to the initial fixed-point format.

        rsb         lr, r1, #33
        lsls        r0, r0, lr
        sub         lr, lr, #2

@ Normalizes the angle to the range from zero to one-quarter and splits the
@ angle bits into two parts. The upper bits determine the expansion point and
@ are used to index the lookup-table. The lower bits form an offset from the
@ expansion point.

        mov         r1, r0, asr #31
        eor         r0, r0, r1, lsl #25
        mov         r2, r0, lsr #25
        sub         r0, r0, r2, lsl #25
        rsb         r3, r2, #63

@ To evaluate a Taylor polynomial for the sine function we need to know the
@ sine and cosine values at the expansion point. Theese values are taken from
@ the lookup table. When the angle is in the second quadrant, the values are
@ swapped, which transforms the polynomial so that it approximates the cosine
@ instead of sine.

        ldr         ip, =fix32_sin_table
        ldr         r2, [ip, r2, lsl #2]
        ldr         r3, [ip, r3, lsl #2]
        eor         r3, r1

@ Converts the offset from revolutions to radians. Since the table entries
@ are pointing to the middle of the interval, the offset value is adjusted
@ by subtracting a half of the interval length.

        lsl         r0, #3
        sub         r0, #0x8000000
        movw        ip, #0xed51
        movt        ip, #0x6487
        smull       r0, r1, ip, r0

@ Calculates the last coefficient of the third-order Taylor series expansion
@ of a sine function. This coefficient can be calculated with less accuracy,
@ which eliminates the one long multiplication.

        movw        ip, #0x1555
        asr         r0, r3, #15
        mul         r0, r0, ip

@ Calculates the other terms of the third-order Taylor series expansion of
@ a sine function. To reduce the number of multiplications the polynomial
@ is evaluated using Horner's method.

        smull       ip, r0, r1, r0
        add         r0, r0, r2, asr #1
        smull       ip, r0, r1, r0
        sub         r0, r0, r3
        smull       ip, r0, r1, r0
        rsb         r0, r0, r2

@ Corrects the sign of the obtained estimate if the angle value was in the
@ second semicircle. Then, converts the result to the required fixed-point
@ representation and rounds the result. The second instruction makes shure
@ the carry flag is cleared. Because if the denormalization shift is zero,
@ the shift instruction will not update the carry flag, which can cause an
@ incorrect rounding.

        rsbcs       r0, r0, #0
        lsls        ip, lr, #1
        asrs        r0, r0, lr
        adc         r0, r0, #0
        pop         {pc}


        .end
