/* 
 * File:   main.cpp
 * Author: Tara Tandel <Tara.tandel at Tara.home>
 *
 * Created on October 22, 2014, 11:40 PM
 */

#include <iostream>
#include <string>
#include <cstdio>
#include "List.h"

using namespace std;

int main(int argc, char* argv[])
{
	string s_number1;
	cin >> s_number1;

	string s_number2;
	cin >> s_number2;

	List<short> N1;
	List<short> N2;
	List<short> ANS;

	int i = s_number1.size() - 1;
	while (i >= 0) {
		short number = 0;
		if (i >= 0)
			number += s_number1[i] - '0';
		i--;
		if (i >= 0)
			number += (s_number1[i] - '0') * 10;
		i--;
		if (i >= 0)
			number += (s_number1[i] - '0') * 100;
		i--;
		N1.push_back(number);
	}

	i = s_number2.size() - 1;
	while (i >= 0) {
		short number = 0;
		if (i >= 0)
			number += s_number2[i] - '0';
		i--;
		if (i >= 0)
			number += (s_number2[i] - '0') * 10;
		i--;
		if (i >= 0)
			number += (s_number2[i] - '0') * 100;
		i--;
		N2.push_back(number);
	}

	int index1 = 0;
	int index2 = 0;
	short carry = 0;
	while (carry != 0 || index1 < N1.getSize() || index2 < N2.getSize()) {
		int number = 0;
		if (index1 < N1.getSize())
			number += N1[index1];
		if (index2 < N2.getSize())
			number += N2[index2];
		number += carry;

		index1++;
		index2++;

		carry = number / 1000;
		ANS.push_back(number % 1000);
	}

	i = ANS.getSize() - 1;
	printf("%d", ANS[i]);
	i--;
	for (; i >= 0; i--) {
		printf("%03d", ANS[i]);
	}
	cout << endl;

	return 0;
}

