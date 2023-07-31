#include <iostream>
#include <string>
#include "Big_Int.h"
using namespace std;

int unit_test_for_long_max() {
    {
        if (long_max("1", "3") != "3") {
            cout << "3 > 1" << endl;
            return -1;
        }
    }
    {
        if (long_max("11", "3") != "11") {
            cout << "11 > 3" << endl;
            return -2;
        }
    }
    {
        if (long_max("125", "9") != "125") {
            cout << "125 > 9" << endl;
            return -3;
        }
    }
    {
        if (long_max("-125", "9") != "9") {
            cout << "9 > -125" << endl;
            return -4;
        }
    }
    {
        if (long_max("-125", "-15") != "-15") {
            cout << "-15 > -125" << endl;
            return -5;
        }
    }
    {
        //Empty Big_int control
        //long_max("", "-15");
    }
    {
        if (long_max("0", "-15") != "0") {
            cout << "0 > -15" << endl;
            return -6;
        }
    }

    cout << "OK";
    return 0;
}

int unit_test_for_long_min() {
    {
        if (long_min("1", "3") != "1") {
            cout << "3 > 1" << endl;
            return -1;
        }
    }
    {
        if (long_min("11", "3") != "3") {
            cout << "11 > 3" << endl;
            return -2;
        }
    }
    {
        if (long_min("125", "9") != "9") {
            cout << "125 > 9" << endl;
            return -3;
        }
    }
    {
        if (long_min("-125", "9") != "-125") {
            cout << "9 > -125" << endl;
            return -4;
        }
    }
    {
        if (long_min("-125", "-9") != "-125") {
            cout << "-9 > -125" << endl;
            return -5;
        }
    }
    {
        //Empty Big_int control
        //long_min("", "-15");
    }
    {
        if (long_min("125", "-9") != "-9") {
            cout << "125 > -9" << endl;
            return -6;
        }
    }

    cout << "OK";
    return 0;
}

int unit_test_for_long_sum() {
    {
        if (long_sum("1", "3") != "4") {
            cout << "1 + 3 != " << long_sum("1", "3") << endl;
            return -1;
        }
    }
    {
        if (long_sum("11", "3") != "14") {
            cout << "11 + 3 != " << long_sum("11", "3") << endl;
            return -2;
        }
    }
    {
        if (long_sum("125", "9") != "134") {
            cout << "125 + 9 != " << long_sum("125", "9") << endl;
            return -3;
        }
    }
    {
        if (long_sum("-125", "9") != "-116") {
            cout << "-125 + 9 != " << long_sum("-125", "9") << endl;
            return -4;
        }
    }
    {
        if (long_sum("125", "-9") != "116") {
            cout << "125 + (-9) != " << long_sum("125", "-9");
            return -5;
        }
    }
    {
        //Empty Big_int control
        //long_sum("", "-15");
    }
    {
        if (long_sum("-125", "-9") != "-134") {
            cout << "-125 + (-9) != " << long_sum("-125", "-9");
            return -6;
        }
    }
    {
        if (long_sum("0", "0") != "0") {
            cout << "0 + 0 != " << long_sum("0", "0");
            return -7;
        }
    }


    cout << "OK";
    return 0;
}

int unit_test_for_long_dif_positive() {
    {
        if (long_dif_positive("3", "1") != "2") {
            cout << "3 - 1 != " << long_dif_positive("3", "1") << endl;
            return -1;
        }
    }
    {
        if (long_dif_positive("11", "3") != "8") {
            cout << "11 + 3 != " << long_dif_positive("11", "3") << endl;
            return -2;
        }
    }
    {
        if (long_dif_positive("125", "9") != "116") {
            cout << "125 - 9 != " << long_dif_positive("125", "9") << endl;
            return -3;
        }
    }
    {
        if (long_dif_positive("1000", "1") != "999") {
            cout << "1000 - 1 != " << long_dif_positive("1000", "1") << endl;
            return -4;
        }
    }
    {
        if (long_dif_positive("100", "125") != "-25") {
            cout << "100 - 125 != " << long_dif_positive("125", "-9");
            return -5;
        }
    }
    {
        //Empty Big_int control
        long_dif_positive("", "-15");
    }
    {
        if (long_dif_positive("19", "32") != "-13") {
            cout << "19 - 32 != " << long_dif_positive("19", "32");
            return -6;
        }
    }

    cout << "OK";
    return 0;
}

int unit_test_for_long_dif() {
    {
        if (long_dif("-125", "-15") != "-110") {
            cout << "-125 - (-15) != " << long_dif("-125", "-15") << endl;
            return -1;
        }
    }
    {
        if (long_dif("-125", "15") != "-140") {
            cout << "-125 - 15 != " << long_dif("-125", "15") << endl;
            return -2;
        }
    }
    {
        if (long_dif("125", "-15") != "140") {
            cout << "125 - 9 != " << long_dif("125", "-15") << endl;
            return -3;
        }
    }
    {
        if (long_dif("125", "15") != "110") {
            cout << "125 - 15 != " << long_dif("125", "15") << endl;
            return -4;
        }
    }
    {
        //Empty Big_int control
        //long_dif("", "-15");
    }
    

    cout << "OK";
    return 0;
}

int unit_test_for_long_multi() {
    {
        if (long_multi("125", "5") != "625") {
            cout << "125 * 5 != " << long_multi("125", "5") << endl;
            return -1;
        }
    }
    {
        if (long_multi("125", "10") != "1250") {
            cout << "125 * 10 != " << long_multi("125", "10") << endl;
            return -2;
        }
    }
    {
        if (long_multi("125", "-5") != "-625") {
            cout << "125 * (-5) != " << long_multi("125", "-5") << endl;
            return -3;
        }
    }
    {
        if (long_multi("-125", "-5") != "625") {
            cout << "-125 * (-5) != " << long_multi("-125", "-15") << endl;
            return -4;
        }
    }
    {
        //Empty Big_int control
        //long_multi("", "-15");
    }

    cout << "OK";
    return 0;
}

int unit_test_for_long_pow() {
    {
        if (long_pow("2", 3) != "8") {
            cout << "2 ^ 3 != " << long_pow("2", 3) << endl;
            return -1;
        }
    }
    {
        //Empty Big_int control
        //long_pow("", 1);
    }

    cout << "OK";
    return 0;
}

int unit_test_for_long_div() {
    {
        if (long_div("10", "2") != "5") {
            cout << "10 / 2 != " << long_div("10", "2") << endl;
            return -1;
        }
    }
    {
        if (long_div("22", "4") != "5") {
            cout << "22 / 4 != " << long_div("22", "4") << endl;
            return -2;
        }
    }
     {
        if (long_div("18446744073709551618", "2") != "9223372036854775809") {
            cout << "18446744073709551618 / 2 != " << long_div("18446744073709551618", "2") << endl;
            return -3;
        }
    }
    {
        if (long_div("0", "2") != "0") {
            cout << "0 / 2 != " << long_div("0", "2") << endl;
            return -4;
        }
    }
    {
        if (long_div("18446744073709551618", "0") != "") {
            cout << "18446744073709551618 / 0 != " << long_div("18446744073709551618", "0") << endl;
            return -5;
        }
    }
    {
        if (long_div("5", "1") != "5") {
            cout << "5 / 1 != " << long_div("5", "1") << endl;
            return -6;
        }
    }
    {
        //Empty Big_int control
        long_div("", "1");
    }

    cout << "OK";
    return 0;
}

int unit_test_for_long_remainder_of_div() {
    {
        if (long_remainder_of_div("11", "2") != "1") {
            cout << "11 % 2 != " << long_remainder_of_div("11", "2") << endl;
            return -1;
        }
    }
    {
        if (long_remainder_of_div("22", "4") != "2") {
            cout << "22 % 4 != " << long_remainder_of_div("22", "4") << endl;
            return -2;
        }
    }
    {
        if (long_remainder_of_div("2", "1") != "0") {
            cout << "2 % 1 != " << long_remainder_of_div("2", "1") << endl;
            return -3;
        }
    }
    {
        //Empty Big_int control
        long_remainder_of_div("", "1");
    }

    cout << "OK";
    return 0;
}

int main() {
    return 0; // Possible to put some utit tests here
}