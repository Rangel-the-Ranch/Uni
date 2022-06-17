#include"Parser.h"

#include<exception>

Parser::Parser(){
    m_XMLelements = new XMLelement[DEFAULT_ELEMENTS_ARR_SIZE];
}
void Parser::free(){
    delete []m_XMLelements;
}
Parser::~Parser(){
    free();
}
void Parser::copyFrom(const Parser& other){
    m_numberOfElements = other.m_numberOfElements;
    m_sizeOfElementsArr = other.m_sizeOfElementsArr;
    m_XMLelements = new XMLelement[m_sizeOfElementsArr];
    for(size_t i=0; i<m_sizeOfElementsArr; i++){
        m_XMLelements[i] = other.m_XMLelements[i];
    }
    m_edit = other.m_edit;
}
Parser::Parser(const Parser& other){
    copyFrom(other);
}
Parser& Parser::operator=(const Parser& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
void Parser::addElement(const XMLelement& newElement){
    while(m_numberOfElements + 1 >= m_sizeOfElementsArr){
        resizeXMLelementArr();
    }
    
    m_XMLelements[m_numberOfElements] = newElement;
    if(m_XMLelements[m_numberOfElements].getId()[0] =='\0'){
        
        m_XMLelements[m_numberOfElements].setId("_");

    }else{
        for(size_t i=0 ; i<m_numberOfElements ; i++){
            
            if(   strstr( m_XMLelements[m_numberOfElements].getId() , m_XMLelements[i].getId() )  ){

                m_XMLelements[m_numberOfElements].setId("_");
            }
        }
    }
    
    m_XMLelements[m_numberOfElements].setParent(m_edit);
    
    //m_edit->addChild( &m_XMLelements[m_numberOfElements] );
    
    m_numberOfElements++;
    

}
void Parser::resizeXMLelementArr(){
    m_sizeOfElementsArr = m_sizeOfElementsArr*2;
    XMLelement* temp = new XMLelement[m_sizeOfElementsArr];
    for(size_t i=0; i<m_sizeOfElementsArr;i++){
        temp[i] = m_XMLelements[i];
    }
    delete []m_XMLelements;
    m_XMLelements = temp;
    temp = nullptr;
}
const XMLelement* Parser::getElementByIndex(const size_t index)const{
    return &m_XMLelements[index];
}

void Parser::goToParent(){
    if( !findParent(m_edit).isEmpty() ){
        m_edit = findParent(m_edit);
    }
}


void Parser::incertFile(const char* file){
    std::ifstream iFile(file);
    if( !iFile.is_open() ){
        //throw std::logic_error("Cannot open file");
        return;
    }
    
    while( !iFile.eof() ){
        myString input( fileInput(iFile) );
        //std::cout<<input.get()<<"\n";
        if( input.getSize() ){
            if(input.get()[0] == '<'){
                if( input.get()[1] == '/' ){
                    
                    goToParent();
                }else{

                    size_t sizeOfInput = input.getSize();

                    myString* words = new myString [sizeOfInput];
                    size_t numberOfWords = 0;
                    for(size_t i=1; i<sizeOfInput-1 && input.get()[i] != '>' ; i++){
                        if(input.get()[i] != ' '){
                            words[numberOfWords] += input.get()[i];
                        }else{
                            if(input.get()[i-1] != ' '){
                                numberOfWords++;
                            }
                        }
                    }
                    
                    XMLelement temp;
                    temp.setParent(m_edit);
                    
                    for(size_t i=0 ; i<numberOfWords; i++){
                        if(words[i].get()[0] == 'i' && words[i].get()[1] == 'd' && words[i].get()[2] == '='){
                            words[i].removeFirstNsymbols(3);
                            temp.setId( words[i].get() );
                        }else{
                            Atribute tempAtribute(words[i].get() );
                            temp.addAtribute(tempAtribute);
                        }
                    }
                    delete []words; 
                    
                    
                    const size_t curIndex = findIndexById(m_edit);   
                    addElement(temp);
                    if(curIndex != m_numberOfElements){
                        m_XMLelements[curIndex].addChild( m_XMLelements[m_numberOfElements-1].getId() );
                    }                     
                    m_XMLelements[m_numberOfElements-1].setParent(m_edit);

                    m_edit = m_XMLelements[m_numberOfElements-1].getId();
                    
                }
            }else{
                
                const size_t curIndex = findIndexById(m_edit);    
                if(curIndex != m_numberOfElements){
                    m_XMLelements[curIndex].setText( input.get() );
                }  
                
                 
            }
        }
    }
    iFile.close(); 

}


const myString Parser::fileInput(std::ifstream& iFile)const{
    myString inputLine;
    
    while( !iFile.eof() ){
        
        char nextSym;
        nextSym = iFile.get();

        if( (nextSym == '<' && inputLine.getSize() != 0) || nextSym == '>' ){
            
            if(nextSym == '<'){
                
                iFile.seekg(-1 , std::ios::cur);
                
            }else{
                inputLine += '>';
            }
            
            return inputLine;

        }else{
            inputLine += nextSym;

        }
    }

    
    return inputLine;
}

void Parser::print()const{
    for(size_t i=0 ;i<m_numberOfElements;i++){
        std::cout<<"id: "<<m_XMLelements[i].getId()<<std::endl;
        if( m_XMLelements[i].getParent().isEmpty() ){
            std::cout<<"parent: NaN"<<std::endl;
        }else{
            std::cout<<"parent: "<< m_XMLelements[i].getParent().get() <<std::endl;
        }
        std::cout<<"children("<<m_XMLelements[i].getNumberOfChildren()<<"): ";
        for(size_t j=0; j<m_XMLelements[i].getNumberOfChildren(); j++){
            std::cout<< m_XMLelements[i].getChildByIndex(j).get() <<" ";
        }
        std::cout<<std::endl;
        std::cout<<m_XMLelements[i].getText();
        std::cout<<"\n\n";
    }
}

size_t Parser::findIndexById(const myString& searchedId)const{
    for(size_t i = 0; i<m_numberOfElements ; i++){
        if( searchedId == m_XMLelements[i].getId() ){
            return i;
        }
    }
    return m_numberOfElements;
}
const myString Parser::findParent(const myString& childId)const{
    myString result;
    const size_t childIndex = findIndexById(childId);
    for(size_t i = 0; i<m_numberOfElements; i++){
        if(m_XMLelements[childIndex].getParent() == m_XMLelements[i].getId() ){
            result =  m_XMLelements[i].getId();
        }
    } 
    return result;

}
const myString* Parser::getChildren(const myString& parentId)const{
    const size_t parentIndex = findIndexById(parentId);
    return m_XMLelements[parentIndex].getChildren();
}   