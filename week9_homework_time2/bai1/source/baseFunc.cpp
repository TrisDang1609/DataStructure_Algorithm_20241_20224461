#include"baseFunc.h"
#include<iostream>

void charCopy(char *dest, char *src, int n){
    for(int i = 0; i < n; i++){
        *(dest + i) = *(src + i);
    }
}
// DATE functions
void dateCopy(DATE &dest, DATE &src){
    dest.year = src.year;
    dest.month = src.month;
    dest.day = src.day;
    dest.hour = src.hour;
    dest.minute = src.minute;
    dest.second = src.second;
}
inline int cmpInt(int& a, int &b){
    if(a > b)
        return 1;
    return -1;
}
int dateCmp(DATE &date1, DATE &date2){
    if(date1.year != date2.year)
        return cmpInt(date1.year, date2.year);
    else {
        if(date1.month != date2.month)
            return cmpInt(date1.month, date2.month);
        else {
            if(date1.day != date2.day)
                return cmpInt(date1.day, date2.day);
            else {
                if(date1.hour != date2.hour)
                    return cmpInt(date1.hour, date2.hour);
                else {
                    if(date1.minute != date2.minute)
                        return cmpInt(date1.minute, date2.minute);
                    else {
                        if(date1.second != date2.second)
                            return cmpInt(date1.second, date2.second);
                        else
                            return 0;
                    }
                }
            }
        }
    }
}


// NODE functions
void printNODE(NODE *file){
    std::cout << "Name: " << file->name << std::endl;
    std::cout << "Size: " << file->size << "Mb" << std::endl;
    std::cout << "Time input: " << file->timeInput.year << "/" << file->timeInput.month << "/" << file->timeInput.day << " " << file->timeInput.hour << ":" << file->timeInput.minute << ":" << file->timeInput.second << std::endl;
}


// NODEFILE functions
void initNODEFILE(NODEFILE &List){
    List.next = nullptr;
}
void appendNODE(NODEFILE &List){
    char _name[100];
    float _size;
    int _year, _month, _day, _hour, _minute, _second;
    std::cin.ignore();
    std::cin.getline(_name, 100);
    std::cin >> _size;
    std::cin >> _year >> _month >> _day >> _hour >> _minute >> _second;
    DATE _timeInput(_year, _month, _day, _hour, _minute, _second);
    NODE *newNode = new NODE(_name, _size, _timeInput);
    if(List.next == nullptr){
        List.next = newNode;
    } else {
        NODE *temp = List.next;
        while(temp->nextFile != nullptr){
            if(dateCmp(temp->nextFile->timeInput, newNode->timeInput) == 1){
                newNode->nextFile = temp->nextFile;
                temp->nextFile = newNode;
                return;
            }
            temp = temp->nextFile;
        }
        temp->nextFile = newNode;
    }
}
void appendNODE(NODEFILE &List, NODE *newNode){
    if(List.next == nullptr){
        List.next = newNode;
    } else {
        NODE *temp = List.next;
        while(temp->nextFile != nullptr){
            if(dateCmp(temp->nextFile->timeInput, newNode->timeInput) == 1){
                newNode->nextFile = temp->nextFile;
                temp->nextFile = newNode;
                return;
            }
            temp = temp->nextFile;
        }
        temp->nextFile = newNode;
    }
}
void moveFile(NODEFILE &List1, NODEFILE &List2, NODE *file){
    appendNODE(List2, file);
    NODE *temp = List1.next;
    NODE *preTemp = temp;
    while(temp->nextFile != file){
        temp = temp->nextFile;
        preTemp = temp;
    }
    free(temp);
    preTemp->nextFile = file->nextFile;
    free(preTemp);
}
void printNODEFILE(NODEFILE &List){
    NODE *temp = List.next;
    while(temp != nullptr){
        printNODE(temp);
        temp = temp->nextFile;
    }
}
int sumSize(NODEFILE &List){
    NODE *temp = List.next;
    int sum = 0;
    while(temp != nullptr){
        sum += temp->size;
        temp = temp->nextFile;
    }
    return sum;
}
int maxSizeofFile(NODEFILE &List, NODE* &maxFile){
    NODE *temp = List.next;
    float max = 0;
    while(temp != nullptr){
        if(temp->size > max)
            max = temp->size;
        temp = temp->nextFile;
    }
    return max;
}
void deleteNode(NODEFILE &List, NODE *file){
    NODE *temp = List.next;
    NODE *preTemp = temp;
    while(temp->nextFile != file){
        temp = temp->nextFile;
        preTemp = temp;
    }
    free(temp);
    preTemp->nextFile = file->nextFile;
    free(preTemp);
}
void deleteUntil32GBList(NODEFILE &List){
    const float unitof32GB = 32.0 * 1024;
    while(sumSize(List) > unitof32GB){
        NODE *maxFile;
        float maxSize = maxSizeofFile(List, maxFile);
        std::cout << std::endl;
        std::cout << "Delete file: " << maxFile->name;
        deleteNode(List, maxFile);
    }
}