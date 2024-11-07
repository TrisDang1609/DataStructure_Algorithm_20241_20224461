#include<iostream>

#ifndef MATHPROBLEM_H
#define MATHPROBLEM_H
int maxBac = -999999;
struct nodeX {
	float num;
	int bac;
	nodeX* nextNode;
	nodeX(float x, int y) {
		num = x;
		bac = y;
		nextNode = nullptr;
	}
};
struct List{
	nodeX* next;
};
List hXfunc, gXfunc;

void appendX(List& a) {
	float tempNum;
	std::cin >> tempNum;
	int tempBac;
	std::cin >> tempBac;
	if(tempBac > maxBac) maxBac = tempBac;
	if (tempNum == 0) {
		return;
	}
	nodeX* tempNode = new nodeX(tempNum, tempBac);
	if (a.next == nullptr) {
		a.next = tempNode;
	}
	else {
		nodeX* temp = a.next;
		while ((*temp).nextNode != nullptr) {
			temp = (*temp).nextNode;
		}
		(*temp).nextNode = tempNode;
	}
}
void buildXfunc(List& a, int times) {
	for (int i = 0; i < times; i++) {
		appendX(a);
	}
}
int findBac(int selectedBac, List* a) {
	nodeX* temp = (*a).next;
	while (temp != nullptr) {
		if ((*temp).bac == selectedBac) {
			return (*temp).num;
		}
		temp = (*temp).nextNode;
	}
}
void sortFunc(List& a) {
	nodeX* temp = a.next;
	while (temp != nullptr) {
		nodeX* temp2 = (*temp).nextNode;
		while (temp2 != nullptr) {
			if ((*temp).bac < (*temp2).bac) {
				float tempNum = (*temp).num;
				int tempBac = (*temp).bac;
				(*temp).num = (*temp2).num;
				(*temp).bac = (*temp2).bac;
				(*temp2).num = tempNum;
				(*temp2).bac = tempBac;
			}
			temp2 = (*temp2).nextNode;
		}
		temp = (*temp).nextNode;
	}
}

void addFunc(List& a, List& b) {
	nodeX* tempA = a.next;
	nodeX* tempB = b.next;
	while (tempA != nullptr) {
		int tempBac = (*tempA).bac;
		(*tempA).num += findBac(tempBac, &b);
		tempA = (*tempA).nextNode;
	}
}
void printFunc(List& a) {
	nodeX* temp = a.next;
	while (temp != nullptr) {
		std::cout << (*temp).num << "x^" << (*temp).bac << " ";
		temp = (*temp).nextNode;
	}
}
#endif // !MATHPROBLEM_H
