
        .syntax     unified
        .arch       armv7e-m
        .cpu        cortex-m4
        .thumb

        .global     fix32_mul
        .type       fix32_mul, "function"


@ Returns the product of two fixed-point numbers. The first two arguments
@ specify numbers representing the multiplicands. The format of the input
@ numbers is specified in the last argument. For more information, see the
@ function description in the header file.
@
@ Execution time: 7-9 cycles
@ Absolute error: 0.5 LSB

        .section   .fix32_mul, "x"
        .align

fix32_mul:
        smull       r0, r1, r0, r1
        lsrs        r0, r0, r2
        rsb         r2, r2, #32
        lsl         r1, r1, r2
        adc         r0, r0, r1
        bx          lr


        .end
