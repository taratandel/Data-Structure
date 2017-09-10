/* 
 * File:   Poly.cpp
 * Author: Tara Tandel
 * 
 * Created on October 18, 2014, 10:35 PM
 */

#include "Poly.h"
#include <algorithm>
#include <iostream>

Poly::Poly()
{
}

Poly::Poly(const Poly& orig) : terms(orig.terms)
{
}

void Poly::sort()
{
	terms.sort(Term::comp);
}

void Poly::add(Poly& p)
{
	auto i = this->terms.begin();
	auto j = p.terms.begin();

	while (i != this->terms.end() && j != p.terms.end()) {
		if (i->getPower() < j->getPower()) {
			i++;
		} else if (i->getPower() == j->getPower()) {
			i->setCoeff(i->getCoeff() + j->getCoeff());
			i++;
			j++;
		} else {
			this->terms.insert(i, *j);
			j++;
		}
	}

	while (i == this->terms.end() && j != p.terms.end()) {
		this->terms.push_back(*j);
		j++;
	}
}

void Poly::addTerm(const Term& term)
{
	terms.push_back(term);
}

void Poly::print()
{
	for (Term& t : this->terms) {
		std::cout << t.getCoeff() << " * X ^ " << t.getPower() << " + ";
	}
	std::cout << std::endl;
}

Poly::~Poly()
{
}

