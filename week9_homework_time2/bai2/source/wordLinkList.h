#ifndef WORLDLINKLIST_H
#define WORLDLINKLIST_H

void charCopy(char *dest, char *src, int n);
struct WORD{
    char word[100];
    int count = 1;
    WORD *next;
    WORD(char _word[100]){
        charCopy(word, _word, 100);
        next = nullptr;
    }
};
struct WORDLIST{
    WORD *next;
};
void initWORDLIST(WORDLIST &List);
void appendWORD(WORDLIST &List, WORD *newWord);
void updateCount(WORDLIST &List, char word[100]);
int maxCount(WORDLIST &List, WORD *maxWord);
void deleteWORD(WORDLIST &List, WORD *word);
void deleteRepeatedWord(WORDLIST &List);
int countWordInList(WORDLIST &List);
#endif // WORLDLINKLIST_H