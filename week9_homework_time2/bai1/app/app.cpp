#include<iostream>

#include"bai1/source/baseFunc.h"

int main(){
    NODEFILE Doucument;
    initNODEFILE(Doucument);
    int n;
    std::cout << "Enter number of files: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) appendNODE(Doucument);
    printNODEFILE(Doucument);
    std::cout << "Sum size of files: " << sumSize(Doucument) << "Mb" << std::endl;
    deleteUntil32GBList(Doucument);
}