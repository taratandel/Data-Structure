/* 
 * File:   main.cpp
 * Author: Tara Tandel <Tara.tandel at Tara.home>
 *
 * Created on November 4, 2014, 6:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <list>
#include "List.h"
#include "Student.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
	List< List<Student> > master_list;
	int number;
	cout << "Please enter student information with sorted grades:" << endl;
	cin >> number;
	for (int i = 0; i < number; i++) {
		Student student;
		cin >> student;
		if (master_list.getSize() != 0) {
			if (master_list.back().back().GetGrade() == student.GetGrade()) {
				master_list.back().push_back(student);
			} else {
				List<Student> list;
				list.push_back(student);
				master_list.push_back(list);
			}
		} else {
			List<Student> list;
			list.push_back(student);
			master_list.push_back(list);
		}
	}
	cout << "Enter grade :" << endl;
	int grade;
	cin >> grade;

	List< List<Student> >::Iterator it = master_list.begin();
	while ((*it).front().GetGrade() < grade)
		it++;
	if ((*it).front().GetGrade() > grade) {
		cout << "Your grade not found" << endl;
		exit(0);
	}

	cout << (*it) << endl;

	string command;
	while (true) {
		cin >> command;
		if (command == "Next") {
			it++;
			cout << (*it) << endl;
		} else if (command == "Perv") {
			it--;
			cout << (*it) << endl;
		} else if (command == "Enough") {
			exit(0);
		} else if (command == "Grade") {
			int grade;
			cin >> grade;
			if ((*it).front().GetGrade() <= grade) {
				while ((*it).front().GetGrade() < grade)
					it++;
				if ((*it).front().GetGrade() > grade) {
					cout << "Your grade not found" << endl;
					exit(0);
				}
				cout << (*it) << endl;
			} else {
				while ((*it).front().GetGrade() > grade)
					it--;
				if ((*it).front().GetGrade() < grade) {
					cout << "Your grade not found" << endl;
					exit(0);
				}
				cout << (*it) << endl;
			}
		}
	}
	return 0;
}

