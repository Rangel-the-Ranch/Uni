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

size_t numberOfUsers = 10;
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

            }else{
                std::cout<<"Welcome, "<<users[i].getUsername();

                return users[i];
            }
        }       
    }
    login();
} 
int main(){
    
    users[0].setAll("IvanDebelan" , "password" , 1);
    users[1].setAll("Admin" , "admin" , 1);
    users[2].setAll("misho","123456",0);
    users[3].setAll("Pesho","woeifgngwqpif",0);
    users[4].importFile("data/users/brumbur.txt");
    
    book Bone("dddwpoigjn","Ivan","books/book1.txt","trailer",2.7,"11111111");
    book Btwo("cccowig","Gosho","books/book2.txt","opis",3.14,"2222222");
    book Bthree("eeewogirwg","Petur","books/book3.txt","diskro",3,"3333333333");
    book Bfour("aaavfsorjinv","Ivan","books/book4.txt","desk",5.5,"44444444444");
    book Bfive("bbblewrjgnb","don","books/book5.txt","topan Ivan ortoman",4.2,"5555555");

    lib.addBook(Bone);
    lib.addBook(Btwo);
    lib.addBook(Bthree);
    lib.addBook(Bfour);

    lib.menu( login() );
     
}