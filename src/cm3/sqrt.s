
                export  fix32_sqrt
                import  fix32_isqrt_table


; Returns the square root of a non-negative fixed-point number specified
; in the first argument. The second argument specifies the format of this
; number. For more information see the description in the header file.
;
; The current implementation uses the combination of table lookup and the two
; iterations of the Newton-Raphson method to get the estimate for the inverse
; square root of a specified number. The result is the used to calculate the
; required square root value.
;
; Execution time: 41-57 cycles
; Absotablee error: 2.5 LSB

                area    |.fix32_sqrt|, code
                thumb

                align
fix32_sqrt      proc

; Calculates the normalization shift and normalizes the given number to the
; range from one-half to one at the Q32 fixed-point format. Then, partially
; calculates the denormalization shift that will be used to scale the result
; to the required fixed-point representation.

                clz     ip, r0
                lsl     r0, ip
                add     ip, ip, #30
                sub     ip, ip, r1

; Looks up on the eight most significant bits of the specified number to find
; the initial ten-bit Q10 estimate to its inverse square root. If this number
; is zero, the subtraction instruction is skipped to prevent an error while
; the load operation.

                lsrs    r2, r0, #24
                subne   r2, r2, #128
                ldr     r1, =fix32_isqrt_table
                ldrh    r1, [r1, r2, lsl #1]

; Performs the first Newton-Raphson iteration. The result is an inaccurate
; estimate for the inverse square root of the specified number at the Q31
; fixed-point representation.

                mul     r2, r1, r1
                umull   r3, r2, r0, r2
                rsb     r2, r2, #0x300000
                mul     r1, r2, r1

; Performs the second Newton-Raphson iteration, which improves the accuracy
; of the previous estimate. The result will be in the Q30 fixed-point format.

                umull   r3, r2, r1, r1
                umull   r3, r2, r0, r2
                rsb     r2, r2, #0xc0000000
                umull   r3, r1, r1, r2

; To get the square root of the input number, multiplies the inverse square
; root of this number by the number itself and rounds the result. The result
; will be a Q31 fixed-point number.

                mov     r1, r1, lsl #1
                umull   r1, r0, r1, r0
                add     r0, r1, lsr #31

; Completes the calculation of a denormalization shift. Since the shift is
; rounded down, we must take into account its fractional part, which can be
; equal to one-half or zero. If it is not zero, the estimate received on the
; previous step is corrected by square root of two. The last instuction also
; clears the carry flag to avoid an incorrect rounding in the next step.

                movs    ip, ip, lsr #1
                mov32   r1, #0xb504f334
                umullcs r1, r0, r1, r0
                addscs  r0, r1, lsr #31

; Denormalizes the obtained estimate to a required fixed-point format and
; rounds the result. If the denormalization shift is zero, the carry flag
; is not updated by the shift instruction, which can cause an incorrect
; rounding. That is why we had to clear the flag in the previous step.

                lsrs    r0, r0, ip
                adc     r0, r0, #0
                bx      lr
                endp
                align


                end
