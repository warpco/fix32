
                export  fix32_frac


; Returns the fractional part of a fixed-point number. The first argument
; specifies a number whose integer part is to be found. The format of the
; number is specifies in the second argument. For additional information,
; see the function description in the header file.
;
; Execution time: 10-12 cycles
; Absolute error: 0 LSB

                area    |.fix32_frac|, code
                thumb

                align
fix32_frac      proc

; The algorithm consist of the three steps. First, the number is splitted
; into the magnitude and sign part. Then, the integer bits are discarded.
; And the last step restores the sign of the input value.

                tst     r0, r0
                negmi   r0, r0
                lsr     r2, r0, r1
                lsl     r2, r2, r1
                sub     r0, r0, r2
                negmi   r0, r0
                bx      lr
                endp
                align


                end
