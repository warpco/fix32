#ifndef FIX32_H
#define FIX32_H


//
// Returns the product of two fixed-point numbers.
//
// @param a, b
// Fixed-point numbers representing the multiplicands. This numbers can
// be specified in any fixed-point format, from Q0 to Q31.
//
// @param exp
// Value specifying a fixed-point format of the first argument. This value
// must be in the range from 0 to 31, which corresponds to the fixed-point
// formats from Q0 to Q31 repsectively. If the value exceeds these limits,
// the behavior is undefined.
//
// @return
// The product of two specified numbers. The product will have the same
// fixed-point format as the input multiplicands. If the product cannot
// be represented in this format, the behavior is undefined.
//
fix32_t fix32_mul(fix32_t a, fix32_t b, sint_t exp);


//
// Returns the reciprocal of a fixed-point number.
//
// @param a
// Non-zero fixed-point number whose reciprocal is to be found. The number
// can be in any fixed-point format from Q1 to Q30. The actual fixed-point
// format is specified by the second argument. If the number is zero, the
// behavior is undefined.
//
// @param exp
// Value specifying a fixed-point format of the first argument. This value
// must be in the range from 1 to 30, which corresponds to the fixed-point
// formats from Q1 to Q30 repsectively. If the value exceeds these limits,
// the behavior is undefined.
//
// @return
// The reciprocal of the specified number. The return value will be in the
// same fixed-point format as the input argument. If the reciprocal cannot
// be represented in this format, the behavior is undefined.
//
fix32_t fix32_inv(fix32_t a, sint_t exp);


//
// Returns the quotient of two fixed-point numbers.
//
// @param a
// Fixed-point value which represents a dividend. This value can have any
// format, from Q1 to Q31. The third argument specifies the actual format.
//
// @param b
// Non-zero fixed-point value representing a divisor. This value can have
// any fixed-point format, from Q1 to Q31. The actual format is specified
// in the third argument. If the value is zero, the behavior is undefined.
//
// @param exp
// Value specifying the format of both the dividend and divisor. The value
// must be in the range from 1 to 31, which corresponds to the fixed-point
// formats from Q1 to Q31 respectively. If the value exceeds these limits,
// the behavior is undefined.
//
// @return
// The quotient of two specified fixed-point numbers. The result will have
// the same fixed-point format as the input values. If the quotient cannot
// be represented in this format, or the first two arguments are specified
// in different formats, the behavior is undefined.
//
fix32_t fix32_div(fix32_t a, fix32_t b, sint_t exp);


//
// Returns the inverse square root of a fixed-point number.
//
// @param a
// Positive fixed-point number whose inverse square root is to be computed.
// If the number is negative or zero, the behavior is undefined. The number
// can be in any fixed-point format, from Q1 to Q30.
//
// @param exp
// Value specifying a fixed-point format of the first argument. This value
// must be in the range from 1 to 30, which corresponds to the fixed-point
// formats from Q1 to Q30 repsectively. If the value exceeds these limits,
// the behavior is undefined.
//
// @return
// The inverse square root of the specified fixed-point number. The result
// will have the same fixed-point format as the input number. If it cannot
// be represented in this format, the behavior is undefined.
//
fix32_t fix32_isqrt(fix32_t a, sint_t exp);


//
// Returns the square root of a fixed-point number.
//
// @param a
// Non-negative fixed-point number whose square root is to be determined.
// The number can be in any fixed-point format, from Q1 to Q31. The last
// argument specifies the actual format.
//
// @param exp
// Value specifying a fixed-point format of the first argument. This value
// must be in the range from 1 to 31, which corresponds to the fixed-point
// formats from Q1 to Q31 repsectively. If the value exceeds these limits,
// the behavior is undefined.
//
// @return
// The square root of the specified number. The result will have the same
// format as the first argument. If the result cannot be represent in this
// format, the behavior is undefined.
//
fix32_t fix32_sqrt(fix32_t a, sint_t exp);


//
// Returns the trigonometric sine of a fixed-point angle.
//
// @param a
// Value representing an angle exressed in revolutions. The value can have
// any fixed-point format, from Q1 to Q31. The actual format is specified
// through the second argument.
//
// @param exp
// Value specifying a fixed-point format of the first argument. This value
// must be in the range from 1 to 31, which corresponds to the fixed-point
// formats from Q1 to Q31 repsectively. If the value exceeds these limits,
// the behavior is undefined.
//
// @return
// The trigonometric sine of the specified angle. The result will have the
// same fixed-point format as the input angle.
//
fix32_t fix32_sin(fix32_t a, sint_t exp);


//
// Returns the trigonometric cosine of a fixed-point angle.
//
// @param a
// Value representing an angle exressed in revolutions. The value can have
// any fixed-point format, from Q1 to Q31. The actual format is specified
// through the second argument.
//
// @param exp
// Value specifying a fixed-point format of the first argument. This value
// must be in the range from 1 to 31, which corresponds to the fixed-point
// formats from Q1 to Q31 repsectively. If the value exceeds these limits,
// the behavior is undefined.
//
// @return
// The trigonometric cosine of the specified angle. The result will have
// the same fixed-point format as the input angle.
//
fix32_t fix32_cos(fix32_t a, sint_t exp);


//
// Returns the absolute value of a fixed-point number.
//
// @param a
// Fixed-point number whose absolute value is to be found. The number can
// have any fixed-point format? there is no need to specify it explicitly.
//
// @return
// The absolute value of the specified number. The result will have the same
// fixed-point format as the input number. If the result cannot be represent
// in this format, the behavior is undefined.
//
fix32_t fix32_abs(fix32_t a);


//
// Returns a value with the magnitude of the first argument and the sign
// of the second argument. The function treats zero as a positive number.
//
// @param mag
// Number in any fixed-point format.
//
// @param sig
// Number in any fixed-point format. Zero is treated as a positive number.
//
// @return
// The value with the magnitude of the first argument and the sign of the
// second argument. The fixed-point format of the result will be the same
// as that of the first argument. The behavior is undefined if the result
// cannot be represented in this format.
//
fix32_t fix32_copy(fix32_t mag, fix32_t sig);


//
// Returns a value with the magnitude of the first argument and the sign
// of the product of both arguments. Zero is treated as a positive number.
//
// @param mag
// Number in any fixed-point format.
//
// @param sig
// Number in any fixed-point format. Zero is treated as a positive number.
//
// @return
// The value with the magnitude of the first argument and the sign of the
// product of both arguments. The result will be in the same format as the
// first argument. If the result cannot be represented in this fixed-point
// format, the behavior is undefined.
//
fix32_t fix32_flip(fix32_t mag, fix32_t sig);


//
// Returns the fractional part of a fixed-point number.
//
// @param a
// Fixed-point number whose fractional part is to be determined. The number
// can be in any fixed-point format, from Q1 to Q31.
//
// @param exp
// Value specifying a fixed-point format of the first argument. This value
// must be in the range from 1 to 31, which corresponds to the fixed-point
// formats from Q1 to Q31 repsectively. If the value exceeds these limits,
// the behavior is undefined.
//
// @return
// The fractional part of the specified number. The return value will have
// the same fixed-point format as the input number.
//
fix32_t fix32_frac(fix32_t a, sint_t exp);


//
// Returns the integer part of a fixed-point number.
//
// @param a
// Fixed-point number whose integer part is to be determined. The number
// can be in any fixed-point format, from Q1 to Q31.
//
// @param exp
// Value specifying a fixed-point format of the first argument. This value
// must be in the range from 1 to 31, which corresponds to the fixed-point
// formats from Q1 to Q31 repsectively. If the value exceeds these limits,
// the behavior is undefined.
//
// @return
// The integer part of the specified number. The return value will have
// the same fixed-point format as the input number.
//
fix32_t fix32_trun(fix32_t a, sint_t exp);


//
// Clamps a fixed-point number within the specified range.
//
// @param a
// Fixed-point number to be clamped. All input arguments must be in the
// same fixed-point format, which can be arbitrary.
//
// @param min
// Fixed-point number representing the lower bound of the clipping range.
// All input arguments must be in the same fixed-point format, which can
// be arbitrary.
//
// @param max
// Fixed-point number representing the upper bound of the clipping range.
// All input arguments must be in the same fixed-point format, which can
// be arbitrary.
//
// @return
// The first argument clamped within the range specified by the second
// and third argument. If the upper bound is less than the lower bound,
// the behaviour is undefined.
//
fix32_t fix32_clip(fix32_t a, fix32_t min, fix32_t max);


#endif
