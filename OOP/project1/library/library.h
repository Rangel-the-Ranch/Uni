#pragma once

#include"book/book.h"
#include"book/book.cpp"

#include"user/user.h"
#include"user/user.cpp"

class library{
    private:
        book* books;
        size_t numberOfBooks;
        size_t sizeOfLibrary;
        static const size_t DEFAULT_STARTING_LIB_SIZE = 16;
        static const size_t MAX_INPUT_SIZE = 64;

        void free();
        void resize();
        void removeFileDecision(const unsigned int index);

        const int validInputConverter(const char* input , const unsigned int numberOfCommands)const;

        void copyFrom(const library& other);

    public:

        library();
        library(const library& other);
        ~library();
        library& operator=(const library& other);

        const size_t getNumberOfBooks()const;
        const size_t getSizeOfLibrary()const;
        const book* getBookArr()const;


        void addBook(const book& newBook);
        void removeBook(const unsigned int index);

        void listBooks()const;
        void listByRakingAc()const;
        void listByRatingDec()const;

        void readBook(const unsigned int index)const;
        void readBookBySentences(const unsigned int index)const;
        void readBookByCharactersInPage(const unsigned int index , const unsigned int symbolsInPage)const;
        void readBookByPage(const unsigned int index , const unsigned int linesInPage)const;

        //void searchByIsbn()const;

        void menu(const user& person);
        const int validInputConverter(const char input , const unsigned int numberOfCommands)const;
        const char getInput()const;

        void printComandsForUser()const;
        void printComandsForAdmin()const;
        void printBookProfileAdmin(const unsigned int index)const;
        void printBookProfileUser(const unsigned int index)const;
        void printReadingOptions()const;

};