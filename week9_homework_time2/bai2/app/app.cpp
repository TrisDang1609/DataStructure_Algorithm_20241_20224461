#include "source/wordLinkList.h"
#include<iostream>
#define LEN 10000
int main(){
    char temp[LEN];
    int tempSize = 0;
    WORDLIST List;
    initWORDLIST(List);
    char sentence[LEN];
    std::cin.getline(sentence, LEN);
    // cut the sentence into single words to input into the list
    for (int i = 0; i < LEN; i++){
        if(sentence[i] == ' ' || sentence[i] == '\0'){
            WORD *newWord = new WORD(temp);
            appendWORD(List, newWord);
            tempSize = 0;
            if(sentence[i] == '\0') break;
        } else {
            temp[tempSize] = sentence[i];
            tempSize++;
        }
    }
    WORD *maxWord = List.next;
    int max = maxCount(List, maxWord);
    std::cout << "Word: " << maxWord->word << " has the most appearance with " << max << " times" << std::endl;
    std::cout << "List of words: " << countWordInList(List) << std::endl;
}