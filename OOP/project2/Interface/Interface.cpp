#include"Interface.h"


/*
 const char*& Interface::getInput()const{
    char tempInput[MAX_INPUT_SIZE];
    std::cin.getline(tempInput, MAX_INPUT_SIZE);
    return tempInput;
}*/

void Interface::help(){
    std::cout<<"open <name of file>  -> open file with selected name"<<std::endl;
    std::cout<<"close                -> closes currently opened XML file"<<std::endl;
    std::cout<<"save                 -> saves changes on current XML file"<<std::endl;
    std::cout<<"saveAs <name of new file> -> caves changes on another XML file"<<std::endl;
    std::cout<<"help -> swows list of commands"<<std::endl;
    std::cout<<"exit -> exits program"<<std::endl;

    std::cout<<"print -> print loaded XML file"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"2.Print XML"<<std::endl;

    std::cout<<"select <id> <key> -> Get atribute value"<<std::endl;
    std::cout<<"set <id> <key> <value> ->Set atribute value"<<std::endl;
    std::cout<<"delete <id> <key>  -> Delete atribute"<<std::endl;

    std::cout<<"children <id> ->Get children of <id>"<<std::endl;
    std::cout<<"newChild <id> ->Add empty child to <id>"<<std::endl;

    std::cout<<"Get text"<<std::endl;
}