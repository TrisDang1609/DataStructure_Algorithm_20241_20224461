#include<iostream>

#include"mathProblem.h"

int main() {
	hXfunc.next = nullptr;
	gXfunc.next = nullptr;
	int hN, gN;
	std::cin >> hN >> gN;
	buildXfunc(hXfunc, hN);
	sortFunc(hXfunc);
	buildXfunc(gXfunc, gN);
	sortFunc(gXfunc);
	addFunc(hXfunc, gXfunc);
	printFunc(hXfunc);
}