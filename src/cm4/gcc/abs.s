
        .syntax     unified
        .arch       armv7e-m
        .cpu        cortex-m4
        .thumb

        .global     fix32_abs
        .type       fix32_abs, "function"


@ Returns the absolute value of a fixed-point number. The first-and-only
@ argument specifies a number whose absoute value is to be determined.
@ For more information, see the function description in the header file.
@
@ Execution time: 4-6 cycles
@ Absolute error: 0 LSB

        .section   .fix32_abs, "x"
        .align

fix32_abs:
        eor         r1, r0, r0, asr #31
        sub         r0, r1, r0, asr #31
        bx          lr


        .end
