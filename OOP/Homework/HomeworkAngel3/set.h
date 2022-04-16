#include<iostream>
#include<cstring>

class Set {
    private:
        unsigned int numberOfWords = 0;
        int* lenghtOfWord = new int [numberOfWords + 1];
        char* words = new char [numberOfWords + 1];

        void addWord(char* word);
        
    public:
        Set();
        
};