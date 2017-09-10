/* 
 * File:   main.cpp
 * Author: Tara Tandel <Tara.tandel at Tara.home>
 *
 * Created on October 22, 2014, 5:40 PM
 */

#include <iostream>
#include "Stack.h"

int main(int argc, char* argv[])
{
	Stack <char> p;
	Stack <char> b;
	Stack <char> a;

	bool notmatch = false;
	char c;
	while ((c = std::cin.get()) != '\n') {
		if (notmatch) {
			continue;
		}

		switch (c) {
		case '(':
			p.push(c);
			break;
		case '[':
			b.push(c);
			break;
		case '{':
			a.push(c);
			break;
		case ')':
			if (p.top() != '(') {
				notmatch = true;
			}
			p.pop();
			break;
		case ']':
			if (b.top() != '[') {
				notmatch = true;
			}
			b.pop();
			break;
		case '}':
			if (a.top() != '{') {
				notmatch = true;
			}
			a.pop();
			break;
		}
	}
	if (notmatch || p.size() != 0 || b.size() != 0 || a.size() != 0) {
		std::cout << "Not match" << std::endl;
	} else {
		std::cout << "Match" << std::endl;
	}
}

