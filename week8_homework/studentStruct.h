
#ifndef STUDENT_STRUCT_H
#define STUDENT_STRUCT_H
// Copy n characters from b to a
void stringCopy(char* a, char* b, int n) {
	for (int i = 0; i < n; i++) {
		*(a + i) = *(b + i);
	}
}
struct DATE {
	int day;
	int month;
	int year;
	DATE* nextNode;
	DATE(int _day, int _month, int _year) {
		day = _day;
		month = _month;
		year = _year;
		nextNode = nullptr;
	}
};

// Copy date b to a
void copyDate(DATE& a, DATE b) {
	a.day = b.day;
	a.month = b.month;
	a.year = b.year;
}
// compare two dates
bool compareDate(DATE *a, DATE *b) {
	if ((*a).day != (*b).day) return false;
	if ((*a).month != (*b).month) return false;
	if ((*a).year != (*b).year) return false;
	return true;
}
struct STUDENT {
	char svID[10];
	char name[30];
	bool gender;
	DATE dob;
	char address[50];
	char major[30];
	char Kyear[5];
	STUDENT* nextStudent;
	STUDENT(char _svID[10], char _name[30], bool _gender, DATE _dob, char _address[50], char _major[30], char _Kyear[5]) {
		stringCopy(svID, _svID, 10);
		stringCopy(name, _name, 30);
		gender = _gender;
		copyDate(dob, _dob);
		stringCopy(address, _address, 50);
		stringCopy(major, _major, 30);
		stringCopy(Kyear, _Kyear, 5);
		nextStudent = nullptr;
	}
};
#endif // !STUDENT_STRUCT_H

