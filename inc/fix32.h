#ifndef FIX32_H
#define FIX32_H


//
// Defines the 32-bit signed integer type representing a fixed-point number.
// You have to change this definition to match the current CPU architecture.
//
typedef signed long fix32_t;


//
// Defines the signed integer type with a size equal to the word length.
// You have to change this definition to match the current CPU architecture.
//
typedef signed int sint_t;


//
// Returns the product of two fixed-point numbers. The first two arguments
// specify numbers representing the multiplicands. The format of the input
// numbers may vary from Q0 to Q31. The actual format is specified in the
// third argument. You must not specify an unsupported format, otherwise
// the behavior is undefined. The result will have the same format as the
// input values. If the result cannot be represented in this format, the
// behavior is undefined.
//
fix32_t fix32_mul(fix32_t a, fix32_t b, sint_t exp);


//
// Returns the reciprocal of a fixed-point number. The number is specified
// in the first argument. You must not specify zero, otherwise the behavior
// is undefined. The second argument specifies the number format, which may
// vary from Q1 to Q30. If you specify a format that is not supported, the
// behavior is undefined. The result will have the same format as the input
// value. If the result cannot be represented in this format, or you specify
// an unsupported format, the behavior is undefined.
//
fix32_t fix32_inv(fix32_t a, sint_t exp);


//
// Returns the quotient of two fixed-point numbers. The first two arguments
// specify numbers representing the dividend and divisor. The divisor must
// be non-zero, otherwise the behavior is undefined. The format of the input
// values may vary from Q1 to Q31, the actual format is specified in the last
// argument. If you specify any format that is not supported, the behavior
// is undefined. The format of the result will be the same as that of the
// input values. If the result cannot be represented in this fixed-point
// format, the behavior is undefined.
//
fix32_t fix32_div(fix32_t a, fix32_t b, sint_t exp);


//
// Returns the inverse square root of a fixed-point number. The number must
// be positive, otherwise the behavior is undefined. The number is specified
// in the first argument. The format of the number may vary from Q1 to Q30,
// the actual format is specified in the second argument. If you specify any
// format that is not supported, the behavior is undefined. The result will
// have the same fixed-point format as the input value. If the result cannot
// be represented in this format, the behavior is undefined.
//
fix32_t fix32_isqrt(fix32_t a, sint_t exp);


//
// Returns the square root of a fixed-point number. This first argument
// specifies a number whose square root is to be determined. The number
// must be non-negative, otherwise the behavior is undefined. The second
// argument specifies the number format, which may vary from Q1 to Q31.
// If you specify any other format, the behavior is undefined. The result
// will have the same format as the input value.
//
fix32_t fix32_sqrt(fix32_t a, sint_t exp);


//
// Returns the sine of an angle expressed in revolutions. The first argument
// specifies a fixed-point number representing the angle. The format of this
// number may vary from Q1 to Q31. The actual format is passed as the second
// argument. If you specify an unsupported format, the behavior is undefined.
// The result will have the same format as the input number.
//
fix32_t fix32_sin(fix32_t a, sint_t exp);


//
// Returns the cosine of an angle expressed in revolutions. A fixed-point
// number, representing the angle, is passed as the first function argument.
// The second argument specifies the fixed-point format of the number, which
// may vary from Q1 to Q31. You must not specify any other format, otherwise
// the behavior is undefined. The resulting format will be the same as that
// of the input value.
//
fix32_t fix32_cos(fix32_t a, sint_t exp);


//
// Returns the absolute value of a fixed-point number. The first argument
// specifies a number whose absoute value is to be found. The number can
// be in any fixed-point format. The format of the result will be the same
// as that of the input value. If the result cannot be represented in this
// fixed-point format, the behavior is undefined.
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
// Returns the fractional part of a fixed-point number. The first argument
// specifies a number whose integer part is to be determined. The format
// of the number may vary from Q1 to Q31. The actual format is specified
// in the second argument. You must not specify an unsupported format,
// otherwise the behavior is undefined.
//
fix32_t fix32_frac(fix32_t a, sint_t exp);


//
// Returns the integer part of a fixed-point number. The first argument
// specifies a number whose integer part is to be determined. The format
// of the number may vary from Q1 to Q31. The actual format is specified
// in the second argument. You must not specify an unsupported format,
// otherwise the behavior is undefined.
//
fix32_t fix32_trun(fix32_t a, sint_t exp);


//
// Clamps a fixed-point number within a particular range. The first argument
// specifies a number to be clamped. The second argument specifies the lower
// range bound. The third argument specifies the upper range bound. All the
// arguments must be in the same fixed-point format, which can be arbitrary.
// The format of the result will be the same as that of the input values.
//
fix32_t fix32_clip(fix32_t a, fix32_t min, fix32_t max);


#endif
