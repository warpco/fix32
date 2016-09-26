
            import  fix32_inv_table
            export  fix32_inv


; Returns the multiplicative inverse or reciprocal of a non-zero fixed-point
; number passed in the first argument. The format of the number is specified
; through the second argument. For more information see the header file.
;
; The current implementation uses the combination of table lookup for a rough
; first approximation, and the two iterations of the Newton-Raphson method to
; improve the accuracy of the result.
;
; Execution time: 38-46 cycles
; Absolute error: 1.0 LSB

            area    |.fix32_inv|, code
            thumb

            align
fix32_inv   proc
            push    {lr}

; Splits the input number to the magnitude and sign parts. The magnitude part
; is passed to the Newton-Raphson method, as it can only take positive values.
; The sign part is used to restore the sign of the final result.

            asr     ip, r0, #31
            eor     r0, r0, ip
            sub     r0, r0, ip

; Normalizes the magnitude part to the range from one-half to one at the Q32
; fixed-point representation. Calculates the denormalization shift which will
; be used to scale the final result to the required fixed-point representation.

            clz     lr, r0
            lsl     r0, r0, lr
            rsb     lr, lr, #62
            sub     lr, lr, r1
            sub     lr, lr, r1

; Looks up on the nine most significant bits of the divisor to determine the
; initial nine-bit Q8 estimate to its reciprocal. Because the leading bit of
; the divisor is always set, it is not used to access the table. The leading
; bit of a reciprocal is always set too, so the lookup table stores only its
; eight least significand bits, the ninth bit is restored by software.

            ldr     r1, =fix32_inv_table
            lsr     r2, r0, #23
            sub     r2, r2, #256
            ldrb    r1, [r1, r2]
            add     r1, r1, #256

; Performs the first Newton-Raphson iteration, producing the Q16 estimate to
; the reciprocal of a divisor.

            mul     r2, r1, r1
            umull   r3, r2, r0, r2
            rsb     r2, r1, lsl #9

; Performs the second Newton-Raphson iteration, producing the Q30 estimate to
; the reciprocal of a divisor. The second to last instruction also clears the
; carry flag to make the subsequent rounding work properly.

            umull   r1, r3, r2, r2
            movs    r1, r1, lsr #2
            adc     r1, r3, lsl #30
            umull   r1, r0, r1, r0
            adds    r0, r1, lsr #31
            rsb     r0, r2, lsl #15

; Denormalizes the reciprocal to the required fixed-point format, rounds the
; result, and restores its sign. To make the rounding work properly when the
; denormalization shift is zero, the carry flag must be cleared.

            lsrs    r0, r0, lr
            adc     r0, r0, #0
            eor     r0, r0, ip
            sub     r0, r0, ip

            pop     {pc}
            endp
            align


            end
