 #include"XMLelement.h"

void XMLelement::setId(const char* newId){
    id = newId;
}
 const char* XMLelement::getId()const{
    return id.get();
 }
 XMLelement::XMLelement(){
    atributes = new Atribute [DEFAULT_ATRIBUTE_ARR_SIZE];
    childs = new XMLelement* [DEFAULT_CHILD_ARR_SIZE];
 }
void XMLelement::addAtribute(const Atribute& newAtribute){
    while(numberOfAtributes + 1 >= sizeOfAtributeArr){
        resizeAtributeArr();
    }
    atributes[numberOfAtributes] = newAtribute;
    numberOfAtributes++;
 }  
void XMLelement::resizeAtributeArr(){
    sizeOfAtributeArr = sizeOfAtributeArr * 2;
    Atribute* temp = new Atribute [ sizeOfAtributeArr ];

    for(int i=0; i<sizeOfAtributeArr/2 ;i++){
        temp[i] = atributes[i];
    }

    delete []atributes;
    atributes = temp;
    temp = nullptr;

 }

 const Atribute* XMLelement::getAtributes()const{
    return atributes;
 }
 const Atribute* XMLelement::searchAtribute(const char* searchText)const{
    for(int i = 0; i<numberOfAtributes; i++){
        if( atributes[i].getName() == searchText ){
            return &atributes[i];
        }
    }
    return nullptr;
 }
  const Atribute* XMLelement::getAtributeNum(const size_t number)const{
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
    delete []childs;
}
XMLelement::~XMLelement(){
    free();
}
void XMLelement::copyFrom(const XMLelement& other){

    id = other.id;
    text = other.text;

    numberOfAtributes = other.numberOfAtributes;
    sizeOfAtributeArr = other.sizeOfAtributeArr;
    atributes = new Atribute [sizeOfAtributeArr];
    for(int i=0 ; i<sizeOfAtributeArr; i++){
        atributes[i] = other.atributes[i];
    }

    parent = other.getParentAdr();

    numberOfChilds= other.numberOfChilds;
    sizeOfChildArr = other.sizeOfChildArr;
    

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
void XMLelement::setParent(XMLelement* newParentAdr){
    parent = newParentAdr;
}
 XMLelement* XMLelement::getParentAdr()const{
    return parent;
}

void XMLelement::addChild(XMLelement* newChild){
    while(numberOfChilds + 1 >= sizeOfChildArr){
        resizeChildArr();
    }
    childs[numberOfChilds] = newChild;
    numberOfChilds++;

}
void XMLelement::resizeChildArr(){
    sizeOfChildArr = sizeOfChildArr*2;
    XMLelement** temp = new XMLelement* [sizeOfChildArr];
    for(int i=0; i<sizeOfChildArr/2; i++){
        temp[i] = childs[i];
    }
    delete []childs;
    childs = temp;
    temp = nullptr;

}
XMLelement** XMLelement::getChilds()const{
    return childs;
}
XMLelement* XMLelement::getChildByIndex(const size_t index)const{
    return childs[index];
}