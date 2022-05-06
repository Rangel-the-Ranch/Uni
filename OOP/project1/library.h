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
        void removeFileDecision(const unsigned int index);
    public:

        library();
        ~library();

        void addBook(const book& newBook);
        void removeBook(const unsigned int index);

        void listBooks()const;
        void listByRakingAc()const;
        void listByRatingDec()const;

        void readBook(const unsigned int index)const;
        void readBookBySentences(const unsigned int index)const;
        void readBookByCharactersInPage(const unsigned int index , const unsigned int symbolsInPage)const;
        void readBookByPage(const unsigned int index , const unsigned int linesInPage)const;
};