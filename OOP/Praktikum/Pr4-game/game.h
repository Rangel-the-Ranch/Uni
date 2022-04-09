#include "player.h"
//#include <cmath>
const int min_AGE = 18;
class casino{
private:
    player person;
    bool validAge(){
        return ( person.getAge() >= min_AGE );
    }
    bool bancyptCheck(){
        if( this->perosn.getMoney() <= 0);
    }
    int randomNumber(){
        return 51;
    }
    void setMoney(int money){
        this->person.setMoney(money);
        bancyptCheck();
    }
    bool isItPrimary(int number){
        int opt = sqrt(number);
        for(int i=2 ;i<opt;i++){
            if(number%i == 0){
                return false;
            }
        }
        return true;
    }
    bool isItPowOfTwo(int number){
        while(number > 1){
            if(number%2 == 1){
                return false;
            }else{
                number = number/2;

            }
        }
        if(number == 1){
            return true;
        }else{
            return false;
        }
    }
    void gameOver(){
        cout<<"game over";
    }
public:
    /*
    person(player& person){
        validAge();
        bancyptCheck();
    }*/

    void evenOdd(int bet , bool guess){
        if( guess == randomNumber() % 2){
            setMoney(this->person.moeny + ((bet*6)/5) )
        }else{
            setMoney(this->person.money - bet);
        }
    }
    void primary(int bet , bool guess){
        if( guess == primary( randomNumber() )   ){
            setMoney(this->person.moeny + ((bet*3)/2) );
        }else{
            setMoney(this->person.money - bet);
        }
    }
    void powOfTwo(int bet){
        if( isItPowOfTwo( randomNumber() )   ){
            setMoney(this->person.moeny + (bet*2) );
        }else{
            setMoney(this->person.money - bet);
        }
    }
    void guessNumber(int bet, int guess){
        if( guess == randomNumber() ){
            setMoney(this->person.moeny + (bet*10) );
        }else{
            setMoney(this->person.money - bet);
        }
    }

};
