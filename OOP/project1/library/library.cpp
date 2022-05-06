#include<cstring>

void library::free(){
    delete []books;
}
void library::resize(){
    this->sizeOfLibrary = this->sizeOfLibrary*2;
    book* buffer = new book [this->sizeOfLibrary];
    for(int i = 0 ; i<numberOfBooks ; i++){
        buffer[i] = this->books[i];
    }
    free();
    this->books = buffer;
    buffer = nullptr;
}
const size_t library::getNumberOfBooks()const{
    return this->numberOfBooks;
}
const size_t library::getSizeOfLibrary()const{
    return this->sizeOfLibrary;
}
const book* library::getBookArr()const{
    return books;
}

void library::copyFrom(const library& other){
    this->numberOfBooks = other.getNumberOfBooks();
    this->sizeOfLibrary = other.getSizeOfLibrary();
    
    //this->books = new book [ this->sizeOfLibrary ];



}

library::library(){
    this->books = new book [ this->DEFAULT_STARTING_LIB_SIZE ];
    this->numberOfBooks = 0;
    this->sizeOfLibrary = DEFAULT_STARTING_LIB_SIZE; 
}
library::~library(){
    free();
}
library::library(const library& other){
    copyFrom(other);
}
library& library::operator=(const library& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

void library::addBook(const book& newBook){
    
    if(this->numberOfBooks >= this->sizeOfLibrary){
        resize();
        this->books[numberOfBooks] = newBook;
        this->numberOfBooks++;

    }else{
        this->books[numberOfBooks] = newBook;
        this->numberOfBooks++;
    }
}

void library::removeBook(const unsigned int index){
    if( index>=this->numberOfBooks ){
        std::cout<<"book does not exist \n";
    }else{
        this->numberOfBooks--;
        removeFileDecision(index);
        for(int i = index; i < this->numberOfBooks; i++){
            this->books[i] = this->books[i+1];
            
        }
        std::cout<<"The book is unlisted"<<std::endl;
    }
}
void library::removeFileDecision(const unsigned int index){
    bool decision;
    std::cout<<"Do you want to remove: "<<books[index].getLocation() <<std::endl;
    std::cin>>decision;
    if(decision == true){
        this->books[index].removeFile();
    }else{
        std::cout<<"file not removed\n";
    }
}

void library::listBooks()const{
    for(size_t i = 0 ; i < this->numberOfBooks; i++){
        std::cout<<this->books[i].getTitle()<<" ";
        std::cout<<this->books[i].getAuthor()<<" ";
        //std::cout<<this->books[i].getLocation()<<" ";
        std::cout<<this->books[i].getIsbn();
        std::cout<<std::endl;
    }
}
/*
void library::listByRanking()const{
    
    for(size_t i = 0 ; i < this->numberOfBooks; i++){
        std::cout<<this->books[i].getTitle()<<" ";
        std::cout<<this->books[i].getAuthor()<<" ";
        std::cout<<this->books[i].getIsbn();
        std::cout<<std::endl;
    }
}
*/


void library::readBook(const unsigned int index)const{
    //std::cout<<numberOfBooks;
    if(index + 1 <= numberOfBooks){
        this->books[index].printBook();
    }else{
        std::cout<<"this book does not exist\n";//<<std::endl;
    }
}
void library::readBookBySentences(const unsigned int index)const{
    if(index + 1 <= numberOfBooks){
        this->books[index].printBySentence();
    }else{
        std::cout<<"this book does not exist\n";//<<std::endl;
    }
}
void library::readBookByCharactersInPage(const unsigned int index , const unsigned int symbolsInPage)const{
    if(index + 1 <= numberOfBooks){
        this->books[index].printByNcharacters(symbolsInPage);
    }else{
        std::cout<<"this book does not exist\n";//<<std::endl;
    }
}

void library::readBookByPage(const unsigned int index , const unsigned int linesInPage)const{
    if(index + 1 <= numberOfBooks){
        this->books[index].printByPage(linesInPage);
    }else{
        std::cout<<"this book does not exist\n";//<<std::endl;
    }
}

void library::printComandsForUser()const{
    std::cout<<"1.Book list"<<std::endl;
    std::cout<<"2.Search"<<std::endl;
}
void library::printComandsForAdmin()const{
    std::cout<<"1.Book list"<<std::endl;
    std::cout<<"2.Search"<<std::endl;
    std::cout<<"3.Add book"<<std::endl;
}
void library::printBookProfileUser(const unsigned int index)const{
    std::cout<<"Title: "<<books[index].getTitle()<<std::endl;
    std::cout<<"Author: "<<books[index].getAuthor()<<std::endl;
    std::cout<<"Rating: "<<books[index].getRating()<<std::endl;
    std::cout<<"ISBN: "<<books[index].getIsbn()<<std::endl;
    std::cout<<std::endl;
    std::cout<<books[index].getDescription()<<std::endl;
  
    std::cout<<"0.Back"<<std::endl;
    std::cout<<"1.Read"<<std::endl;
    
}
void library::printBookProfileAdmin(const unsigned int index)const{
    std::cout<<"Title: "<<books[index].getTitle()<<std::endl;
    std::cout<<"Author: "<<books[index].getAuthor()<<std::endl;
    std::cout<<"Rating: "<<books[index].getRating()<<std::endl;
    std::cout<<"ISBN: "<<books[index].getIsbn()<<std::endl;
    std::cout<<"location: "<<books[index].getLocation()<<std::endl;
    std::cout<<std::endl;
    std::cout<<books[index].getDescription()<<std::endl;

    std::cout<<"0.Back"<<std::endl;
    std::cout<<"1.Read"<<std::endl;
    std::cout<<"2.Remove"<<std::endl;
}
void library::printReadingOptions()const{
    std::cout<<"1.Read (normaly..?)"<<std::endl;
    std::cout<<"2.Read sentence by sentency"<<std::endl;
    std::cout<<"3.Read by N amount of lines on a page"<<std::endl;
    std::cout<<"4.Read by N amount of symbols on a page"<<std::endl;

    std::cout<<"0.Back"<<std::endl;
}
void library::menu(){

}
