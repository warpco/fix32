
            export  fix32_copy


; Returns a value with the magnitude of the first argument and the sign
; of the second argument. The function treats zero as a positive number.
; For more information see the description in the header file.
;
; Execution time: 5-7 cycles
; Absolute error: 0 LSB

            area    |.fix32_copy|, code
            thumb

            align
fix32_copy  proc
            eor     ip, r0, r1
            eor     r0, r0, ip, asr #31
            sub     r0, r0, ip, asr #31
            bx      lr
            endp
            align


            end
