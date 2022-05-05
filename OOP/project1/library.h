#pragma once

#include"book.h"
#include"book.cpp"

class library{
    private:
        book* books;
        size_t numberOfBooks;
        size_t sizeOfLibrary;
        static const size_t DEFAULT_STARTING_LIB_SIZE = 16;

        void free();
        void resize();
    public:
        library();
        ~library();

        void addBook(const book& newBook);
        void listBooks()const;
        void readBook(const unsigned int index)const;
        
};