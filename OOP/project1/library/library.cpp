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
void library::swapIndex(const size_t A ,const size_t B){
    const book temp = books[A];
    books[A] = books[B];
    books[B] = temp;
}

void library::listBooks()const{
    for(size_t i = 0 ; i < this->numberOfBooks; i++){
        std::cout<<i+1<<". ";
        std::cout<<this->books[i].getTitle()<<", ";
        std::cout<<this->books[i].getAuthor()<<", ";
        //std::cout<<this->books[i].getLocation()<<", ";
        std::cout<<"rating: "<<books[i].getRating()<<", ";
        std::cout<<this->books[i].getIsbn();
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}

void library::rankingSort(const bool highestToLowest){
    if(highestToLowest == true){
        int remainingNumberOfBooks = this->numberOfBooks;
        while(remainingNumberOfBooks > 0){
            double highest = 0;
            size_t highestIndex;
            for(int i=0; i<remainingNumberOfBooks; i++){    
                if( this->books[i].getRating() > highest){
                    highest = this->books[i].getRating();
                    highestIndex = i;
                }
            }
            swapIndex(remainingNumberOfBooks-1 , highestIndex);
            remainingNumberOfBooks--;
        }  
    }else{
        int remainingNumberOfBooks = this->numberOfBooks;
        while(remainingNumberOfBooks > 0){
            double lowest = 5;
            size_t lowestIndex;
            for(int i=0; i<remainingNumberOfBooks; i++){    
                if( this->books[i].getRating() < lowest){
                    lowest = this->books[i].getRating();
                    lowestIndex = i;
                }
            }
            swapIndex(remainingNumberOfBooks-1 , lowestIndex);
            remainingNumberOfBooks--;
        } 
    }
}


void library::listByRatingAc()const{
    //book* sortArr = new book [numberOfBooks];
    

    for(size_t i = 0 ; i < this->numberOfBooks; i++){
        std::cout<<this->books[i].getTitle()<<" ";
        std::cout<<this->books[i].getAuthor()<<" ";
        std::cout<<"rating: "<<books[i].getRating()<<" ";
        std::cout<<this->books[i].getIsbn();
        std::cout<<std::endl;
        std::cout<<std::endl;
    }
}



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

const int library::validInputConverter(const int input , const unsigned int numberOfCommands)const{
    if(input >= 0 || input <= numberOfCommands){
        return input;
    }else{
        return -1;
    }
}

const int library::getInput()const{
    char input[MAX_INPUT_SIZE];
    std::cin>>input;
    const size_t inputLen = strlen(input); 
    int command=0;
    int pow = 1;
    for(int i=inputLen-1; i>=0; i--){
        if(input[i] != '0' && input[i] != '1' && input[i] != '2' &&
            input[i] != '3' && input[i] != '4' && input[i] != '5' &&
            input[i] != '6' && input[i] != '7' && input[i] != '8' &&
            input[i] != '9'){
                return -1;
        }
        if(input[i] == '0' ){
                command = command+0*pow;
        }
        if(input[i] == '1' ){
                command = command+1*pow;
        }
        if(input[i] == '2' ){
                command = command+2*pow;
        }
        if(input[i] == '3' ){
                command = command+3*pow;
        }
        if(input[i] == '4' ){
                command = command+4*pow;
        }
        if(input[i] == '5' ){
                command = command+5*pow;
        }
        if(input[i] == '6' ){
                command = command+6*pow;
        }
        if(input[i] == '7' ){
                command = command+7*pow;
        }
        if(input[i] == '8' ){
                command = command+8*pow;
        }
        if(input[i] == '9' ){
                command = command+9*pow;
        }
        pow = pow*10;
    }
    return command;
    
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
void library::printListMenu()const{
    std::cout<<"1.List by ranking"<<std::endl;
    std::cout<<"2.List by title"<<std::endl;
    std::cout<<"3.List by author"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"0.Back"<<std::endl;
}
void library::menu(const user& person){
    if(person.getIsAdmin() == true){
        printComandsForAdmin();
        int input = getInput();
        int convInput = validInputConverter(input , 3);
        if( convInput == -1){
            std::cout<<"Invalid command!"<<std::endl;
        }else{
            if(convInput == 0){
                return;
                std::cout<<"WIP\n";
            }
            if(convInput == 1){
                listMenu(person);
            }
            if(convInput == 2){
                std::cout<<"WIP\n";
            }
            if(convInput == 3){
                addBookMenu(person);
            }
        }
    }else{
        printComandsForUser();
        int input = getInput();
        int convInput = validInputConverter(input , 2);
        if( convInput == -1){
            std::cout<<"Invalid command!"<<std::endl;
        }else{
            if(convInput == 0){
                return;
                std::cout<<"WIP\n";
            }
            if(convInput == 1){
                listMenu(person);
            }
            if(convInput == 2){
                std::cout<<"WIP\n";
            }
        }
    }
    menu(person);
}
void library::addBookMenu(const user& person){
    char title[MAX_INPUT_SIZE];
    char author[MAX_INPUT_SIZE];
    char ISNB [MAX_INPUT_SIZE];
    char location[MAX_INPUT_SIZE];
    char description[MAX_INPUT_SIZE];
    double rating;
    std::cout<<"Title: ";
    std::cin>>title;
    std::cout<<"Author: ";
    std::cin>>author;
    std::cout<<"ISNB: ";
    std::cin>>ISNB;
    std::cout<<"Location: ";
    std::cin>>location;
    std::cout<<"Rating: ";
    std::cin>>rating;
    std::cout<<"Description: ";
    std::cin>>description;
    book temp(title,author,location,description,rating,ISNB);
    addBook(temp);
    std::cout<<"Book added succsefuly"<<std::endl;

}
void library::listMenu(const user& person){
    printListMenu();
    char input = getInput();
    int convInput = validInputConverter(input , 3);
    if( convInput == -1){
        std::cout<<"Invalid command:"<<std::endl;
        listMenu(person);
    }else{
        if(convInput == 0){
                return;
            }
            if(convInput == 1){
                bool highestToLowest;
                std::cout<<"Highest to lowest? (0/1) : \n";
                
                int input = getInput();
                input = validInputConverter(input , 1);
                if(input == -1){
                    std::cout<<"Invalid input"<<std::endl;
                    listMenu(person);
                }

                if(input == true){
                    rankingSort(true);
                    std::cout<<"0.Back"<<std::endl;
                    listBooks();
                    selectBookIndex(person);
                }else{
                    rankingSort(false);
                    std::cout<<"0.Back"<<std::endl;
                    listBooks();  
                    selectBookIndex(person);
                }
                
                
            }
            if(convInput == 2){
                bool AtoZ;
                std::cout<<"A to Z? (if 0 -> Z to A) (0/1) : \n";
                int input = getInput();
                input = validInputConverter(input ,1);
                if(input == -1){
                    std::cout<<"Invalid input"<<std::endl;
                    listMenu(person);
                }
                if(input == 0){
                    AtoZ = false;
                }
                if(input == 1){
                    AtoZ = true;
                }

                

            }
            if(convInput == 3){
                std::cout<<"WIP\n";
            }
    }
    //menu(person);
}
/*
void library::titleSort(const bool AtoZ){
    if(AtoZ == true){
        int remainingNumberOfBooks = this->numberOfBooks;
        while(remainingNumberOfBooks > 0){
            char lowest = 256;
            size_t lowestIndex;
            for(int i=0;i<remainingNumberOfBooks;i++){
                if(this-<books[i].getTitle){
                    lowest
                }
            }
        }
    }else{

    }
}*/

void library::selectBookIndex(const user& person){
    int input =validInputConverter( getInput() , numberOfBooks-1);
    if(input == 0){
        return;
    }
    if(person.getIsAdmin() == true){
        printBookProfileAdmin(input-1);
        int secInput = validInputConverter(getInput() , 2);
        if(input == -1){
            std::cout<<"Invalid input"<<std::endl;
            selectBookIndex(person);
        }
        if(input == 0){
            return;
        }
        if(secInput == 1){
            books[input-1].printBook();
        }
        if(secInput == 2){
            removeBook(input-1);
        }

    }else{
        printBookProfileUser(input-1);
        int secInput = validInputConverter(getInput() , 1);
        if(input == -1){
            std::cout<<"Invalid input"<<std::endl;
            selectBookIndex(person);
        }
        if(input == 0){
            return;
        }
        if(secInput == 1){
            readingMenu(person , input-1);
        }
    }
}
void library::readingMenu(const user& person ,const size_t bookIndex){
    printReadingOptions();
    int input = validInputConverter(getInput() , 4);
    if(input == -1){
        std::cout<<"Invalid input"<<std::endl;
        readingMenu(person,bookIndex);
    }
    if(input == 0){
        return;
    }
    if(input == 1){
        books[bookIndex].printBook();
    }
    if(input == 2){
        books[bookIndex].printBySentence();
    }
    if(input == 3){
        std::cout<<"Lines on page: ";
        int secInput = getInput();
        if(secInput == -1){
            std::cout<<"Invalid input"<<std::endl;
            readingMenu(person , bookIndex);
        }else{
            books[bookIndex].printByPage(secInput);
        }
    }
    if(input == 4){
        std::cout<<"Characters on page: ";
        int secInput = getInput();
        if(secInput == -1){
            std::cout<<"Invalid input"<<std::endl;
            readingMenu(person , bookIndex);
        }else{
            books[bookIndex].printByNcharacters(secInput);
        }
    }
}
