#include <iostream>
#include <string>
#include "Big_Int.h"
using namespace std;

int main() {
    string a_s, b_s;
    unsigned long long b;
    cin >> a_s >> b_s >> b;

    cout << long_max(a_s, b_s) << '\n'; // max num from a and b
    cout << long_min(a_s, b_s) << '\n'; // min num from a and b
    cout << long_sum(a_s, b_s) << '\n'; //sum of a and b
    cout << long_diff(a_s, b_s) << '\n'; // difference from a to b
    cout << long_multi(a_s, b_s) << '\n'; // multiplication  of a and b
    cout << long_pow(a_s, b) << '\n'; // power a to b
    cout << long_div(a_s, b_s) << '\n'; // division a to b
}