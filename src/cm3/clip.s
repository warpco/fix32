
                export  fix32_clip


; Returns the first argument clamped within a range defined by the second and
; third argument. For more information see the description in the header file.
;
; Execution time: 9-11 cycles
; Absolute error: 0 LSB

                area    |.fix32_clip|, code
                thumb

                align
fix32_clip      proc
                mov     r3, r0
                cmp     r3, r1
                movlt   r0, r1
                cmp     r3, r2
                movgt   r0, r2
                bx      lr
                endp
                align


                end
