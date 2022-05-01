
//#include<iostream>
#include<cstring>
//#include"book.h"
//using namespace std;

void book::free(){
    delete []this->title;
    delete []this->author;
    delete []this->location;
    delete []this->description;
}
double book::validRatingConverter(double rate){
    if(rate >= 1 && rate <= 5){
        return rate;
    }else{
        if(rate < 1){
            return 1;
        }
        if(rate > 5){
            return 5;
        }
    }
    return 1;
}
//###################
void book::copyFrom(const book& other){
    this->title = new char[ sizeof( other.getTitle() ) + 1];
    strcpy(this-> title, other.getTitle() );

    this->author = new char[ sizeof( other.getAuthor() ) + 1];
    strcpy(this->author , other.getAuthor() );

    this->location = new char[ sizeof( other.getLocation() ) + 1];
    strcpy(this->location , other.getLocation() );

    this->description = new char[ sizeof( other.getDescription() ) + 1];
    strcpy(this->description , other.getDescription() );

    setRating( other.getRating() );
}

book&  book::operator=(const book& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

book::book(const book& other){
    copyFrom(other);
}

//####################
book::book(const char* newTitle ,  const char* newAuthor, const char* newLocation , const char* newDescription , double newRating){
    this->title = new char[ sizeof(newTitle) + 1 ];
    strcpy(this->title , newTitle);

    this->author = new char[ sizeof(newAuthor) + 1 ];
    strcpy(this->author , newAuthor);

    this->location = new char[ sizeof(newLocation) + 1 ];
    strcpy(this->location , newLocation);

    this->description = new char[ sizeof(newDescription) + 1 ];
    strcpy(this->description , newDescription);
    
    setRating( newRating );
}
book::book(){
    /*
    this->title = new char[ sizeof("default") + 1 ];
    strcpy(this->title , "default");

    this->author = new char[ sizeof("default") + 1 ];
    strcpy(this->author , "default");

    this->location = new char[ sizeof("default") + 1 ];
    strcpy(this->location , "default");

    this->description = new char[ sizeof("default") + 1 ];
    strcpy(this->description , "default"); 
    */
   this->title = nullptr;
   this->author = nullptr;
   this->location = nullptr;
   this->description = nullptr;
   this->rating = 1;
}
book::~book(){
    free();
}
//#########################
void book::setTitle(const char* newTitle){
    delete []this->title;
    this->title = new char [ sizeof(newTitle) + 1 ];
    strcpy(this->title , newTitle);
}
const char* book::getTitle()const {
    return this->title;
}

void book::setAuthor(const char* newAuthor){
    delete []this->author;
    this->author = new char [ sizeof(newAuthor) + 1 ];
    strcpy(this->author , newAuthor);
}
const char* book::getAuthor()const {
    return this->author;
}

void book::setLocation(const char* newLocation){
    delete []this->location;
    this->location = new char [ sizeof(newLocation) + 1 ];
    strcpy(this->location , newLocation);
}
const char* book::getLocation()const {
    return this->location;
}

void book::setDescription(const char* newDescription){
    delete []this->description;
    this->description = new char [ sizeof(newDescription) + 1 ];
    strcpy(this->description , newDescription);
}
const char* book::getDescription()const {
    return this->description;
}
void book::setRating(double newRating){
    this->rating = validRatingConverter(newRating);
}
double book::getRating()const{
    return this->rating;
}
//#################
