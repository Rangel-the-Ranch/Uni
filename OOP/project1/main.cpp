#include<iostream>
#include"book.h"
#include"book.cpp"

int main(){
    
    book A("Title","Ivan","txt.txt","test 1 2 3" ,4.2);
    book V(A);
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
    */
}