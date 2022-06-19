#include"Interface/Interface.h"
//cd OOP/project2
//g++ Source.cpp myString/myString.cpp Interface/Parser/XMLelement/atribute/atribute.cpp Interface/Parser/XMLelement/XMLelement.cpp Interface/Parser/Parser.cpp Interface/Interface.cpp -o Source.exe ; ./Source.exe
size_t XMLelement::uniqueIdNum = 1;
const myString Parser::BASE_ID = "_Base";
int main(){  
    Interface interface;
    interface.begin();
    //interface.open("test.xml");
    //interface.print();
    //interface.xpath("_18" , "gradusi/");
}

