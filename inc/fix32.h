#ifndef FIX32_H
#define FIX32_H


//
// Returns the product of two fixed-point numbers. The first two arguments
// specify the multiplicands. The last argument specifies the format of the
// multiplicands, and must be in the range from 0 to 31, which corresponds
// to the fixed-point formats from Q0 to Q31. The result will have the same
// format as the input numbers. If the result cannot be represented in this
// format, the behavior is undefined.
//
fix32_t fix32_mul(fix32_t a, fix32_t b, sint_t exp);


//
// Returns the reciprocal of a fixed-point number specified in the first
// argument. The second argument specifies its format and must be in the
// range from 1 to 30, which corresponds to the fixed-point formats from
// Q1 to Q30. The result will have the same format as the input numbers.
// If it cannot be represented in this format, the behavior is undefined.
//
fix32_t fix32_inv(fix32_t a, sint_t exp);


//
// Returns the quotient of two fixed-point numbers. The first and second
// argument specify the dividend and non-zero divisor. The last argument
// specifies their format, and must be in the range from 1 to 31, which
// corresponds to the fixed-point formats from Q1 to Q31. The result will
// have the same format as the input numbers. If it cannot be represented
// in this format, the behavior is undefined.
//
fix32_t fix32_div(fix32_t a, fix32_t b, sint_t exp);


//
// Returns the inverse square root of a positive fixed-point number, which
// is specified in the first argument. The second argument specifies the
// format of the number and must be from 1 to 30, which corresponds to the
// fixed-point formats from Q1 to Q30. The result will have the same format
// as the input number. If the result cannot be represented in this format,
// the behavior is undefined.
//
fix32_t fix32_isqrt(fix32_t a, sint_t exp);


//
// Returns the square root of a non-negative fixed-point number specified
// in the first argument. The second argument specifies the format of the
// number and must be in the range from 1 to 31, which corresponds to the
// fixed-point formats from Q1 to Q31. The result will have the same format
// as the input number. If the result cannot be represent in this format,
// the behavior is undefined.
//
fix32_t fix32_sqrt(fix32_t a, sint_t exp);


//
// Returns the sine of a fixed-point angle. The first argument specifies
// an angle exressed in revolutions. The second argument defines the format
// of the angle and should be in the range from 1 to 31, which corresponds
// to the fixed-point formats from Q1 to Q31. The result will have the same
// fixed-point format as the input angle.
//
fix32_t fix32_sin(fix32_t a, sint_t exp);


//
// Returns the cosine of a fixed-point angle. The first argument specifies
// an angle exressed in revolutions. The second argument defines the format
// of the angle and should be in the range from 1 to 31, which corresponds
// to the fixed-point formats from Q1 to Q31. The result will have the same
// fixed-point format as the input angle.
//
fix32_t fix32_cos(fix32_t a, sint_t exp);


//
// Returns the absolute value of a fixed-point number specified in the first
// argument. The number can have any fixed-point format. The result will have
// the same fixed-point format as the specified number. If the result cannot
// be represent in this format, the behavior is undefined.
//
fix32_t fix32_abs(fix32_t a);


//
// Returns a value with the magnitude of the first argument and the sign
// of the second argument. The function treats zero as a positive number.
// The numbers can be in any fixed-point format. The result will have the
// same format as the first argument. If the result cannot be represented
// in this fixed-point format, the behavior is undefined.
//
fix32_t fix32_copy(fix32_t mag, fix32_t sig);


//
// Returns a value with the magnitude of the first argument and the sign
// of the product of both arguments. Zero is treated as a positive number.
// The numbers can be in any fixed-point format. The result will have the
// same format as the first argument. If the result cannot be represented
// in this fixed-point format, the behavior is undefined.
//
fix32_t fix32_flip(fix32_t mag, fix32_t sig);


//
// Returns the fractional part of a fixed-point number which is specified
// in the first argument. The second argument determines the format of the
// number and must be in the range from 1 to 31, which corresponds to the
// fixed-point formats from Q1 to Q31 repsectively. The result will have
// the same format as the input number.
//
fix32_t fix32_frac(fix32_t a, sint_t exp);


//
// Returns the integer part of a fixed-point number specified in the first
// argument. The second argument determines the format of the number and must
// be in the range from 1 to 31, which corresponds to the fixed-point formats
// from Q1 to Q31 repsectively. The result will have the same format as the
// input number.
//
fix32_t fix32_trun(fix32_t a, sint_t exp);


//
// Clamps a fixed-point number within a particular range. The first argument
// specifies a number to be clamped. The second and third argument define the
// lower and upper range bound respectively. All arguments must be specified
// in the same fixed-point format, which can be arbitrary. The format of the
// result will be the same as that of the input numbers.
//
fix32_t fix32_clip(fix32_t a, fix32_t min, fix32_t max);


#endif
