/* 
 * File:   main.cpp
 * Author: Tara Tandel
 *
 * Created on October 18, 2014, 10:35 PM
 */

#include <cstdlib>

#include "Poly.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
	Poly p1;
	p1.addTerm(Term(0, 1));
	p1.addTerm(Term(1, 2));
	p1.addTerm(Term(10, 1));
	
	Poly p2;
	p2.addTerm(Term(0, 1));
	p2.addTerm(Term(20, 2));
	
	p1.add(p2);
	
	p1.print();
	return 0;
}

