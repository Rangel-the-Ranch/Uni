 #include"XMLelement.h"

void XMLelement::setId(const char* newId){
    id = newId;
}
 const char* XMLelement::getId()const{
    return id.get();
 }
 XMLelement::XMLelement(){
    atributes = new atribute [DEFAULT_ATRIBUTE_ARR_SIZE];
 }
void XMLelement::addAtribute(const atribute& newAtribute){
    while(numberOfAtributes + 1 >= sizeOfAtributeArr){
        resizeAtributeArr();
    }
    atributes[numberOfAtributes] = newAtribute;
    numberOfAtributes++;
 }  
void XMLelement::resizeAtributeArr(){
    sizeOfAtributeArr = sizeOfAtributeArr * 2;
    atribute* temp = new atribute [ sizeOfAtributeArr ];

    for(int i=0; i<sizeOfAtributeArr/2 ;i++){
        temp[i] = atributes[i];
    }

    delete []atributes;
    atributes = temp;
    temp = nullptr;

 }

 const atribute* XMLelement::getAtributes()const{
    return atributes;
 }
 const atribute* XMLelement::searchAtribute(const char* searchText)const{
    for(int i = 0; i<numberOfAtributes; i++){
        if( atributes[i].getName() == searchText ){
            return &atributes[i];
        }
    }
    return nullptr;
 }
  const atribute* XMLelement::getAtributeNum(const size_t number)const{
    if(number > numberOfAtributes){
        return nullptr;
    }else{
        return &atributes[number];
    }
 }

 void XMLelement::setText(const char* newText){
    text = newText;
 }
const char* XMLelement::getText()const{
    return text.get();
}
void XMLelement::free(){
    delete []atributes;
}
XMLelement::~XMLelement(){
    free();
}
void XMLelement::copyFrom(const XMLelement& other){
    numberOfAtributes = other.numberOfAtributes;
    sizeOfAtributeArr = other.sizeOfAtributeArr;
    id = other.id;
    text = other.text;
    atributes = new atribute [sizeOfAtributeArr];
    for(int i=0 ; i<sizeOfAtributeArr; i++){
        atributes[i] = other.atributes[i];
    }
}
XMLelement::XMLelement(const XMLelement& other){
    copyFrom(other);
}
XMLelement& XMLelement::operator=(const XMLelement& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}