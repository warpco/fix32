
        .syntax     unified
        .arch       armv7e-m
        .cpu        cortex-m4
        .thumb

        .global     fix32_trun
        .type       fix32_trun, "function"


@ Returns the integer part of a fixed-point number specified in the first
@ argument. The second argument specifies the format of the first argument.
@ For more information, see the function description in the header file.
@
@ Execution time: 9-11 cycles
@ Absolute error: 0 LSB

        .section   .fix32_trun, "x"
        .align

@ The algorithm consist of the three steps. First, the input is splitted
@ to the magnitude and sign part. Next, the fractional bits are discarded.
@ And the last step restores the sign of the input value.

fix32_trun:
        tst         r0, r0
        negmi       r0, r0
        lsr         r0, r0, r1
        lsl         r0, r0, r1
        negmi       r0, r0
        bx          lr


        .end
