#include<iostream>
#include"myString/myString.h"
#include"myString/myString.cpp"

#include"atribute/atribute.h"
#include"atribute/atribute.cpp"

#include"XMLelements/XMLelement.h"
#include"XMLelements/XMLelement.cpp"
int main(){
    XMLelement parent;
    XMLelement child;
    parent.setId("banan");
    child.setId("2");
    child.setParent(&parent);
    child.setId("zele");
    child.getParentAdr()->setId("portokal");
    std::cout<< parent.getId();
    //std::cout<< ("baklava" == A) ;
    //std::cout<< (A == "baklava") ;
    //XMLelement gosho;
    //std::cout<<gosho.getId();
}