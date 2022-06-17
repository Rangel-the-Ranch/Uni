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
    Parser kur;
    kur.incertFile("testTXT.TXT");
    kur.print();

}
/*
<player>
<person>Ivan</person>
<person>Gosho</person>
<person>Petur</person>
</player>
<items>
<weapon>sword</weapon>
<weapon>axe</weapon>
<food>
<slot>beef</slot>
<slot>pork</slot>
</food>
</items>
*/