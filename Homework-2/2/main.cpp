/* 
 * File:   main.cpp
 * Author: Tara Tandel <Tara.tandel at Tara.home>
 *
 * Created on October 22, 2014, 6:21 PM
 */

#include <iostream>
#include "Stack.h"

int main(int argc, char* argv[])
{
	int number;

	std::cin >> number;

	Stack <short> d_to_b;

	do {
		d_to_b.push(number % 2);
		number /= 2;
	} while (number != 0);

	while (!d_to_b.empty()) {
		std::cout << d_to_b.top();
		d_to_b.pop();
	}
	std::cout << std::endl;
}

