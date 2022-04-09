#include<cstring>
class player{
private:
    char* name;
    char* password;
    int age;
    int money;


public:
    player(){
        this->name = "Unknown";
        this->password = "123456";
        this->age = 0;
        this->money = 0;
    }
    player(const char* name, const char* password ,int age,int  money ){
        this->name = new char[strlen(name)+1];
        this->password = new char[strlen(password)+1];
        this->age = age;
        this->money = money;
    }
    int getAge()const{
        return this->age;
    }
    int getMoney()const{
        return this->money;
    }
    int setMoney(int money){
        this->money = money;
    }
    ~player(){
        delete []name;
        delete []password;
    }
};
