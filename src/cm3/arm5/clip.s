
                export  fix32_clip


; Clamps a fixed-point number within a particular range. The first argument
; specifies a number to be clamped. The second argument specifies the lower
; range bound. The third argument specifies the upper range bound. For more
; information, see the function description in the header file.
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
