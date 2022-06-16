#pragma once

#include<cstring>
#include<fstream>

class Parser{
    public:
        Parser();
        Parser(const Parser& other);
        ~Parser();

        void addElement(const XMLelement& newElement);
        XMLelement* getElementByIndex(const size_t index)const;

        Parser& operator=(const Parser& other);

        void goToParent();

        void incertFile(const char* file);
        void print()const;

        void editElement(XMLelement* adr);
        XMLelement* m_edit = &m_XMLelements[0];

    private:
        static const size_t DEFAULT_ELEMENTS_ARR_SIZE = 16;
        XMLelement* m_XMLelements = nullptr;
        size_t m_numberOfElements = 0;
        size_t m_sizeOfElementsArr = DEFAULT_ELEMENTS_ARR_SIZE;
        

        void free();
        void copyFrom(const Parser& other);//////////////////////////////////////
        void resizeXMLelementArr();

        const myString fileInput(std::ifstream& iFile)const;
        
        
};