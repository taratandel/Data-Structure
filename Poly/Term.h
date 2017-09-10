/* 
 * File:   Term.h
 * Author: Tara Tandel
 *
 * Created on October 18, 2014, 10:38 PM
 */

#ifndef TERM_H
#define	TERM_H

class Term {
public:
	Term();
	Term(const Term& orig);
	Term(int power, float coeff);

	static int comp(Term a, Term b);
	
	float getCoeff() const
	{
		return coeff;
	}

	void setCoeff(float coeff)
	{
		this->coeff = coeff;
	}

	int getPower() const
	{
		return power;
	}

	void setPower(int power)
	{
		this->power = power;
	}

	virtual ~Term();
private:
	float coeff;
	int power;
};

#endif	/* TERM_H */

