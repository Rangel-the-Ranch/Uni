#include<iostream>
#include<fstream>
#include<cstring>


#include"library/library.h"
#include"library/library.cpp"



int main(){
    user A("IvanDebelan" , "password" , 1);
    user B("misho","123456",0);

    book Bone("B1","Ivan","books/book1.txt","tova e purvata knniga",1.11,"11111111");
    book Btwo("B2","Gosho","books/book2.txt","tova e vtorata knniga",2.2,"2222222");
    book Bthree("B3","Petur","books/book3.txt","tova e tretata knniga",3.333,"3333333333");
    book Bfour("B4","Ivan","books/book4.txt","tova e chetvurta knniga",4.444,"44444444444");
    book Bfive("B5","don","books/book5.txt","tova e peta knniga",5.555,"5555555");

    library lib;

    lib.addBook(Bone);
    lib.addBook(Btwo);
    lib.addBook(Bthree);
    lib.addBook(Bfour);
    lib.addBook(Bfive);

    lib.menu(A);
    //lib.listBooks();

    
   //////////////////////////////////////////
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