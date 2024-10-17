// include init libs
#include<iostream>
#include<string.h>

//include .h_files
#include "Blum.h"
#include "sortColor.h"

int main() {
	int choice;
	int n;
	std::cout << "Bai 1 hay Bai 2?\n" << "1.Bai 1\n" << "2.Bai 2\n";
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "Bai 1" << std::endl;
		std::cout << "enter N: ";
		std::cin >> n;
		std::string arr[10000];
		for (int i = 0; i < n; i++) {
			std::cin >> arr[i];
		}
		sortColorFunc(arr, n);
	}
	else {
		int blum;
		std::cout << "Bai 2" << std::endl;
		std::cout << "enter N: ";
		std::cin >> n;
		std::cout << "The needy blum: ";
		std::cin >> blum;
		blumFunc(n, blum);
	}
}