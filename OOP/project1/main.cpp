#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>

#include"user/user.h"
#include"user/user.cpp"

#include"library/library.h"
#include"library/library.cpp"

//rwtsz58y
const size_t MAX_INPUT = 100;
const user Guess("Guest" , "guest" , 0);

size_t numberOfUsers = 8;
user* users = new user[numberOfUsers];
library lib;


const user& login(){
    
    char input[MAX_INPUT];
    std::cout<<"Username: ";
    std::cin>>input;
    for(int i=0; i<numberOfUsers; i++ ){
        if( users[i].checkUsername(input) == true ){
            std::cout<<std::endl;
            std::cout<<"Password: ";

            char secInput[MAX_INPUT];
            std::cin>>secInput;

            if( users[i].checkPassword(secInput) == false ){

                std::cout<<"Wrong password!"<<std::endl;
                std::cout<<"Login as guest"<<std::endl;
                std::cout<<std::endl;
                return Guess;

            }else{
                std::cout<<"Welcome, "<<users[i].getUsername();
                std::cout<<std::endl;
                return users[i];
            }
        }       
    }
    std::cout<<"Username not found!"<<std::endl;
    std::cout<<"Login as guest"<<std::endl;
    std::cout<<std::endl;
    return Guess;
} 
int main(){

    users[0].setAll("Admin" , "admin" , 1);
    users[1].setAll("Ivan" , "123456" , 1);
    users[2].setAll("Nikolai","cubaBuba",0);
    users[3].setAll("Pesho","pesho123",0);
    users[4].setAll("Gosho" , "password" , 1);
    users[5].setAll("Mitko" , "000000" , 0);
    users[6].setAll("Ivo","ivo20102002",1);
    users[7].setAll("Papagal","wgopuwgog(^2871280g",0);

    //Guess.createUserFile();
    book Bone("midas","myth","books/midas.txt","golden touch",3.7,"11111111");
    book Btwo("moonLanding","history.com","books/moonLanding.txt","1969 moonlading",4.8,"2222222");
    book Bthree("eeewogirwg","Petur","books/book3.txt","diskro",3,"3333333333");
    book Bfour("aaavfsorjinv","Ivan","books/book4.txt","desk",5.5,"44444444444");
    book Bfive("bbblewrjgnb","don","books/book5.txt","topan Ivan ortoman",4.2,"5555555");

    Bone.createBookInfoFile();
    Btwo.createBookInfoFile();

    lib.addBook(Bone);
    lib.addBook(Btwo);
    lib.addBook(Bthree);
    lib.addBook(Bfour);

    lib.menu( login() );
     
}