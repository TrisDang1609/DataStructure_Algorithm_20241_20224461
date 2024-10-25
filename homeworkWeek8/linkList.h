#include<iostream>

#include "sinhVien.h"

#ifndef LINKLIST_H
#define LINKLIST_H
struct Node {
    student Student;
    Node* next;
    Node(){
        initStudent(Student);
    }
};

class Linklist{
    private:
        Node* head;
        Node* tail;
    public:
        Linklist(){
            head = NULL;
            tail = NULL;
        }
        void append(){
            Node* temp = new Node();
            temp->next = NULL;
            if(head == NULL){
                head = temp;
                tail = temp;
            }else{
                tail->next = temp;
                tail = temp;
            }
        }
        void printList(){
            Node* temp = head;
            while(temp != NULL){
                printStudent(temp->Student);
            }
        }
};
#endif // LINKLIST_H