
            export  fix32_mul


; Returns the product of two fixed-point numbers. The first two arguments
; specify numbers representing the multiplicands. The format of the input
; numbers is specified in the last argument. For more information, see the
; function description in the header file.
;
; Execution time: 9-13 cycles
; Absolute error: 0.5 LSB

            area    |.fix32_mul|, code
            thumb

            align
fix32_mul   proc
            smull   r0, r1, r0, r1
            lsrs    r0, r0, r2
            rsb     r2, r2, #32
            lsl     r1, r1, r2
            adc     r0, r0, r1
            bx      lr
            endp


            end
