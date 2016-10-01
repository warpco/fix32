
            import  fix32_inv_table
            export  fix32_inv


; Returns the reciprocal of a fixed-point number. The number is specified
; in the first argument. The second argument specifies the number format.
; For more information, see the function description in the header file.
;
; Execution time: 31-33 cycles
; Absolute error: 1.0 LSB

            area    |.fix32_inv|, code
            thumb

            align
fix32_inv   proc
            push    {lr}

; Splits the input number to the magnitude and sign part. The magnitude part
; is passed to the Newton-Raphson method, because the current implementation
; only takes positive numbers. The sign part will be used to restore the sign
; of the obtained estimate.

            asr     ip, r0, #31
            eor     r0, r0, ip
            sub     r0, r0, ip

; Normalizes the magnitude part of the input value to the range from one-half
; to one at the Q32 fixed-point format. Then, calculates the denormalization
; shift which is used to scale the result to the required fixed-point format.

            clz     lr, r0
            lsl     r0, r0, lr
            rsb     lr, lr, #62
            sub     lr, r1, lsl #1

; Looks up on the nine most significant bits of the input value to determine
; the initial nine-bit Q8 estimate to its reciprocal. Since the leading bit
; of the input value is always set, it is not used during lookup. The ninth
; bit of the reciprocal is always set too, so the lookup table stores only
; the eight bits, while the ninth bit is restored by software.

            ldr     r1, =fix32_inv_table
            lsr     r2, r0, #23
            sub     r2, r2, #256
            ldrb    r1, [r1, r2]
            add     r1, r1, #256

; Performs the first Newton-Raphson iteration, producing a rough estimate
; to the required reciprocal value. The estimate will be in the Q16 fixed-
; point format.

            mul     r2, r1, r1
            umull   r3, r2, r0, r2
            rsb     r2, r1, lsl #9

; Performs the second Newton-Raphson iteration, producing the Q30 estimate
; to the reciprocal of the input value. The second to last instruction also
; clears the carry flag to make the subsequent rounding work properly.

            umull   r1, r3, r2, r2
            movs    r1, r1, lsr #2
            adc     r1, r3, lsl #30
            umull   r1, r0, r1, r0
            adds    r0, r1, lsr #31
            rsb     r0, r2, lsl #15

; Using the calculated denormalization shift, denormalizes the reciprocal
; to the required fixed-point format, rounds the result, and restores its
; sign. To make the rounding work properly when the denormalization shift
; is zero, the carry flag must be cleared.

            lsrs    r0, r0, lr
            adc     r0, r0, #0
            eor     r0, r0, ip
            sub     r0, r0, ip

            pop     {pc}
            endp
            align


            end
