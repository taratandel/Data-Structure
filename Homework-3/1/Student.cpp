/* 
 * File:   Student.cpp
 * Author: Tara Tandel <Tara.tandel at Tara.home>
 * 
 * Created on November 4, 2014, 10:50 PM
 */

#include "Student.h"

Student::Student()
{
}

Student::Student(const Student& orig)
{
	student_numebr = orig.student_numebr;
	fisrt_name = orig.fisrt_name;
	last_name = orig.last_name;
	male = orig.male;
	grade = orig.grade;
}

std::string Student::GetFisrt_name() const
{
	return fisrt_name;
}

void Student::SetFisrt_name(std::string fisrt_name)
{
	this->fisrt_name = fisrt_name;
}

int Student::GetGrade() const
{
	return grade;
}

void Student::SetGrade(int grade)
{
	this->grade = grade;
}

std::string Student::GetLast_name() const
{
	return last_name;
}

void Student::SetLast_name(std::string last_name)
{
	this->last_name = last_name;
}

bool Student::IsMale() const
{
	return male;
}

void Student::SetMale(bool male)
{
	this->male = male;
}

int Student::GetStudent_numebr() const
{
	return student_numebr;
}

void Student::SetStudent_numebr(int student_numebr)
{
	this->student_numebr = student_numebr;
}

std::ostream& operator<<(std::ostream &os, const Student& student)
{
	os << "Student#: " << student.student_numebr << " - ";
	os << student.fisrt_name << " " << student.last_name << " - ";
	os << ((student.male) ? "Male" : "Female") << " - ";
	os << "Grade: " << student.grade;

	return os;
}

std::istream& operator>>(std::istream &is, Student& student)
{
	is >> student.student_numebr;
	is >> student.fisrt_name >> student.last_name;
	is >> student.male;
	is >> student.grade;
	
	return is;
}

Student::~Student()
{
}

