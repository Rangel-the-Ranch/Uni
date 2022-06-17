#include<iostream>

#include"myString/myString.h"
#include"myString/myString.cpp"

#include"atribute/atribute.h"
#include"atribute/atribute.cpp"

#include"XMLelements/XMLelement.h"
#include"XMLelements/XMLelement.cpp"

#include"Parser/Parser.h"
#include"Parser/Parser.cpp"

#include"Interface/Interface.h"
#include"Interface/Interface.cpp"

size_t XMLelement::uniqueIdNum = 1;

int main(){  
    /*
    Interface inter;
    inter.menu();
    */

      
    Parser kur;
    kur.incertFile("testTXT.xml");
    std::cout<<std::endl;
    kur.print();
    
}
