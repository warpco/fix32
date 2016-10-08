
            export  fix32_mls


; Multiplies the values from the first two arguments, subtracts the product
; from the value in the third argument, and returns the result. The format
; of the input values is specified in the fourth argument. See the function
; description in the header file for more information.
;
; Execution time: 8-10 cycles
; Absolute error: 0.5 LSB

            area    |.fix32_mls|, code
            thumb

            align
fix32_mls   proc
            smull   r0, r1, r0, r1
            lsrs    r0, r0, r3
            rsb     r3, r3, #32
            lsl     r1, r1, r3
            adc     r0, r0, r1
            sub     r0, r2, r0
            bx      lr
            endp


            end
