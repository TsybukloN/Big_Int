#pragma once
#include <string>
#include <algorithm>
using namespace std;

void equle_to_legnth(string& a_s, string& b_s) {
    if (a_s.length() > b_s.length()) {
        string doner(a_s.length() - b_s.length(), '0');
        b_s = doner + b_s;
    }
    else if (a_s.length() < b_s.length()) {
        string doner(b_s.length() - a_s.length(), '0');
        a_s = doner + a_s;
    }
}

string long_max(string a_s, string b_s);
string long_min(string a_s, string b_s);
string long_sum(string a_s, string b_s);
string long_dif_positive(string a_s, string b_s);
string long_dif(string a_s, string b_s);
string long_multi(string a, string b);
string long_pow(string x, unsigned long long p);
string long_remainder_of_div(string a_s, string b_s);

//////////////////////////////////////////////////

string long_max(const string a,const string b) {
    if (a.empty() || b.empty()) {
        cout << "One of the element in long_max() is empty!" << endl;
        return "";
    }

    string a_s = a, b_s = b;

    if (a_s[0] == '-' && b_s[0] == '-') {
        a_s.erase(0,1);
        b_s.erase(0,1);
        return "-" + long_min(a_s, b_s);
    }
    
    equle_to_legnth(a_s, b_s);
    if (a_s > b_s) return a;
    else return b;
}

string long_min(const string a,const string b) {
    if (a.empty() || b.empty()) {
        cout << "One of the element in long_min() is empty!" << endl;
        return "";
    }

    string a_s = a, b_s = b;

    if (a_s[0] == '-' && b_s[0] == '-') {
        a_s.erase(0, 1);
        b_s.erase(0, 1);
        return "-" + long_max(a_s, b_s);
    }
    
    equle_to_legnth(a_s, b_s);
    if (a_s < b_s) return a;
    else return b;
    
}

string long_sum(string a, string b) {
    if (a.empty() || b.empty()) {
        cout << "One of the element in long_sum() is empty!" << endl;
        return "";
    }

    int in_mind = 0;
    string result;
    int a_digit, b_digit;
    string sign;

    if (a[0] == '-' && b[0] == '-') {
        a.erase(0, 1);
        b.erase(0, 1);
        sign = "-";
    }
    else if (a[0] == '-') {
        a.erase(0, 1);
        return long_dif(b, a);
    }
    else if (b[0] == '-') {
        b.erase(0, 1);
        return long_dif(a, b);
    }

    equle_to_legnth(a, b);

    for (int i = a.length() - 1; i >= 0; i--) {
        a_digit = (a[i] - '0') + in_mind;
        b_digit = b[i] - '0';
        in_mind = (a_digit + b_digit) / 10;
        result += to_string((a_digit + b_digit) % 10);
    }

    if (in_mind != 0) result.push_back('1');
    result += sign;
    reverse(result.begin(), result.end());

    return result;
}

string long_dif_positive(string a_s, string b_s) {
    if (a_s.empty() || b_s.empty()) {
        cout << "One of the element in long_dif_positive() is empty!" << endl;
        return "";
    }

    int in_mind = 0;
    string result;
    int a_digit, b_digit;
    string sign;

    equle_to_legnth(a_s, b_s);

    if (long_max(a_s, b_s) == b_s) {
        swap(a_s, b_s);
        sign = "-";
    }

    for (int i = a_s.length() - 1; i >= 0; i--) {
        a_digit = (a_s[i] - '0') + in_mind;
        b_digit = b_s[i] - '0';
        in_mind = 0;
        if (a_digit - b_digit < 0) {
            in_mind = -1;
            a_digit += 10;
        }
        result += to_string(a_digit - b_digit);
    }

    while (result[result.length() - 1] == '0') result.erase(a_s.length() - 1, 1);
    result += sign;
    reverse(result.begin(), result.end());
    return result;
}

string long_dif(string a, string b) {
    if (a.empty() || b.empty()) {
        cout << "One of the element in long_dif() is empty!" << endl;
        return "";
    }

    if (a[0] == '-' && b[0] == '-') {
        a.erase(0, 1);
        b.erase(0, 1);
        swap(a, b);
    }
    else if (a[0] == '-') {
        a.erase(0, 1);
        return "-" + long_sum(a, b);
    }
    else if (b[0] == '-') {
        b.erase(0, 1);
        return long_sum(a, b);
    }
    
    int in_mind = 0;
    string result;
    int a_digit, b_digit;
    string sign;

    equle_to_legnth(a, b);

    if (long_max(a, b) == b && a != b) {
        swap(a, b);
        sign = "-";
    }

    for (int i = a.length() - 1; i >= 0; i--) {
        a_digit = (a[i] - '0') + in_mind;
        b_digit = b[i] - '0';
        in_mind = 0;
        if (a_digit - b_digit < 0) {
            in_mind = -1;
            a_digit += 10;
        }
        result += to_string(a_digit - b_digit);
    }

    while (result[result.length() - 1] == '0' && result != "0") result.erase(a.length() - 1, 1);
    result += sign;
    reverse(result.begin(), result.end());
    return result;
    
}

string long_multi(string a, string b) {
    if (a.empty() || b.empty()) {
        cout << "One of the element in long_multi() is empty!" << endl;
        return "";
    }

    //if (a == "0" || b == "0") return "0";

    if (long_max(a, b) == a) swap(a, b);

    int in_mind = 0;
    string result = "0", step_result;
    string sign = "";
    int in_mind_i;
    int a_digit, b_digit;

    if (a[0] == '-' && b[0] == '-') {
        a.erase(0, 1);
        b.erase(0, 1);
    }
    else if (a[0] == '-') {
        a.erase(0, 1);
        sign = "-";
    }
    else if (b[0] == '-') {
        b.erase(0, 1);
        sign = "-";
    }

    for (int e = b.length() - 1; e >= 0; e--) {
        for (int i = a.length() - 1; i >= 0; i--) {
            a_digit = a[i] - '0';
            b_digit = b[e] - '0';

            in_mind_i = (a_digit * b_digit) + in_mind;

            in_mind = in_mind_i / 10;

            step_result += to_string(in_mind_i % 10);
        }
        if (in_mind != 0) step_result.push_back(char(in_mind + '0'));

        reverse(step_result.begin(), step_result.end());

        string doner(b.length() - 1 - e, '0');
        step_result += doner;

        result = long_sum(result, step_result);

        step_result = "";
        doner = "";
        in_mind = 0;
    }
    result = sign + result;
    return result;
}

string long_pow(string x, unsigned long long p) {
    if (x.empty()) {
        cout << "Element in long_pow() is empty!" << endl;
        return "";
    }
    else if (p < 0) return "0";

    string result = "1";
    for (unsigned long long i = 0; i < p; i++) result = long_multi(result, x);
    return result;
}

string long_div(string a_s, string b_s) {
    if (b_s == "0" || b_s.empty() || a_s.empty()) {
        cout << "Element in long_pow() is empty or division to 0!" << endl;
        return "";
    }
    else if (a_s == "0") return "0";

    string num_max = "18446744073709551615";
    string result;

    if (long_max(num_max,b_s) == num_max) {
        unsigned long long b = stol(b_s);
        unsigned long long def = 0;

        int cnt = 1;
        while (stol(a_s.substr(0, cnt)) / b == 0) cnt++;
        unsigned long long a_p = stoi(a_s.substr(0, cnt));

        for (unsigned long long i = cnt; i <= a_s.size(); i++) {
            result += to_string(a_p / b);
            def = a_p % b;
            a_p = int(a_s[i] - '0');
            if (def != 0) a_p += 10 * def;
        }
    }
    else {
        result = "0";
        while (long_max(long_multi(long_sum(result, "1"), b_s), a_s) == a_s)
        {
            result = long_sum(result, "1");
        }
    }

    return result;
}

string long_remainder_of_div(string a_s, string b_s) { //Remainder of the division
    if (a_s.empty() || b_s.empty()) {
        cout << "One of the element in long_remainder_of_div() is empty!" << endl;
        return "";
    }
    return long_dif(a_s, long_multi(long_div(a_s, b_s), b_s));
}