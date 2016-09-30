
        .syntax     unified
        .arch       armv7-m
        .cpu        cortex-m3
        .thumb

        .global     fix32_flip
        .type       fix32_flip, "function"


@ Returns a value with the magnitude of the first argument and the sign
@ of product of the both arguments. For additional information, see the
@ function description in the header file.
@
@ Execution time: 4-6 cycles
@ Absolute error: 0 LSB

        .section   .fix32_flip, "x"
        .align

fix32_flip:
        eor         r0, r0, r1, asr #31
        sub         r0, r0, r1, asr #31
        bx          lr


        .end
