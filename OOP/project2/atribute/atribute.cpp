#include"atribute.h";

const char* atribute::getName()const{
    return name.get();
}
const char* atribute::getValue()const{
    return value.get();
}
void atribute::setName(const char* newName){
    name = newName;
}
void atribute::setValue(const char* newValue){
    value = newValue;
}
bool atribute::withoutValue()const{
    if(value.isEmpty() == true ){
        return false;
    }else{
        return true;
    }
}
atribute::atribute(const char* newName , const char* newValue){
    name = newName;
    value = newValue;
}