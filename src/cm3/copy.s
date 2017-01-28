
        .syntax     unified
        .arch       armv7-m
        .cpu        cortex-m3
        .thumb

        .global     fix32_copy
        .type       fix32_copy, "function"


@ Returns a value with the magnitude of the first argument and the sign
@ of the second argument. For additional information, see the function
@ description in the header file.
@
@ Execution time: 5-7 cycles
@ Absolute error: 0 LSB

        .section   .fix32_copy, "x"
        .align

fix32_copy:
        eor         ip, r0, r1
        eor         r0, r0, ip, asr #31
        sub         r0, r0, ip, asr #31
        bx          lr


        .end
