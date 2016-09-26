#include <fix32.h>


//
// Called when a test fails. The argument will contain the line number in the
// current file where the error was detected. You can set a breakpoint inside
// this function to catch the error and determine which test failed.
//
void fail(int line)
{
    while(1);
}


//
// Called when all the tests are passed. You can set a breakpoint inside this
// function to make sure that all the tests completed successfully.
//
void okay(void)
{
    while(1);
}


void test_mul(void)
{
    if (fix32_mul(0x7fffffff, 0x7fffffff, 31) != 0x7ffffffe) fail(__LINE__);
    if (fix32_mul(0x7fffffff, 0x80000000, 31) != 0x80000001) fail(__LINE__);
    if (fix32_mul(0x80000000, 0x80000001, 31) != 0x7fffffff) fail(__LINE__);
    if (fix32_mul(0x3152c6d4, 0x3e50babc, 29) != 0x600ccfff) fail(__LINE__);
    if (fix32_mul(0xff6bf986, 0x2558ad00, 23) != 0xd4cf9437) fail(__LINE__);
    if (fix32_mul(0x002ddd9c, 0x008ebea0, 19) != 0x03326276) fail(__LINE__);
    if (fix32_mul(0x16274c20, 0xffea3ea3, 18) != 0x8782c52d) fail(__LINE__);
    if (fix32_mul(0xd13c3ff2, 0x000055f0, 17) != 0xf82694dc) fail(__LINE__);
    if (fix32_mul(0x18923452, 0x0002e787, 16) != 0x475d4af4) fail(__LINE__);
    if (fix32_mul(0xeebc1a9f, 0xfffc50a6, 15) != 0x7f3e579e) fail(__LINE__);
}


void test_inv(void)
{
    if (fix32_inv(0xd6b403f4, 30) != 0x9cd0cad2) fail(__LINE__);
    if (fix32_inv(0x7fe95a16, 29) != 0x08016a9f) fail(__LINE__);
    if (fix32_inv(0x0303e5d5, 28) != 0x54e705e1) fail(__LINE__);
    if (fix32_inv(0x0ea767bb, 27) != 0x045e0fe6) fail(__LINE__);
    if (fix32_inv(0xe647665c, 26) != 0xff60c0d7) fail(__LINE__);
    if (fix32_inv(0x7ff02269, 25) != 0x000800fe) fail(__LINE__);
    if (fix32_inv(0x66f2d738, 24) != 0x00027c97) fail(__LINE__);
    if (fix32_inv(0x1f21624a, 23) != 0x00020e4d) fail(__LINE__);
    if (fix32_inv(0x1b2c5236, 21) != 0x000025af) fail(__LINE__);
    if (fix32_inv(0xef89226d, 19) != 0xfffffc1d) fail(__LINE__);
    if (fix32_inv(0x5ed2759f, 18) != 0x0000002b) fail(__LINE__);
    if (fix32_inv(0x7f2d5690, 17) != 0x00000008) fail(__LINE__);
    if (fix32_inv(0xaae53cec, 15) != 0xffffffff) fail(__LINE__);
    if (fix32_inv(0x0ba27e1e, 14) != 0x00000001) fail(__LINE__);
    if (fix32_inv(0xf5323937, 12) != 0x00000000) fail(__LINE__);
}


void test_div(void)
{
    if (fix32_div(0xb9785a58, 0x6d0b24e7, 31) != 0xad3580b8) fail(__LINE__);
    if (fix32_div(0x10b4ae81, 0x7769fb3f, 30) != 0x08f41712) fail(__LINE__);
    if (fix32_div(0xc3fb2ce8, 0x544ed815, 29) != 0xe9381db2) fail(__LINE__);
    if (fix32_div(0x3bdd19d3, 0x252a5915, 28) != 0x19c592e6) fail(__LINE__);
    if (fix32_div(0x353fbb10, 0xe9680fe4, 27) != 0xed2538d3) fail(__LINE__);
    if (fix32_div(0x16e55d16, 0x03f3bd04, 26) != 0x172c665a) fail(__LINE__);
    if (fix32_div(0x79d32ff9, 0xf1965e24, 24) != 0xf78c1ed3) fail(__LINE__);
    if (fix32_div(0x28355003, 0xbfcd1b3d, 22) != 0xffd7ea90) fail(__LINE__);
    if (fix32_div(0x89b87bf3, 0x217295f6, 20) != 0xffc76b7c) fail(__LINE__);
    if (fix32_div(0x8ad655cc, 0x719432ab, 17) != 0xfffdefd8) fail(__LINE__);
    if (fix32_div(0x77a73994, 0x403a6d44, 16) != 0x0001dcea) fail(__LINE__);
    if (fix32_div(0x0e64eae7, 0x0737f5a1, 14) != 0x00007f9e) fail(__LINE__);
    if (fix32_div(0x284da6d4, 0x6094edba, 12) != 0x000006ad) fail(__LINE__);
    if (fix32_div(0x2bd2a7b7, 0x03fe62c2, 11) != 0x000057c9) fail(__LINE__);
    if (fix32_div(0xe5558521, 0x80120930,  9) != 0x0000006b) fail(__LINE__);
    if (fix32_div(0x43b0720e, 0x096f40c0,  7) != 0x00000396) fail(__LINE__);
    if (fix32_div(0x35ff4f71, 0xc59e31fd,  5) != 0xffffffe2) fail(__LINE__);
    if (fix32_div(0x1c17b1b4, 0xbfe7d55b,  4) != 0xfffffff9) fail(__LINE__);
    if (fix32_div(0x8d2ec803, 0x9e74eaed,  1) != 0x00000002) fail(__LINE__);
    if (fix32_div(0x719ba49f, 0xb6a32bff,  1) != 0xfffffffd) fail(__LINE__);
}


void test_isqrt(void)
{
    if (fix32_isqrt(0x1816f4cb, 30) != 0x68511dd0) fail(__LINE__);
    if (fix32_isqrt(0x02613402, 29) != 0x75584552) fail(__LINE__);
    if (fix32_isqrt(0x07ba2f31, 29) != 0x411e9c98) fail(__LINE__);
    if (fix32_isqrt(0x186d105c, 28) != 0x0cf31374) fail(__LINE__);
    if (fix32_isqrt(0x1e6d816e, 25) != 0x008343ec) fail(__LINE__);
    if (fix32_isqrt(0x793c1513, 24) != 0x0017400c) fail(__LINE__);
    if (fix32_isqrt(0x5f4ccf78, 23) != 0x0009457f) fail(__LINE__);
    if (fix32_isqrt(0x4536292e, 21) != 0x00015c24) fail(__LINE__);
    if (fix32_isqrt(0x007e41df, 18) != 0x0000b644) fail(__LINE__);
    if (fix32_isqrt(0x57f906dc, 16) != 0x000001b5) fail(__LINE__);
    if (fix32_isqrt(0x4b31f08c, 14) != 0x0000003b) fail(__LINE__);
    if (fix32_isqrt(0x0629fa94, 13) != 0x00000049) fail(__LINE__);
    if (fix32_isqrt(0x47eaa74d, 11) != 0x00000003) fail(__LINE__);
    if (fix32_isqrt(0x7bd10b9c, 10) != 0x00000001) fail(__LINE__);
    if (fix32_isqrt(0x01e7af4a,  9) != 0x00000002) fail(__LINE__);
}


void test_sqrt(void)
{
    if (fix32_sqrt(0x79d41007, 31) != 0x7ce045b8) fail(__LINE__);
    if (fix32_sqrt(0x7d077aa6, 31) != 0x7e8181d5) fail(__LINE__);
    if (fix32_sqrt(0x5ec3ab12, 30) != 0x4de0a8ea) fail(__LINE__);
    if (fix32_sqrt(0x40303d8b, 30) != 0x40181a3b) fail(__LINE__);
    if (fix32_sqrt(0x6244dc91, 29) != 0x3813a948) fail(__LINE__);
    if (fix32_sqrt(0x5721603a, 29) != 0x34cd9ad4) fail(__LINE__);
    if (fix32_sqrt(0x100f7a08, 26) != 0x0803dd93) fail(__LINE__);
    if (fix32_sqrt(0x7c5c7322, 23) != 0x07e2adde) fail(__LINE__);
    if (fix32_sqrt(0x7fffffff, 19) != 0x02000000) fail(__LINE__);
    if (fix32_sqrt(0x31b158e8, 15) != 0x004fc0fb) fail(__LINE__);
    if (fix32_sqrt(0x1ff692ad, 13) != 0x001ffb49) fail(__LINE__);
    if (fix32_sqrt(0x6feb955e, 12) != 0x002a5123) fail(__LINE__);
    if (fix32_sqrt(0x398c830e, 10) != 0x000f2c15) fail(__LINE__);
    if (fix32_sqrt(0x4067e450,  9) != 0x000b597a) fail(__LINE__);
    if (fix32_sqrt(0x0402e49c,  6) != 0x0001005d) fail(__LINE__);
    if (fix32_sqrt(0x7fffffff,  5) != 0x00040000) fail(__LINE__);
    if (fix32_sqrt(0x7fd42c42,  2) != 0x000169cc) fail(__LINE__);
    if (fix32_sqrt(0x00000000,  1) != 0x00000000) fail(__LINE__);
}


void test_sin(void)
{
    if (fix32_sin(0xa0000000, 31) != 0x7fffffff) fail(__LINE__);
    if (fix32_sin(0xc0000000, 31) != 0x00000000) fail(__LINE__);
    if (fix32_sin(0xe0000000, 31) != 0x80000001) fail(__LINE__);
    if (fix32_sin(0x00000000, 31) != 0x00000000) fail(__LINE__);
    if (fix32_sin(0x20000000, 31) != 0x7fffffff) fail(__LINE__);
    if (fix32_sin(0x40000000, 31) != 0x00000000) fail(__LINE__);
    if (fix32_sin(0x60000000, 31) != 0x80000001) fail(__LINE__);
    if (fix32_sin(0x77a7e745, 29) != 0xe012b18f) fail(__LINE__);
    if (fix32_sin(0x018dbaa1, 23) != 0x004fe109) fail(__LINE__);
    if (fix32_sin(0x36672e2d, 21) != 0x001f9625) fail(__LINE__);
    if (fix32_sin(0x640609b3, 18) != 0xffffc318) fail(__LINE__);
    if (fix32_sin(0x3bad69a5, 15) != 0xffff8e14) fail(__LINE__);
    if (fix32_sin(0x9074574c, 12) != 0x0000045d) fail(__LINE__);
    if (fix32_sin(0x5ee781d8,  8) != 0xffffff2b) fail(__LINE__);
    if (fix32_sin(0x890ebc72,  3) != 0x00000008) fail(__LINE__);
}


void test_cos(void)
{
    if (fix32_cos(0xa0000000, 31) != 0x00000000) fail(__LINE__);
    if (fix32_cos(0xc0000000, 31) != 0x80000001) fail(__LINE__);
    if (fix32_cos(0xe0000000, 31) != 0x00000000) fail(__LINE__);
    if (fix32_cos(0x00000000, 31) != 0x7fffffff) fail(__LINE__);
    if (fix32_cos(0x20000000, 31) != 0x00000000) fail(__LINE__);
    if (fix32_cos(0x40000000, 31) != 0x80000001) fail(__LINE__);
    if (fix32_cos(0x60000000, 31) != 0x00000000) fail(__LINE__);
    if (fix32_cos(0x7e8df2cc, 29) != 0x1eb83f31) fail(__LINE__);
    if (fix32_cos(0x30b049b0, 25) != 0xfee20bca) fail(__LINE__);
    if (fix32_cos(0xd5325f24, 21) != 0xffe36848) fail(__LINE__);
    if (fix32_cos(0x981b12fe, 18) != 0x00007710) fail(__LINE__);
    if (fix32_cos(0x7013aff1, 15) != 0xffffa5c0) fail(__LINE__);
    if (fix32_cos(0xf8af51e7, 11) != 0x0000009d) fail(__LINE__);
    if (fix32_cos(0xdf88e6d9,  4) != 0xfffffff1) fail(__LINE__);
    if (fix32_cos(0x006802ba,  1) != 0x00000002) fail(__LINE__);
}


void test_abs(void)
{
    if (fix32_abs(0x00000000) != 0x00000000) fail(__LINE__);
    if (fix32_abs(0x00000001) != 0x00000001) fail(__LINE__);
    if (fix32_abs(0xffffffff) != 0x00000001) fail(__LINE__);
    if (fix32_abs(0x7fffffff) != 0x7fffffff) fail(__LINE__);
    if (fix32_abs(0x80000001) != 0x7fffffff) fail(__LINE__);
    if (fix32_abs(0x4a3c59a3) != 0x4a3c59a3) fail(__LINE__);
    if (fix32_abs(0xfcb799be) != 0x03486642) fail(__LINE__);
    if (fix32_abs(0x0511e042) != 0x0511e042) fail(__LINE__);
    if (fix32_abs(0xb2ac44f9) != 0x4d53bb07) fail(__LINE__);
    if (fix32_abs(0xcb276864) != 0x34d8979c) fail(__LINE__);
}


void test_copy(void)
{
    if (fix32_copy(0x00000000, 0x00000000) != 0x00000000) fail(__LINE__);
    if (fix32_copy(0x00000000, 0x7fffffff) != 0x00000000) fail(__LINE__);
    if (fix32_copy(0x00000000, 0x80000001) != 0x00000000) fail(__LINE__);
    if (fix32_copy(0x7fffffff, 0x00000000) != 0x7fffffff) fail(__LINE__);
    if (fix32_copy(0x7fffffff, 0x7fffffff) != 0x7fffffff) fail(__LINE__);
    if (fix32_copy(0x7fffffff, 0x80000001) != 0x80000001) fail(__LINE__);
    if (fix32_copy(0x80000001, 0x00000000) != 0x7fffffff) fail(__LINE__);
    if (fix32_copy(0x80000001, 0x7fffffff) != 0x7fffffff) fail(__LINE__);
    if (fix32_copy(0x80000001, 0x80000001) != 0x80000001) fail(__LINE__);
    if (fix32_copy(0x0b1f772a, 0xecb7affb) != 0xf4e088d6) fail(__LINE__);
}


void test_flip(void)
{
    if (fix32_flip(0x00000000, 0x00000000) != 0x00000000) fail(__LINE__);
    if (fix32_flip(0x00000000, 0x7fffffff) != 0x00000000) fail(__LINE__);
    if (fix32_flip(0x00000000, 0x80000001) != 0x00000000) fail(__LINE__);
    if (fix32_flip(0x7fffffff, 0x00000000) != 0x7fffffff) fail(__LINE__);
    if (fix32_flip(0x7fffffff, 0x7fffffff) != 0x7fffffff) fail(__LINE__);
    if (fix32_flip(0x7fffffff, 0x80000001) != 0x80000001) fail(__LINE__);
    if (fix32_flip(0x80000001, 0x00000000) != 0x80000001) fail(__LINE__);
    if (fix32_flip(0x80000001, 0x7fffffff) != 0x80000001) fail(__LINE__);
    if (fix32_flip(0x80000001, 0x80000001) != 0x7fffffff) fail(__LINE__);
    if (fix32_flip(0x1b0a627f, 0x9e9128d9) != 0xe4f59d81) fail(__LINE__);
}


void test_frac(void)
{
    if (fix32_frac(0x00000000, 31) != 0x00000000) fail(__LINE__);
    if (fix32_frac(0x7fffffff, 31) != 0x7fffffff) fail(__LINE__);
    if (fix32_frac(0x80000001, 31) != 0x80000001) fail(__LINE__);
    if (fix32_frac(0xa35a2e07, 30) != 0xe35a2e07) fail(__LINE__);
    if (fix32_frac(0x7ddc521b, 26) != 0x01dc521b) fail(__LINE__);
    if (fix32_frac(0x60c7ca9c, 17) != 0x0001ca9c) fail(__LINE__);
    if (fix32_frac(0x9bcbcd20, 13) != 0xffffed20) fail(__LINE__);
    if (fix32_frac(0x737bdc6f, 10) != 0x0000006f) fail(__LINE__);
    if (fix32_frac(0xae944b67,  8) != 0xffffff67) fail(__LINE__);
    if (fix32_frac(0xfc1e56a9,  1) != 0xffffffff) fail(__LINE__);
}


void test_trun(void)
{
    if (fix32_trun(0x00000000, 31) != 0x00000000) fail(__LINE__);
    if (fix32_trun(0x7fffffff, 31) != 0x00000000) fail(__LINE__);
    if (fix32_trun(0x80000001, 31) != 0x00000000) fail(__LINE__);
    if (fix32_trun(0x4fa50186, 30) != 0x40000000) fail(__LINE__);
    if (fix32_trun(0x98583cb0, 27) != 0xa0000000) fail(__LINE__);
    if (fix32_trun(0x3914aa1f, 21) != 0x39000000) fail(__LINE__);
    if (fix32_trun(0x0cfb4e31, 16) != 0x0cfb0000) fail(__LINE__);
    if (fix32_trun(0xf0e34914, 12) != 0xf0e35000) fail(__LINE__);
    if (fix32_trun(0x42c06fcb,  7) != 0x42c06f80) fail(__LINE__);
    if (fix32_trun(0xabc5fc0c,  3) != 0xabc5fc10) fail(__LINE__);
}


int main(void)
{
    test_mul();
    test_inv();
    test_div();
    test_isqrt();
    test_sqrt();
    test_sin();
    test_cos();
    test_abs();
    test_copy();
    test_flip();
    test_frac();
    test_trun();

    okay();
}
