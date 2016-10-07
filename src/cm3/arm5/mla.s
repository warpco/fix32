
            export  fix32_mla


; Multiplies fixed-point values from the first two arguments, adds a value
; from the third argument, and returns the result. The format of the input
; values is specified in the fourth argument. For additional information,
; see the function description in the header file.
;
; Execution time: 10-14 cycles
; Absolute error: 0.5 LSB

            area    |.fix32_mla|, code
            thumb

            align
fix32_mla   proc
            smull   r0, r1, r0, r1
            lsrs    r0, r0, r3
            rsb     r3, r3, #32
            lsl     r1, r1, r3
            adc     r0, r0, r1
            add     r0, r0, r2
            bx      lr
            endp


            end
