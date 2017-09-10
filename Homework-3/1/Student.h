/* 
 * File:   Student.h
 * Author: Tara Tandel <Tara.tandel at Tara.home>
 *
 * Created on November 4, 2014, 10:50 PM
 */

#ifndef STUDENT_H
#define	STUDENT_H

#include <string>
#include <iostream>

class Student {
public:
	Student();
	Student(const Student& orig);

	std::string GetFisrt_name() const;
	void SetFisrt_name(std::string fisrt_name);
	int GetGrade() const;
	void SetGrade(int grade);
	std::string GetLast_name() const;
	void SetLast_name(std::string last_name);
	bool IsMale() const;
	void SetMale(bool male);
	int GetStudent_numebr() const;
	void SetStudent_numebr(int student_numebr);
	friend std::ostream& operator<<(std::ostream &os, const Student& student);
	friend std::istream& operator>>(std::istream &is, Student& student);

	virtual ~Student();
private:
	int grade;
	int student_numebr;
	bool male;
	std::string fisrt_name;
	std::string last_name;
};

#endif	/* STUDENT_H */

