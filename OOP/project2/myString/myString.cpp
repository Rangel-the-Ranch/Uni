#include "MyString.h"

void myString::free(){
    delete []str;
}
void myString::copyFrom(const myString& other){
    str = new char[ strlen( other.get() ) + 1];
	strcpy(str, other.get() );
	size = other.getSize();
}
void myString::concatFrom(const myString& other){
    char* temp = new char[getSize() + other.getSize() + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;
    temp = nullptr;

	size = size + other.getSize();
}
myString::myString(){
    str = new char [ 1 ];
    str[0] = '\0';
    size = 0 ; 
}
myString::myString(const char* newString){
    if(newString == nullptr){
        str = new char[ 1 ];
		str[0] = '\0';
		size = 0;
    }else{
        size = strlen(newString);
        str = new char [ size + 1 ];
        strcpy(str, newString);
        
    }
}
myString::myString(const myString& other){
    copyFrom(other);
}
myString::myString(myString&& other){
    str = other.str;
    other.str = nullptr;
    size = other.getSize();
}
size_t getNumSize(size_t number){
    size_t res = 0;
	while (number){
		res++;
		number = number / 10;
	}
	return res;
}
myString::myString(size_t number){
    size = getNumSize(number);

    str = new char[size + 1];
    str[size] ='\0';
    
    for(int i=0; i < size; i++){
        str[size - 1 - i] = (number % 10) + '0';
        number = number/10;    
    }


}

myString::~myString(){
    free();
}
size_t myString::getSize()const{
    return size;
}
const char* myString::get()const{
    return str;
}

myString& myString::operator=(const myString& other){
    if( this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
myString& myString::operator=(myString&& other){
    if( this != &other){
        free();
        str = other.str;
        other.str = nullptr;
        size = other.getSize();
    }
    return *this;
}
myString& myString::operator+=(const myString& other){
    concatFrom(other);
    return *this;
}
bool myString::isEmpty()const{
    if(str[0] == '\0' ){
        return true;
    }else{
        return false;
    }
}

bool operator==(const myString& left , const myString& right){
    return !strcmp(left.get() , right.get() );
    
}