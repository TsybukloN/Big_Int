#pragma once
// #define NDEBUG //uncomment to kill all tests
#include <cassert>
#include <iostream>
#include <sstream>
#include "Big_Int.h"

using namespace std;

void TEST_long_max() {
	assert(long_max("1", "3") == "3");
	cout << "Checkpoint #1 is done!\n";

	assert(long_max("11", "3") == "11");
	cout << "Checkpoint #2 is done!\n";

	assert(long_max("-125", "9") == "9");
	cout << "Checkpoint #3 is done!\n";

	assert(long_max("125", "-3") == "125");
	cout << "Checkpoint #4 is done!\n";

	assert(long_max("-11", "-3") == "-3");
	cout << "Checkpoint #5 is done!\n";

	cout << "All checkpoints is done!\n" << endl;
}

void TEST_long_min() {
	assert(long_min("1", "3") == "1");
	cout << "Checkpoint #1 is done!\n";

	assert(long_min("11", "3") == "3");
	cout << "Checkpoint #2 is done!\n";

	assert(long_min("-125", "9") == "-125");
	cout << "Checkpoint #3 is done!\n";

	assert(long_min("125", "-3") == "-3");
	cout << "Checkpoint #4 is done!\n";

	assert(long_min("-11", "-3") == "-11");
	cout << "Checkpoint #5 is done!\n";

	cout << "All checkpoints is done!\n" << endl;
}

void TEST_long_sum() {
	assert(long_sum("1", "3") == "4");
	cout << "Checkpoint #1 is done!\n";

	assert(long_sum("19", "3") == "22");
	cout << "Checkpoint #2 is done!\n";

	assert(long_sum("-125", "9") == "-116");
	cout << "Checkpoint #3 is done!\n";

	assert(long_sum("125", "-3") == "122");
	cout << "Checkpoint #4 is done!\n";

	assert(long_sum("-11", "-3") == "-14");
	cout << "Checkpoint #5 is done!\n";

	assert(long_sum("0", "0") == "0");
	cout << "Checkpoint #6 is done!\n";

	cout << "All checkpoints is done!\n" << endl;
}

void TEST_long_dif() {
	assert(long_dif("4", "1") == "3");
	cout << "Checkpoint #1 is done!\n";

	assert(long_dif("22", "3") == "19");
	cout << "Checkpoint #2 is done!\n";

	assert(long_dif("-125", "9") == "-134");
	cout << "Checkpoint #3 is done!\n";

	assert(long_dif("125", "-3") == "128");
	cout << "Checkpoint #4 is done!\n";

	assert(long_dif("-11", "-3") == "-8");
	cout << "Checkpoint #5 is done!\n";

	assert(long_dif("0", "0") == "0");
	cout << "Checkpoint #6 is done!\n";

	cout << "All checkpoints is done!\n" << endl;
}

void TEST_long_multi() {
	assert(long_multi("125", "5") == "625");
	cout << "Checkpoint #1 is done!\n";

	assert(long_multi("-125", "10") == "-1250");
	cout << "Checkpoint #2 is done!\n";

	assert(long_multi("125", "-5") == "-625");
	cout << "Checkpoint #3 is done!\n";

	assert(long_multi("-125", "-5") == "625");
	cout << "Checkpoint #4 is done!\n";

	assert(long_dif("0", "0") == "0");
	cout << "Checkpoint #5 is done!\n";

	cout << "All checkpoints is done!\n" << endl;
}

void TEST_long_pow() {
	assert(long_pow("2", 3) == "8");
	cout << "Checkpoint is done!\n" << endl;
}

void TEST_long_div() {
	assert(long_div("10", "2") == "5");
	cout << "Checkpoint #1 is done!\n";

	assert(long_div("22", "4") == "5");
	cout << "Checkpoint #2 is done!\n";

	assert(long_div("18446744073709551618", "2") == "9223372036854775809");
	cout << "Checkpoint #3 is done!\n";

	assert(long_div("0", "2") == "0");
	cout << "Checkpoint #4 is done!\n";

	assert(long_div("18446744073709551618", "0") == "");
	cout << "Checkpoint #5 is done!\n";

	assert(long_div("5", "1") == "5");
	cout << "Checkpoint #6 is done!\n";

	cout << "All checkpoints is done!\n" << endl;
}

void TEST_long_remainder_of_div() {
	assert(long_remainder_of_div("11", "2") == "1");
	cout << "Checkpoint #1 is done!\n";

	assert(long_remainder_of_div("22", "4") == "2");
	cout << "Checkpoint #2 is done!\n";

	assert(long_remainder_of_div("2", "1") != "0");
	cout << "Checkpoint #3 is done!\n";

	cout << "All checkpoints is done!\n" << endl;
}

///////////////////////////////////////////////////

void TEST_Big_Int_ios() {
	Big_Int big_int;

	string line = "123";
	istringstream istream(line);
	istream >> big_int;
	assert(big_int.get_val() == "123");
	cout << "Checkpoint #1 is done!\n";

	ostringstream ostream;
	ostream << big_int;
	assert(ostream.str() == "123");
	cout << "Checkpoint #2 is done!\n";

	cout << "All checkpoints is done!\n" << endl;
}

void TEST_Big_Int_EGL() {
	Big_Int big_int_1("1");
	Big_Int big_int_2("1");
	Big_Int big_int_3("2");

	assert(big_int_1 == big_int_2);
	cout << "Checkpoint #1 in done\n";

	assert(big_int_1 != big_int_3);
	cout << "Checkpoint #2 in done\n";

	assert(big_int_2 < big_int_3);
	assert(big_int_2 <= big_int_3);
	assert(big_int_1 <= big_int_2);
	cout << "Checkpoint #3 in done\n";

	assert(big_int_3 > big_int_1);
	assert(big_int_3 >= big_int_1);
	assert(big_int_2 >= big_int_1);
	cout << "Checkpoint #4 in done\n";

	cout << "All checkpoints is done!\n" << endl;
}

void TEST_Big_Int_Addition() {
	{
		Big_Int big_int_1("1");
		Big_Int big_int_2("3");

		assert(big_int_1 + big_int_2 == Big_Int("4"));
		big_int_1 += big_int_2;
		assert(big_int_1  == Big_Int("4"));
		++big_int_1;
		assert(big_int_1 == Big_Int("5"));
		cout << "Checkpoint #1 in done\n";
	}

	{
		Big_Int big_int_1("19");
		Big_Int big_int_2("3");

		assert(big_int_1 + big_int_2 == Big_Int("22"));
		cout << "Checkpoint #2 in done\n";
	}

	{
		Big_Int big_int_1("-125");
		Big_Int big_int_2("9");

		assert(big_int_1 + big_int_2 == Big_Int("-116"));
		cout << "Checkpoint #3 in done\n";
	}

	{
		Big_Int big_int_1("125");
		Big_Int big_int_2("-3");

		assert(big_int_1 + big_int_2 == Big_Int("122"));
		cout << "Checkpoint #4 in done\n";
	}

	{
		Big_Int big_int_1("-11");
		Big_Int big_int_2("-3");

		assert(big_int_1 + big_int_2 == Big_Int("-14"));
		cout << "Checkpoint #5 in done\n";
	}

	{
		Big_Int big_int_1("0");
		Big_Int big_int_2("0");

		assert(big_int_1 + big_int_2 == Big_Int("0"));
		cout << "Checkpoint #6 in done\n";
	}

	cout << "All checkpoints is done!\n" << endl;
}

void TEST_Big_Int_Subtraction() {
	{
		Big_Int big_int_1("4");
		Big_Int big_int_2("3");

		assert(big_int_1 - big_int_2 == Big_Int("1"));
		big_int_1 -= big_int_2;
		assert(big_int_1 == Big_Int("1"));
		--big_int_1;
		assert(big_int_1 == Big_Int("0"));
		cout << "Checkpoint #1 in done\n";
	}

	{
		Big_Int big_int_1("22");
		Big_Int big_int_2("3");

		assert(big_int_1 - big_int_2 == Big_Int("19"));
		cout << "Checkpoint #2 in done\n";
	}

	{
		Big_Int big_int_1("-125");
		Big_Int big_int_2("9");

		assert(big_int_1 - big_int_2 == Big_Int("-134"));
		cout << "Checkpoint #3 in done\n";
	}

	{
		Big_Int big_int_1("125");
		Big_Int big_int_2("-3");

		assert(big_int_1 - big_int_2 == Big_Int("128"));
		cout << "Checkpoint #4 in done\n";
	}

	{
		Big_Int big_int_1("-11");
		Big_Int big_int_2("-3");

		assert(big_int_1 - big_int_2 == Big_Int("-8"));
		cout << "Checkpoint #5 in done\n";
	}

	{
		Big_Int big_int_1("0");
		Big_Int big_int_2("0");

		assert(big_int_1 - big_int_2 == Big_Int("0"));
		cout << "Checkpoint #6 in done\n";
	}

	cout << "All checkpoints is done!\n" << endl;
}

void TEST_Big_Int_Multiplication() {
	{
		Big_Int big_int_1("125");
		Big_Int big_int_2("5");

		assert(big_int_1 * big_int_2 == Big_Int("625"));
		big_int_1 *= big_int_2;
		assert(big_int_1 == Big_Int("625"));
		cout << "Checkpoint #1 in done\n";
	}

	{
		Big_Int big_int_1("-125");
		Big_Int big_int_2("10");

		assert(big_int_1 * big_int_2 == Big_Int("-1250"));
		cout << "Checkpoint #2 in done\n";
	}

	{
		Big_Int big_int_1("125");
		Big_Int big_int_2("-5");

		assert(big_int_1 * big_int_2 == Big_Int("-625"));
		cout << "Checkpoint #3 in done\n";
	}

	{
		Big_Int big_int_1("-125");
		Big_Int big_int_2("-5");

		assert(big_int_1 * big_int_2 == Big_Int("625"));
		cout << "Checkpoint #4 in done\n";
	}

	{
		Big_Int big_int_1("0");
		Big_Int big_int_2("0");

		assert(big_int_1 * big_int_2 == Big_Int("0"));
		cout << "Checkpoint #5 in done\n";
	}

	cout << "All checkpoints is done!\n" << endl;
}

void TEST_Big_Int_Division() {
	{
		Big_Int big_int_1("10");
		Big_Int big_int_2("2");

		assert(big_int_1 / big_int_2 == Big_Int("5"));
		big_int_1 /= big_int_2;
		assert(big_int_1 == Big_Int("5"));
		cout << "Checkpoint #1 in done\n";
	}

	{
		Big_Int big_int_1("18446744073709551618");
		Big_Int big_int_2("2");

		assert(big_int_1 / big_int_2 == Big_Int("9223372036854775809"));
		cout << "Checkpoint #2 in done\n";
	}

	{
		Big_Int big_int_1("22");
		Big_Int big_int_2("4");

		assert(big_int_1 / big_int_2 == Big_Int("5"));
		cout << "Checkpoint #3 in done\n";
	}

	{
		Big_Int big_int_1("0");
		Big_Int big_int_2("5");

		assert(big_int_1 / big_int_2 == Big_Int("0"));
		cout << "Checkpoint #4 in done\n";
	}

	{
		Big_Int big_int_1("18446744073709551618");
		Big_Int big_int_2("0");

		assert(big_int_1 / big_int_2 == Big_Int(""));
		cout << "Checkpoint #5 in done\n";
	}

	{
		Big_Int big_int_1("5");
		Big_Int big_int_2("1");

		assert(big_int_1 / big_int_2 == Big_Int("5"));
		cout << "Checkpoint #5 in done\n";
	}

	cout << "All checkpoints is done!\n" << endl;
}

void TEST_Big_Int_Modulo() {
	{
		Big_Int big_int_1("11");
		Big_Int big_int_2("2");

		assert(big_int_1 % big_int_2 == Big_Int("1"));
		big_int_1 %= big_int_2;
		assert(big_int_1 == Big_Int("1"));
		cout << "Checkpoint #1 in done\n";
	}

	{
		Big_Int big_int_1("22");
		Big_Int big_int_2("4");

		assert(big_int_1 % big_int_2 == Big_Int("2"));
		cout << "Checkpoint #2 in done\n";
	}

	{
		Big_Int big_int_1("2");
		Big_Int big_int_2("1");

		assert(big_int_1 % big_int_2 == Big_Int("0"));
		cout << "Checkpoint #3 in done\n";
	}

	cout << "All checkpoints is done!\n" << endl;
}