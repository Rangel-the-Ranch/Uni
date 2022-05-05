#pragma once
//#include"book.cpp"
#include<fstream>
class book{
    private:
        char* title;
        char* author;
        char* location;
        char* description;
        double rating;
        char* isbn;
        //int sizeOfFile;
        //static const  char* defaultParameter;

        void free();
        double  validRatingConverter(double rate)const;
        bool validIsbn(const char* checkIsbn)const;
        size_t getFileSize(std::ifstream& iFile)const;

        void copyFrom(const book& other);
    public:

        book& operator=(const book& other);

        book(const book& other);
        book(const char* newTitle , const char* newAuthor, const char* newLocation , const char* newDescription, double newRating, const char* newIsbn);
        book();
        ~book();

        void setTitle(const char* newTitle);
        void setAuthor(const char* newAuthor);
        void setLocation(const char* newLocation);
        void setDescription(const char* newDescription);
        void setRating(const double newRating);
        void setIsbn(const char* newIsbn);
        const char* getTitle()const;
        const char* getAuthor()const;
        const char* getLocation()const;
        const char* getDescription()const;
        double getRating()const;
        const char* getIsbn()const;

        void printBook()const;
        

        
};