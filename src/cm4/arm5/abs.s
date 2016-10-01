
            export  fix32_abs


; Returns the absolute value of a fixed-point number. The first-and-only
; argument specifies a number whose absoute value is to be determined.
; For more information, see the function description in the header file.
;
; Execution time: 4-6 cycles
; Absolute error: 0 LSB

            area    |.fix32_abs|, code
            thumb

            align
fix32_abs   proc
            eor     r1, r0, r0, asr #31
            sub     r0, r1, r0, asr #31
            bx      lr
            endp
            align


            end
