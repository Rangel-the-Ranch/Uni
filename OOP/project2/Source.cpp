#include<iostream>

#include"myString/myString.h"
#include"myString/myString.cpp"

#include"atribute/atribute.h"
#include"atribute/atribute.cpp"

#include"XMLelements/XMLelement.h"
#include"XMLelements/XMLelement.cpp"

#include"Parser/Parser.h"
#include"Parser/Parser.cpp"

size_t XMLelement::uniqueIdNum = 1;

int main(){
    
    //Parser kur;
    //kur.incertFile("testTXT.TXT");
    /*
    XMLelement A;
    kur.addElement(A);
    kur.getElementByIndex(0)->getText();
    kur.m_edit->setText("jaba");
    std::cout<<kur.getElementByIndex(0)->getText();
    kur.print();
    */
    XMLelement mazno[100];
    std::cout<<mazno[0].getId();
    std::cout<<mazno[1].getId();
    std::cout<<mazno[2].getId();
    std::cout<<mazno[3].getId();
    std::cout<<mazno[4].getId();


}