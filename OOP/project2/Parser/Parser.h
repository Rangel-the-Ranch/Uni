#pragma once

#include<cstring>
#include<fstream>

class Parser{
    public:
        Parser();
        Parser(const Parser& other);
        ~Parser();
        Parser& operator=(const Parser& other);

        void addElement(const XMLelement& newElement);
        const XMLelement* getElementByIndex(const size_t index)const;

        void goToParent();

        size_t findIndexById(const myString& searchedId)const;
        const myString findParent(const myString& childId)const;
        const myString* getChildren(const myString& parentId)const;

        void incertFile(const char* file);
        void print()const;
        //XMLelement* m_XMLelements = nullptr;
    private:
        static const size_t DEFAULT_ELEMENTS_ARR_SIZE = 16;
        XMLelement* m_XMLelements = nullptr;
        size_t m_numberOfElements = 0;
        size_t m_sizeOfElementsArr = DEFAULT_ELEMENTS_ARR_SIZE;
        myString m_edit = "_Base";
        
        void free();
        void copyFrom(const Parser& other);
        void resizeXMLelementArr();
        const myString fileInput(std::ifstream& iFile);   
};