#include<iostream>

#ifndef SINHVIEN_H
#define SINHVIEN_H
struct DATE{
    int day;
    int month;
    int year;
};

struct student{
    char svID[10];
    char name[30];
    //default set: True -> Male, False -> Female
    bool gender;
    DATE birthday;
    char address[50];
    int grade;
    // liên khoá năm bao nhiêu, em không biết tiếng anh từ này  
    int Kyear;
};
void initStudent(student &sv){
    // define all the nessessary variables
    char _svID[10];
    char _name[30];
    bool _gender;
    DATE _birthday;
    char _address[50];
    int _grade;
    int _Kyear;

    // input the necessary information
    std::cin.get(_svID, 10);
    std::cin.ignore();
    std::cin.get(_name, 30);
    std::cout << "Gender set: Male -> 1, Female -> 0" << std::endl;
    std::cin >> _gender;
    std::cin >> _birthday.day;
    std::cin >> _birthday.month;
    std::cin >> _birthday.year;
    std::cin.get(_address, 50);
    std::cin >> _grade;
    std::cin >> _Kyear;
    // get the value from the user
    for (int i = 0; i < 10; i++)
    {
        sv.svID[i] = _svID[i];
    }
    for(int i = 0; i < 30; i++){
        sv.name[i] = _name[i];
    }
    sv.gender = _gender;
    sv.birthday.day = _birthday.day;
    sv.birthday.month = _birthday.month;
    sv.birthday.year = _birthday.year;
    for(int i = 0; i < 50; i++){
        sv.address[i] = _address[i];
    }
    sv.grade = _grade;
    sv.Kyear = _Kyear;
}   

void printStudent(student sv){
    std::cout << "Student ID: " << sv.svID << std::endl;
    std::cout << "Name: " << sv.name << std::endl;
    if(sv.gender){
        std::cout << "Gender: Male" << std::endl;
    } else std::cout << "Gender: Female" << std::endl;
    std::cout << "Birthday: " << sv.birthday.day << "/" << sv.birthday.month << "/" << sv.birthday.year << std::endl;
    std::cout << "Address: " << sv.address << std::endl;
    std::cout << "Grade: " << sv.grade << std::endl;
    std::cout << "Lien khoa: " << sv.Kyear << std::endl;
}
#endif // SINHVIEN_H