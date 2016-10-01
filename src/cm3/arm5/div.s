
            import  fix32_inv_table
            export  fix32_div


; Returns the quotient of two fixed-point numbers. The first two arguments
; specify a dividend and non-zero divisor. The last argument specifies the
; format of the first two arguments. For more information, see the function
; description in the header file.
;
; Execution time: 46-56 cycles
; Absolute error: 2.0 LSB

            area    |.fix32_div|, code
            thumb

            align
fix32_div   proc
            push    {lr}

; Splits the divisor to the magnitude and sign parts. The magnitude part goes
; to the Newton-Raphson method, as it can only take positive values. The sign
; part is combined with the dividend.

            tst     r1, r1
            negmi   r0, r0
            negmi   r1, r1

; Normalizes the divisor to the range from one-half to one at the Q32 fixed
; point representation. Finds the normalization shift which will be used to
; scale the final result to the required fixed-point representation.

            clz     lr, r1
            lsl     r1, r1, lr
            rsb     lr, lr, #62
            sub     lr, lr, r2

; Looks up on the nine most significant bits of the divisor to determine the
; initial nine-bit Q8 estimate to its reciprocal. Because the leading bit of
; the divisor is always set, it is not used to access the table. The leading
; bit of a reciprocal is always set too, so the lookup table stores only its
; eight least significand bits, the ninth bit is restored by software.

            ldr     ip, =fix32_inv_table
            lsr     r2, r1, #23
            sub     r2, r2, #256
            ldrb    ip, [ip, r2]
            add     ip, ip, #256

; Performs the first Newton-Raphson iteration, producing the Q16 estimate
; to the multiplicative inverse of the divisor.

            mul     r2, ip, ip
            umull   r3, r2, r1, r2
            rsb     r2, ip, lsl #9

; Performs the second Newton-Raphson iteration, producing the Q30 estimate
; to the multiplicative inverse of the divisor.

            umull   ip, r3, r2, r2
            movs    ip, ip, lsr #2
            adc     ip, r3, lsl #30
            umull   r3, ip, r1, ip
            add     ip, r3, lsr #31
            rsb     ip, r2, lsl #15

; Multiplies the absolute value of a dividend by the multiplicative inverse
; of a divisor. On the next step the resulting product will be denormalized
; to get the actual quotient.

            smull   r0, r1, r0, ip

; Performs the denormalization by arithmetically shifting the product from
; the previous step to the right. Because the number of bits to be shifted
; can be greater than 32, the operation is performed in two steps. The code
; below partially shifts the quotient to reduce the number of places to be
; shifted to no more than 32.

            subs    lr, lr, #32
            movgt   r0, r1
            asrgt   r1, r1, #31
            addle   lr, lr, #32

; Now, when the number of bits to be shifted is less than or equal to 32,
; the code below finally denormalizes the quotient and rounds the result.

            lsrs    r0, r0, lr
            rsb     lr, lr, #32
            lsl     r1, r1, lr
            adc     r0, r0, r1

            pop     {pc}
            endp
            align


            end
