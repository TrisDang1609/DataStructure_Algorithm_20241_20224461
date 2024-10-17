#include<iostream>
#include<string.h>

#ifndef sortColor
#define sortColor
void sortColorFunc(std::string arr[], int n) {
	int arrCheck[3];
	arrCheck[0] = arrCheck[1] = arrCheck[2] = 0;
	std::string display[3];
	display[0] = "Do", display[1] = "Xanh", display[2] = "Trang";
	for (int i = 0; i < n; i++) {
		if (arr[i] == "Do") {
			arrCheck[0]++;
		}
		else if (arr[i] == "Xanh") {
			arrCheck[1]++;
		}
		else {
			arrCheck[2]++;
		}
	}
	for (int i = 0; i < 3; i++) {
		while (arrCheck[i]--) {
			std::cout << display[i] << " ";
		}
	}
}
#endif // !sortColor

