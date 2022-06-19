#include"Interface/Interface.h"
//cd OOP/project2
//g++ Source.cpp myString/myString.cpp Interface/Parser/XMLelement/atribute/atribute.cpp Interface/Parser/XMLelement/XMLelement.cpp Interface/Parser/Parser.cpp Interface/Interface.cpp -o Source.exe ; ./Source.exe
size_t XMLelement::uniqueIdNum = 1;
const myString Parser::BASE_ID = "_Base";
int main(){  
   
    Interface interface;
    interface.open("test.xml");
    //interface.print();
    interface.xpath("_18" , "gradusi/");
    //interface.xpath()
    //interface.begin();
    //Parser A;
    //A.incertFile("test.xml");
}
/*
<items id="_23">
	<weapon id="_25">item1</weapon>
	<weapon id="_27">item2</weapon>
	<food id="_29">
		<slot id="_31">slot1</slot>
		<slot id="_33">slot2</slot>
	</food>
</items>
*/

