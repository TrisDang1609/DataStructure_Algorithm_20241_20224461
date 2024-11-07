#include<iostream>

#include "studentNode.h"
#include "circleTable.h"
int main() {
	int choice;
	std::cout << "Bai1 hay bai2: ";
	std::cin >> choice;
	if (choice == 1) {
		List.next = nullptr;
		dateList.next = nullptr;
		// Append n students to the list
		std::cout << "Enter the number of students: ";
		int n;
		std::cin >> n;
		for (int i = 0; i < n; i++) apendList(List);
		//print out the list of students after sort via svID
		sortViaSvID(List);
		printList(List);
		//print out the same dob students
		printSameDob(List);
		//delete the same dob students except the first one
		deleteSameDate(List, dateList);
		printList(List);
	}
	else if (choice == 2) {
		table.next = nullptr;
		int n;
		std::cout << "Enter the number of node in circle: ";
		std::cin >> n;
		initAllTable(table, n);
		int m;
		std::cout << "Enter the number of node to delete: ";
		std::cin >> m;
		passTable(table, n, m);
		std::cout << "The last node is: " << (*table.next).data;
	}
}