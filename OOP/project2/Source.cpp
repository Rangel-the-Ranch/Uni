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
const myString Parser::BASE_ID = "_Base";

int main(){  
    
    Interface inter;
    inter.begin();
    //inter.open("testTXT.xml");
    //inter.print();
    
    //Parser kur;
    //kur.incertFile("testTXT.xml");
    //kur.exportToFile("output.xml");
    
}

