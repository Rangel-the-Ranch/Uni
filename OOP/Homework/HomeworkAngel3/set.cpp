#include"set.h"

Set::Set(){

}

void Set::addWord(char* word){
    strcpy(this->words[numberOfWords] , word);
}


