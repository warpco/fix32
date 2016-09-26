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


int main(void)
{
    test_mul();

    okay();
}
