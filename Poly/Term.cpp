/* 
 * File:   Term.cpp
 * Author: Tara Tandel
 * 
 * Created on October 18, 2014, 10:38 PM
 */

#include "Term.h"

Term::Term()
{
}

Term::Term(const Term& orig)
{
	this->coeff = orig.coeff;
	this->power = orig.power;
}

int Term::comp(Term a, Term b)
{
	return a.power - b.power;
}


Term::Term(int power, float coeff)
{
	this->power = power;
	this->coeff = coeff;
}

Term::~Term()
{
}

