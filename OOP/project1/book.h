#pragma once
//#include"book.cpp"

class book{
    private:
        char* title;
        char* author;
        char* location;
        char* description;
        double rating;
        
        //static const  char* defaultParameter;

        void free();
        double  validRatingConverter(double rate);
    
        void copyFrom(const book& other);
    public:

        book& operator=(const book& other);
        book(const book& other);

        book(const char* newTitle , const char* newAuthor, const char* newLocation , const char* newDescription, double newRating);
        book();
        ~book();

        void setTitle(const char* newTitle);
        void setAuthor(const char* newAuthor);
        void setLocation(const char* newLocation);
        void setDescription(const char* newDescription);
        void setRating(double newRating);
        const char* getTitle()const;
        const char* getAuthor()const;
        const char* getLocation()const;
        const char* getDescription()const;
        double getRating()const;
        

        
};