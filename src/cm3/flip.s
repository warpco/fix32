
            export  fix32_flip


; Returns a value with the magnitude of the first argument and the sign
; of product of the both arguments. Zero is treated as a positive number.
; For more information see the description in the header file.
;
; Execution time: 4-6 cycles
; Absolute error: 0 LSB

            area    |.fix32_flip|, code
            thumb

            align
fix32_flip  proc
            eor     r0, r0, r1, asr #31
            sub     r0, r0, r1, asr #31
            bx      lr
            endp
            align


            end
