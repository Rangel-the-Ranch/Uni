#include<iostream>
//#include"book.h"
//#include"book.cpp"

#include"library.h"
#include"library.cpp"


int main(){
    
    std::cout<<std::endl<<std::endl;
    book Bone("B1","Ivan","books/book1.txt","tova e purvata knniga",1.11,"11111111");
    book Btwo("B2","Gosho","books/book2.txt","tova e vtorata knniga",2.2,"2222222");
    book Bthree("B3","Petur","books/book3.txt","tova e tretata knniga",3.333,"3333333333");
    //Btwo.printByPage(10);

    library lib;
    lib.addBook(Bone);
    lib.addBook(Btwo);
    lib.addBook(Bthree);
    
    //lib.listBooks();
    //lib.readBook(2);
    //lib.readBookBySentences(2);
    //lib.readBookByCharactersInPage(1,100);
    //lib.readBookByPage(1,10);


   /*
   std::ifstream iBook( "books/book2.txt");
   if(iBook.is_open() != true ){
        std::cout<<"Cannot open file";
    }else{

        //char* text = new char[1000000000];
        char text[100];

        iBook.getline(text , 100);
        //std::getline(iBook,text);
        std::cout<<text;

        //delete []text;
        iBook.close();  

    }
    */
     
}