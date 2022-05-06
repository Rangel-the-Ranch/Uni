//#include<cstring>

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

library::library(){
    this->books = new book [ this->DEFAULT_STARTING_LIB_SIZE ];
    this->numberOfBooks = 0;
    this->sizeOfLibrary = DEFAULT_STARTING_LIB_SIZE; 
}
library::~library(){
    free();
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

