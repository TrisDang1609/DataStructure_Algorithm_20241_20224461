// in this file, i choose a default unit of size is Mb

#ifndef BASEFUNC_H
#define BASEFUNC_H
int clkDef = 0;
void charCopy(char *dest, char *src, int n);
// DATE struct & its functions
struct DATE{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    DATE() : year(0), month(0), day(0), hour(0), minute(0), second(0){}
    DATE(int _year, int _month, int _day, int _hour, int _minute, int _second){
        year = _year;
        month = _month;
        day = _day;
        hour = _hour;
        minute = _minute;
        second = _second;
    }
};
void dateCopy(DATE &dest, DATE &src);
int dateCmp(DATE &date1, DATE &date2);

// NODE struct & its functions
struct NODE{
    char name[100];
    float size;
    DATE timeInput;
    NODE *nextFile;
    NODE(char _name[100], float _size, DATE _timeInput){
        charCopy(name, _name, 100);
        size = _size;
        dateCopy(timeInput, _timeInput);
        nextFile = nullptr;
    }
};
void printNODE(NODE *file);

// NODEFILE struct & its functions
struct NODEFILE{
    NODE *next;
};
void initNODEFILE(NODEFILE &List);
void appendNODE(NODEFILE &List);
void printNODEFILE(NODEFILE &List);
int sumSize(NODEFILE &List);
int maxSizeofFile(NODEFILE &List);
void moveFile(NODEFILE &List1, NODEFILE &List2, NODE *file);
void appendNODE(NODEFILE &List, NODE *newNode);
void deleteNode(NODEFILE &List, NODE *file);
void deleteUntil32GBList(NODEFILE &List);
#endif // BASEFUNC_H