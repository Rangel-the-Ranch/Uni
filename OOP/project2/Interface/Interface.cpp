#include"Interface.h"

void Interface::help()const{
    std::cout<<"open <name of file>         -> Open file with selected name"<<std::endl;
    std::cout<<"close                       -> Closes currently opened XML file"<<std::endl;
    std::cout<<"save                        -> Saves changes on current XML file"<<std::endl;
    std::cout<<"saveAs <name of new file>   -> Caves changes on another XML file"<<std::endl;
    std::cout<<"help                        -> Swows list of commands"<<std::endl;
    std::cout<<"exit                        -> Exit program"<<std::endl;
    std::cout<<"print                       -> Print loaded XML file"<<std::endl;
    std::cout<<"select <id> <key>           -> Get atribute value"<<std::endl;
    std::cout<<"set <id> <key> <value>      -> Set atribute value"<<std::endl;
    std::cout<<"delete <id> <key>           -> Delete atribute"<<std::endl;
    std::cout<<"children <id>               -> Get children of <id>"<<std::endl;
    std::cout<<"child <id> <n>              -> Get index <n> child of <id>"<<std::endl;
    std::cout<<"newChild <id>               -> Add empty child to <id>"<<std::endl;
    std::cout<<"text <id>                   -> Get text of <id>"<<std::endl;
}
void Interface::open(const char* fileName){
    m_parser.incertFile(fileName);
    m_file = fileName;
}
void Interface::text(const myString& elementId)const{
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    std::cout<<m_parser.getElementByIndex(indexOfElement)->getText();
    std::cout<<std::endl;
}
void Interface::print()const{
    m_parser.print();
}
void Interface::select(const myString& elementId , const myString& nameOfAtribute)const{
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    if( !m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute) ){
        std::cout<<"Atribute doesnt exist!"<<std::endl;
        return;
    }
    
    if(m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute)->withoutValue()){
        std::cout<<"Atribute has no value!"<<std::endl;
        return;
    }else{  
        std::cout<<m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute)->getName();
        std::cout<<" = ";
        std::cout<<m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute)->getValue();
        std::cout<<std::endl;
    }
}
void Interface::set(const myString& elementId , const myString& nameOfAtribute, const myString& newValue){
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    if( !m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute) ){
        std::cout<<"Atribute doesnt exist!"<<std::endl;
        return;
    }
    m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute)->setValue(newValue.get());
    std::cout<<"New value set!"<<std::endl;
}
void Interface::children(const myString& elementId)const{
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    for(size_t i=0; i < m_parser.getElementByIndex(indexOfElement)->getNumberOfChildren(); i++){
        std::cout<<m_parser.getElementByIndex(indexOfElement)->getChildByIndex(i).get()<<" ";
    }
    std::cout<<std::endl;
}
void Interface::child(const myString& elementId, const myString& key)const{
    const int convert = key.getNumber();
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    if( key.getNumber() == -1 ){
        std::cout<<"Invalid key!";
        return;
    }
    const size_t convertT = static_cast<size_t>(convert);
    if( convertT >= m_parser.getElementByIndex(indexOfElement)->getNumberOfChildren()){
        std::cout<<"Invalid key!";
        return;
    }
    std::cout<<m_parser.getElementByIndex(indexOfElement)->getChildByIndex(convert).get();
    std::cout<<std::endl;
}
void Interface::newChild(const myString& elementId){
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    XMLelement t_newChild;
    m_parser.getElementByIndex(indexOfElement)->addChild(t_newChild.getId());
    std::cout<<"Added new child with ID: "<<m_parser.getElementByIndex(indexOfElement)->getChildByIndex( m_parser.getElementByIndex(indexOfElement)->getNumberOfChildren()-1 ).get();
    std::cout<<std::endl;
}
void Interface::deleteAtr(const myString& elementId, const myString& nameOfAtribute){
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    if( !m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute) ){
        std::cout<<"Atribute doesnt exist!"<<std::endl;
        return;
    }
    m_parser.getElementByIndex(indexOfElement)->deleteAtribute(nameOfAtribute);
    std::cout<<"Deleted!"<<std::endl;
}
void Interface::save()const{
    m_parser.exportToFile(m_file.get());
}
void Interface::saveAs(const myString& newFile)const{
    m_parser.exportToFile(newFile.get());
}
void Interface::close(){
    if(m_file != '\0'){
        m_file = '\0';
        m_parser.cleanUp();
    }
}
void Interface::begin(){
    char input[MAX_INPUT_SIZE];
    std::cin.getline(input, MAX_INPUT_SIZE);
    const size_t sizeOfInput = strlen(input) +1;
    myString* words = new myString[MAX_INPUT_SIZE];
    size_t numberOfWords = 0;
    for(size_t i=0; i<sizeOfInput; i++){
        if(input[i] == ' '){
            words[i] += '\0';
            if(input[i-1] !=' '){
                
                numberOfWords++;
            }
        }else{
            words[numberOfWords] += input[i];  
        }
    }
    numberOfWords++;
    bool didCommand = false;
    bool exit = false;
    if(words[0] == "open"){open(words[1].get()); didCommand = true;}
    if(words[0] == "close"){close(); didCommand = true;}
    if(words[0] == "save"){save(); didCommand = true;}
    if(words[0] == "saveAs"){saveAs(words[1]); didCommand = true;}
    if(words[0] == "help"){help(); didCommand = true;}
    if(words[0] == "exit"){didCommand = true; exit = true;}
    if(words[0] == "print"){print(); didCommand = true;}
    if(words[0] == "select"){select(words[1] , words[2]); didCommand = true;}
    if(words[0] == "set"){set(words[1] , words[2] , words[3]); didCommand = true;}
    if(words[0] == "children"){children(words[1]); didCommand = true;}
    if(words[0] == "child"){child(words[1] , words[2]); didCommand = true;}
    if(words[0] == "text"){text(words[1]); didCommand = true;}
    if(words[0] == "delete"){deleteAtr(words[1] , words[2]); didCommand = true;}
    if(words[0] == "newChild"){newChild(words[1]); didCommand = true;}
    
    if(didCommand == false){
        std::cout<<"druga komanda";
    }

    delete []words;
    if(exit == true){
        ////////////////////save / close//////////////////////////
    }else{
        //begin();
    }
}