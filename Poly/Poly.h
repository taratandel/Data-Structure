/* 
 * File:   Poly.h
 * Author: Tara Tandel
 *
 * Created on October 18, 2014, 10:35 PM
 */

#ifndef POLY_H
#define	POLY_H

#include "Term.h"
#include <list>

class Poly {
public:
	Poly();
	Poly(const Poly& orig);

	void add(Poly& p);
	void sort();
	void addTerm(const Term& term);
	void print();
	
	virtual ~Poly();
private:
	std::list<Term> terms;
};

#endif	/* POLY_H */

