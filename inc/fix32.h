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


#endif
