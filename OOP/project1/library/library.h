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
        static const size_t MAX_INPUT_SIZE = 16;

        void free();
        void resize();
        void removeFileDecision(const unsigned int index);

        const int validInputConverter(const char* input , const unsigned int numberOfCommands)const;
        void swapIndex(const size_t A,const size_t B);
        void rankingSort(const bool highestToLowest);
        void titleSort(const bool AtoZ);
        void authorSort(const bool AtoZ);
        
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
        
        //void rankingSort(const bool highestToLowest);
        //void titleSort(const bool AtoZ);

        void listBooks()const;
        void listByRatingAc()const;
        void listByRatingDec()const;

        void readBook(const unsigned int index)const;
        void readBookBySentences(const unsigned int index)const;
        void readBookByCharactersInPage(const unsigned int index , const unsigned int symbolsInPage)const;
        void readBookByPage(const unsigned int index , const unsigned int linesInPage)const;

        //void searchByIsbn()const;

        void menu(const user& person);
        void listMenu(const user& person);
        void selectBookIndex(const user& person);
        void selectSearchedBookIndex(const user& person, const size_t input);
        void readingMenu(const user& person ,const size_t boolIndex);
        void addBookMenu(const user& person);
        void searchMenu(const user& person);

        const int validInputConverter(const int input , const unsigned int numberOfCommands)const;
        const int getInput()const;
        char* getInputString()const;

        void printComandsForUser()const;
        void printComandsForAdmin()const;
        void printBookProfileAdmin(const unsigned int index)const;
        void printBookProfileUser(const unsigned int index)const;
        void printReadingOptions()const;
        void printListMenu()const;
        void searchMenu();


};