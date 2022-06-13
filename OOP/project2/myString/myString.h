#pragma once
#include<cstring>

class myString{
    private:
        char* str;
        size_t size;

        void copyFrom(const myString& other);
        void free();
        void concatFrom(const myString& other);
    public:

        myString();
        myString(const char* newString);
        myString(const myString& other);
        myString(myString&& other);
        myString(size_t number);

        ~myString();

        size_t getSize()const;
        const char* get()const;

        myString& operator=(const myString& other);
        myString& operator=(myString&& other);
        myString& operator+=(const myString& other);
        
};