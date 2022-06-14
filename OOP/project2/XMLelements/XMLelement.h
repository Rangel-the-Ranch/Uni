 #pragma once
 
 #include<cstring>

 class XMLelement{
    public:
        XMLelement();
        XMLelement(const XMLelement& other);
        ~XMLelement();

        void setId(const char* newId);
        const char* getId()const;

        void addAtribute(const atribute& newAtribute);
        const atribute* getAtributes()const;
        const atribute* searchAtribute(const char* searchName)const;
        const atribute* getAtributeNum(const size_t number)const;

        void setText(const char* newText);
        const char* getText()const;

        void setParent(XMLelement* newParentAdr);
        XMLelement* getParentAdr()const;
        
        XMLelement& operator=(const XMLelement& other);

    private:

        static const size_t DEFAULT_ATRIBUTE_ARR_SIZE = 16;
        atribute* atributes;
        XMLelement* parent = nullptr;
        //XMLelement* child = nullptr;
        size_t numberOfAtributes = 0;
        size_t sizeOfAtributeArr = DEFAULT_ATRIBUTE_ARR_SIZE;   
        myString id;
        myString text;

        void resizeAtributeArr();
        void free();
        void copyFrom(const XMLelement& other);

 };