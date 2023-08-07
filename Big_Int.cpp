#include <iostream>
#include "Big_Int.h"

using namespace std;

////Testing///////////////////////////////////////////
#include "Testing_Big_Int.h"

/* copy test function to main field for testing
TEST_long_max(); // max(a, b)
TEST_long_min(); // min(a, b)
TEST_long_sum(); // a + b
TEST_long_dif(); // a - b
TEST_long_multi(); // a * b
TEST_long_pow(); // pow(a, b)
TEST_long_div(); // a / b
TEST_long_remainder_of_div(); // a % b
*/

/* copy tset function to main field for testing class
* TEST_Big_Int_ios(); // istream >> big_int; ostream << big_int;
* TEST_Big_Int_EGL(); // (==) (!=) (>) (>=) (<) (<=)
* TEST_Big_Int_Addition() // (+) (+=) (++)
* TEST_Big_Int_Subtraction() // (-) (-=) (--)
* TEST_Big_Int_Multiplication() // (*) (*=)
* TEST_Big_Int_Division() // (/) (/=)
* TEST_Big_Int_Power() // pow()
* TEST_Big_Int_Modulo() // (%) (%=)
*/

/////////////////////////////////////////////////////

int main() {
    TEST_Big_Int_Modulo();
    return 0;
}