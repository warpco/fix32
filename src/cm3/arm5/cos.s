
            import  fix32_sin_table
            export  fix32_cos


; Returns the cosine of a fixed-point angle. The first argument specifies
; an angle exressed in revolutions. The format of the angle is specified
; in the second argument. See the function description in the header file
; for more information.
;
; Execution time: 48-58 cycles
; Absolute error: 2.2 LSB

            area    |.fix32_cos|, code
            thumb

            align
fix32_cos   proc
            push    {lr}

; The code below can only work with non-negative angles. Due to the symmetry
; of the cosine function, all that is necessary to extend the domain to the
; negative angles is to calculate the absolute value of a specified angle.

            eor     ip, r0, r0, asr #31
            sub     r0, ip, r0, asr #31

; Normalizes the angle to the range from zero to one-half at the Q33 fixed
; point representation. The carry flag will indicate whether the angle was
; in the first or the second semicircle. The obtained normalization shift
; will be used to scale the result back to the initial fixed-point format.

            rsb     lr, r1, #33
            lsls    r0, r0, lr
            sub     lr, lr, #2

; Normalizes the angle to the range from zero to one-quarter and splits the
; angle bits into two parts. The upper bits define the expansion point and
; are used to index the lookup-table. The lower bits are used as an offset
; from the expansion point.

            mov     r1, r0, asr #31
            eor     r0, r1, lsl #25
            mov     r3, r0, lsr #25
            sub     r0, r3, lsl #25
            rsb     r2, r3, #63

; To evaluate the Taylor polynomial for the cosine function we need to know
; the cosine and sine values at the expansion point. Theese values are taken
; from the lookup table. When the angle is in the second quadrant, the values
; are swapped, which transforms the polynomial so that it approximates minus
; sine instead of cosine.

            ldr     ip, =fix32_sin_table
            ldr     r2, [ip, r2, lsl #2]
            ldr     r3, [ip, r3, lsl #2]
            eor     r2, r1

; Converts the offset from revolutions to radians. Since the table entries
; are pointing to the middle of the interval, the offset value is adjusted
; by subtracting a half of the interval length.

            lsl     r0, #3
            sub     r0, #0x08000000
            mov32   ip, #0x6487ed51
            smull   r0, r1, ip, r0

; Calculates the last coefficient of the third-order Taylor series expansion
; of a sine function. This coefficient can be calculated with less accuracy,
; which eliminates the one long multiplication.

            mov     ip, #0x1555
            asr     r0, r3, #15
            mul     r0, r0, ip

; Calculates the remaining terms of the third-order Taylor series expansion
; of the cosine function. The polynomial is evaluated using Horner's method
; to reduce the number of multiplications.

            smull   ip, r0, r1, r0
            rsb     r0, r2, asr #1
            smull   ip, r0, r1, r0
            add     r0, r3
            smull   ip, r0, r1, r0
            rsb     r0, r2

; Corrects the sign of the obtained estimate if the angle value was in the
; second semicircle. Then, converts the result to the required fixed-point
; representation and rounds the result. The second instruction makes shure
; the carry flag is cleared. Because if the denormalization shift is zero,
; the shift instruction will not update the carry flag, which can cause an
; incorrect rounding.

            rsbcs   r0, r0, #0
            lsls    ip, lr, #1
            asrs    r0, r0, lr
            adc     r0, r0, #0

            pop     {pc}
            endp
            align


            end
