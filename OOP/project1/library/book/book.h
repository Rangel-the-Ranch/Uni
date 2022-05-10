#pragma once

class book{
    private:
        char* title;
        char* author;
        char* location;
        char* description;
        double rating;
        char* isbn;
        static const unsigned int LINES_BETWEEN_PAGES = 3;
        static const unsigned int MAX_SYMBOLS_IN_LINE = 1024;


        void free();
        const double  validRatingConverter(const double rate)const;
        const bool validIsbn(const char* checkIsbn)const;
        const size_t getFileSize(std::ifstream& iFile)const;
        void newPageSpacer()const;
        const bool isEndSymbol(const char symbol)const;
        

        void copyFrom(const book& other);
        //void removeFile();
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
        const double getRating()const;
        const char* getRatingAsString()const;
        const char* getIsbn()const;

        void removeFile();

        void printBook()const;
        void printByPage(const unsigned int linesInPage)const;
        void printByNcharacters(const unsigned int symbolsInPage)const;
        void printBySentence()const;

        void createBookInfoFile()const;

        
};