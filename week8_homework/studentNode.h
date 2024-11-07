
#ifndef STUDENT_NODE_H
#define STUDENT_NODE_H

#include<iostream>

#include "studentStruct.h"
// This part is about date linked list
struct DATE_LIST {
	DATE* next;
};
DATE_LIST dateList;
// Append a date to the list
void appendDate(DATE_LIST& a, DATE b) {
	DATE* newDate = new DATE(b.day, b.month, b.year);
	while(a.next != nullptr) {
		a.next = (*a.next).nextNode;
	}
	(*a.next).nextNode = newDate;
}
//find Date in the listDate
bool findDate(DATE_LIST& a, DATE b) {
	DATE* temp = a.next;
	while (temp != nullptr) {
		if (compareDate(temp, &b)) return true;
		temp = (*temp).nextNode;
	}
	return false;
}
struct STUDENT_NODE {
	STUDENT* next;
};
STUDENT_NODE List;

void apendList(STUDENT_NODE& a) {
	char _svID[10];
	char _name[30];
	int _day, _month, _year;
	bool _gender;
	char _address[50];
	char _major[30];
	char _Kyear[5];
	std::cout << "Enter student ID: ";
	std::cin >> _svID;
	std::cin.ignore(10, '\n');
	std::cout << "Enter student name: ";
	std::cin.getline(_name, 30);
	std::cin.ignore(30, '\n');
	std::cout << "Enter gender( Male: 0 // Female: 1): ";
	std::cin >> _gender;
	std::cout << "Enter date of birth: ";
	std::cin >> _day >> _month >> _year;
	std::cin.ignore('\n');
	std::cout << "Enter address: ";
	std::cin.getline(_address, 50);
	std::cin.ignore(50, '\n');
	std::cout << "Enter major: ";
	std::cin.getline(_major, 30);
	std::cin.ignore(30, '\n');
	std::cout << "Enter Kyear: ";
	std::cin.getline(_Kyear, 5);
	std::cin.ignore(5, '\n');
	DATE _dob(_day, _month, _year);
	STUDENT* newStudent = new STUDENT(_svID, _name, _gender, _dob, _address, _major, _Kyear);
	if (List.next == nullptr) {
		List.next = newStudent;
	}
	else {
		STUDENT* temp = List.next;
		while ((*temp).nextStudent != nullptr) {
			temp = (*temp).nextStudent;
		}
		(*temp).nextStudent = newStudent;
	}
}
void printStudent(STUDENT* a) {
	std::cout << "Student ID: " << (*a).svID << std::endl;
	std::cout << "Student name: " << (*a).name << std::endl;
	std::cout << "Gender: " << ((*a).gender, "Female", "Male") << std::endl;
	std::cout << "Date of birth: " << (*a).dob.day << "/" << (*a).dob.month << "/" << (*a).dob.year << std::endl;
	std::cout << "Address: " << (*a).address << std::endl;
	std::cout << "Major: " << (*a).major << std::endl;
	std::cout << "Kyear: " << (*a).Kyear << std::endl;
}
void printList(STUDENT_NODE& a) {
	std::cout << "List of students below:" << std::endl;
	STUDENT* temp = a.next;
	while (temp != nullptr) {
		printStudent(temp);
		temp = (*temp).nextStudent;
	}
}
void sortViaSvID(STUDENT_NODE& List) {
	STUDENT* temp1 = List.next;
	while(temp1 != nullptr) {
		STUDENT* temp2 = (*temp1).nextStudent;
		while (temp2 != nullptr) {
			if (strcmp((*temp1).svID, (*temp2).svID) > 0) {
				STUDENT temp = *temp1;
				*temp1 = *temp2;
				*temp2 = temp;
			}
			temp2 = (*temp2).nextStudent;
		}
		temp1 = (*temp1).nextStudent;
	}
}
void printSameDob(STUDENT_NODE& List) {
	bool checkAll = true;
	STUDENT* temp1 = List.next;
	while(temp1 != nullptr) {
		if (findDate(dateList, (*temp1).dob)) {
			appendDate(dateList, (*temp1).dob);
		}
		bool checkAnother = false;
		STUDENT * temp2 = (*temp1).nextStudent;
		while (temp2 != nullptr) {
			if (compareDate(&(*temp1).dob, &(*temp2).dob)) {
				if(!checkAnother) {
					std::cout << "The students have the same date of birth: " << std::endl; 
					printStudent(temp1);
					printStudent(temp2);
					checkAnother = true;
				} else{
					printStudent(temp2);
				}
				checkAll = false;
			}
			temp2 = (*temp2).nextStudent;
		}
		temp1 = (*temp1).nextStudent;
	}
	if(checkAll) std::cout << "There is no student with the same date of birth" << std::endl;
}
void deleteSameDate(STUDENT_NODE& List, DATE_LIST& dateList) {
	STUDENT* temp1 = List.next;
	while ((*temp1).nextStudent != nullptr) {
		if (findDate(dateList, (*(*temp1).nextStudent).dob)) {
			(*temp1).nextStudent = (*(*temp1).nextStudent).nextStudent;
			delete (*temp1).nextStudent;
		} else temp1 = (*temp1).nextStudent;
	}
}
#endif // !STUDENT_NODE_H

