#include<iostream>
#include<fstream>
#include<cstring>


#include"library/library.h"
#include"library/library.cpp"



int main(){
    user A("IvanDebelan" , "password" , 1);
    user B("misho","123456",0);

    book Bone("dddwpoigjn","Ivan","books/book1.txt","Ctova e purvata",2.7,"11111111");
    book Btwo("cccowig","Gosho","books/book2.txt","Atova e vtorata",3.14,"2222222");
    book Bthree("eeewogirwg","Petur","books/book3.txt","Btova e tretata",3,"3333333333");
    book Bfour("aaavfsorjinv","Ivan","books/book4.txt","Gtova e chetvurta",5.5,"44444444444");
    book Bfive("bbblewrjgnb","don","books/book5.txt","Ctova e peta",4.2,"5555555");

    library lib;

    lib.addBook(Bone);
    lib.addBook(Btwo);
    lib.addBook(Bthree);
    lib.addBook(Bfour);
    lib.addBook(Bfive);

    lib.menu(A);

    //lib.titleSort(false);
    //lib.rankingSort(true);
    
    //lib.listBooks();
    
    //lib.readingMenu(A , 1);
    //lib.swapIndex(1,2);
    //lib.rankingSort();
    //lib.listBooks();
    //std::cout<<lib.getInput();
    
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