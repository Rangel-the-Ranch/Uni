//#include<iostream>

#include"myString/myString.h"
#include"Interface/Parser/XMLelement/atribute/atribute.h"
#include"Interface/Parser/XMLelement/XMLelement.h"
#include"Interface/Parser/Parser.h"
#include"Interface/Interface.h"

#include"myString/myString.cpp"
#include"Interface/Parser/XMLelement/atribute/atribute.cpp"
#include"Interface/Parser/XMLelement/XMLelement.cpp"
#include"Interface/Parser/Parser.cpp"
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
    return 0;
}

