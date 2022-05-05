#include<iostream>
//#include"book.h"
//#include"book.cpp"

#include"library.h"
#include"library.cpp"

int main(){
    book Bone("B1","Ivan","books/book1.txt","tova e purvata knniga",1.11,"11111111");
    book Btwo("B2","Gosho","books/book2.txt","tova e vtorata knniga",2.2,"2222222");
    book Bthree("B3","Petur","books/book3.txt","tova e tretata knniga",3.333,"3333333333");
    //Btwo.printBook();
    
    library lib;
    lib.addBook(Bone);
    lib.addBook(Btwo);
    lib.addBook(Bthree);
    
    //lib.listBooks();
    lib.readBook(2);

    //book A("Title","Ivan","txt.txt","test 1 2 3" ,4.2 ,"0000000000");
    //book V(A);
    //V = A;
    //A.setTitle("totle");
    //A.setAuthor("gosho");
    //A.setLocation("dat");
    //A.setDescription("nov test na kniga");
    
    //std::cout<<A.getTitle()<<std::endl;
    //std::cout<<A.getAuthor()<<std::endl;
    //std::cout<<A.getLocation()<<std::endl;
    //std::cout<<A.getDescription()<<std::endl;
    //std::cout<<A.getRating()<<std::endl;
    
    /*
    std::cout<<V.getTitle()<<std::endl;
    std::cout<<V.getAuthor()<<std::endl;
    std::cout<<V.getLocation()<<std::endl;
    std::cout<<V.getDescription()<<std::endl;
    std::cout<<V.getRating()<<std::endl;
    std::cout<<V.getIsbn()<<std::endl;
    */
}