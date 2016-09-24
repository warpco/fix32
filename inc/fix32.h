#ifndef FIX32_H
#define FIX32_H


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
fix32_t fix32_inv(fix32_t a, fix32_t exp);


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
fix32_t fix32_div(fix32_t a, fix32_t b, fix32_t exp);


#endif
