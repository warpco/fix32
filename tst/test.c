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


int main(void)
{
    test_mul();
    test_inv();

    okay();
}
