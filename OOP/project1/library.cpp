//#include<cstring>

void library::free(){
    delete []books;
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

    }else{
        this->books[numberOfBooks] = newBook;
        this->numberOfBooks++;
    }
}