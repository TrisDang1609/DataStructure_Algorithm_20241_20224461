#include "wordLinkList.h"
#include <iostream>

void charCopy(char *dest, char *src, int n){
    for(int i = 0; i < n; i++){
        dest[i] = src[i];
        if(src[i] == '\0') break;
    }
}
bool charcmp(char *str1, char *str2){
    while(*str1 != '\0'){
        if(*str1 != *str2) return false;
    }
    return true;
}
// WORD functions
void printWORD(WORD *word){
    std::cout << "Word: " << word->word << " ";
}


// WORDLIST functions
void initWORDLIST(WORDLIST &List){
    List.next = nullptr;
}
void updateCount(WORDLIST &List, char word[100]){
    WORD *temp = List.next;
    while(temp != nullptr){
        if(charcmp(temp->word, word) == 0){
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    WORD *newWord = new WORD(word);
}
void appendWORD(WORDLIST &List, WORD *newWord){
    if(List.next == nullptr){
        List.next = newWord;
    } else {
        WORD *temp = List.next;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newWord;
    }
    updateCount(List, newWord->word);
}
void printWORDLIST(WORDLIST &List){
    WORD *temp = List.next;
    while(temp != nullptr){
        printWORD(temp);
        temp = temp->next;
    }
    std::cout << std::endl;
}
int maxCount(WORDLIST &List, WORD *maxWord){
    WORD *temp = List.next;
    int max = 0;
    while(temp != nullptr){
        if(temp->count > max){
            max = temp->count;
            maxWord = temp;
        }
        temp = temp->next;
    }
    return max;
}
void deleteWORD(WORDLIST &List, WORD *word){
    WORD *temp = List.next;
    WORD *preTemp = temp;
    while(temp != word){
        preTemp = temp;
        temp = temp->next;
    }
    preTemp->next = temp->next;
    delete temp;
}
void deleteRepeatedWord(WORDLIST &List){
    WORD *temp = List.next;
    while(temp != nullptr){
        if((*temp).word == (*(temp->next)).word){
            deleteWORD(List, temp);
        }
    }
}
int countWordInList(WORDLIST &List){
    int count = 0;
    WORD *temp = List.next;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}