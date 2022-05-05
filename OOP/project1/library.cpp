//#include<cstring>

void library::free(){
    delete []books;
}
void library::resize(){

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

void library::listBooks()const{
    for(size_t i = 0 ; i < this->numberOfBooks; i++){
        std::cout<<books[i].getTitle()<<" ";
        std::cout<<books[i].getAuthor()<<" ";
        std::cout<<books[i].getIsbn();
        std::cout<<std::endl;
    }
}

void library::readBook(const unsigned int index)const{
    //std::cout<<numberOfBooks;
    if(index + 1 <= numberOfBooks){
        books[index].printBook();
    }else{
        std::cout<<"this book does not exist\n";//<<std::endl;
    }
}