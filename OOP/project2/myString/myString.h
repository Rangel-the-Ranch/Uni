#pragma once
#include <iostream>
#include<cstring>


class myString{
    public:

        myString();
        myString(const char* newString);
        myString(const myString& other);
        myString(myString&& other);
        myString(size_t number);

        ~myString();

        size_t getSize()const;
        const char* get()const;
        bool isEmpty()const;

        myString& operator=(const myString& other);
        myString& operator=(myString&& other);
        myString& operator+=(const myString& other);
    private:
        char* str;
        size_t size;

        void copyFrom(const myString& other);
        void free();
        void concatFrom(const myString& other);
       
       
};
bool operator==(const myString& left , const myString& right);