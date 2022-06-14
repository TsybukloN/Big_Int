#pragma once
using namespace std;

string long_max(string a_s, string b_s) {
    if (a_s.length() > b_s.length()) {
        string doner(a_s.length() - b_s.length(), '0');
        b_s = doner + b_s;
    }
    else if (b_s.length() > a_s.length()) {
        string doner(b_s.length() - a_s.length(), '0');
        a_s = doner + a_s;
    }

    if (a_s > b_s) return a_s;
    else return b_s;
}

string long_min(string a_s, string b_s) {
    if (a_s.length() > b_s.length()) {
        string doner(a_s.length() - b_s.length(), '0');
        b_s = doner + b_s;
    }
    else if (b_s.length() > a_s.length()) {
        string doner(b_s.length() - a_s.length(), '0');
        a_s = doner + a_s;
    }

    if (a_s < b_s) return a_s;
    else return a_s;
}

string long_sum(string a_s, string b_s) {
    if (a_s.length() > b_s.length()) {
        string doner(a_s.length() - b_s.length(), '0');
        b_s = doner + b_s;
    }
    else if (b_s.length() > a_s.length()) {
        string doner(b_s.length() - a_s.length(), '0');
        a_s = doner + a_s;
    }

    int in_mind = 0;
    string rez;
    int a, b;

    for (int i = a_s.length() - 1; i >= 0; i--) {
        a = (a_s[i] - '0') + in_mind;
        b = b_s[i] - '0';
        in_mind = (a + b) / 10;
        rez += to_string((a + b) % 10);
    }

    if (in_mind != 0) rez.push_back('1');
    reverse(rez.begin(), rez.end());
    return rez;
}

string long_diff(string a_s, string b_s) {
    if (a_s.length() > b_s.length()) {
        string doner(a_s.length() - b_s.length(), '0');
        b_s = doner + b_s;
    }
    else if (b_s.length() > a_s.length()) {
        string doner(b_s.length() - a_s.length(), '0');
        a_s = doner + a_s;
    }

    char zn = '+';
    if (a_s < b_s) {
        swap(a_s, b_s);
        zn = '-';
    }

    int in_mind = 0;
    string rez;
    int a, b;

    for (int i = a_s.length() - 1; i >= 0; i--) {
        a = (a_s[i] - '0') + in_mind;
        b = b_s[i] - '0';
        if (a - b < 0) {
            in_mind = -1;
            a += 10;
        }
        rez += to_string(a - b);
    }

    while (rez[rez.length() - 1] == '0') rez.erase(a_s.length() - 1, 1);
    rez.push_back(zn);
    reverse(rez.begin(), rez.end());
    return rez;
}

string long_multi(string a_s, string b_s) {
    if (a_s == "0" || b_s == "0") return "0";

    string b_s_doner, a_s_doner;
    if (a_s.length() > b_s.length()) {
        string doner(a_s.length() - b_s.length(), '0');
        b_s_doner = doner + b_s;
    }
    else if (b_s.length() > a_s.length()) {
        string doner(b_s.length() - a_s.length(), '0');
        a_s_doner = doner + a_s;
    }

    if (a_s_doner > b_s_doner) swap(a_s, b_s);

    int in_mind = 0;
    string rez = "0", rez_f;
    int rez_i;
    int a, b;

    for (int e = b_s.length() - 1; e >= 0; e--) {
        for (int i = a_s.length() - 1; i >= 0; i--) {
            a = a_s[i] - '0';
            b = b_s[e] - '0';

            rez_i = (a * b) + in_mind;

            in_mind = rez_i / 10;

            rez_f += to_string(rez_i % 10);
        }
        if (in_mind != 0) rez_f.push_back(char(in_mind + '0'));

        reverse(rez_f.begin(), rez_f.end());

        string doner(b_s.length() - 1 - e, '0');
        rez_f += doner;

        rez = long_sum(rez, rez_f);

        rez_f = "";
        doner = "";
        in_mind = 0;
    }
    return rez;
}

string long_pow(string x, unsigned long long p) {
    string rez = "1";
    for (unsigned long long i = 0; i < p; i++) rez = long_multi(rez, x);
    return rez;
}

string long_num_div(string a_s, unsigned long long b) {
    if (a_s == "0") return "0";
    unsigned long long def = 0;
    string rez;

    int cnt = 1;
    while (stoi(a_s.substr(0, cnt)) / b == 0) cnt++;
    unsigned long long a_p = stoi(a_s.substr(0, cnt));

    for (unsigned long long i = cnt; i <= a_s.size(); i++) {
        rez += to_string(a_p / b);
        def = a_p % b;
        a_p = a_s[i] - '0';
        if (def != 0) a_p += 10 * def;
    }

    return rez;
}

string long_s_to_s_div(string a_s, string b_s) {
    string rez = "0";
    while (long_max(long_multi(long_sum(rez, "1"), b_s), a_s) == a_s) {
        rez = long_sum(rez, "1");
    }
    return rez;
} // so slow

string long_div(string a_s, string b_s) {
    string num_max = "18446744073709551615";
    string rez;
    if (long_max(num_max,b_s) == num_max) {
        unsigned long long b = stoi(b_s);
        unsigned long long def = 0;

        int cnt = 1;
        while (stoi(a_s.substr(0, cnt)) / b == 0) cnt++;
        unsigned long long a_p = stoi(a_s.substr(0, cnt));

        for (unsigned long long i = cnt; i <= a_s.size(); i++) {
            rez += to_string(a_p / b);
            def = a_p % b;
            a_p = a_s[i] - '0';
            if (def != 0) a_p += 10 * def;
        }

        while (rez[0] == '0') rez.erase(0, 1);
    }
    else {
        rez = "0";
        while (long_max(long_multi(long_sum(rez, "1"), b_s), a_s) == a_s) {
            rez = long_sum(rez, "1");
        }
    }

    return rez;
}