#pragma once

#include<cmath>

class Interface{
    public:
        //const char*& getInput()const;
        void begin();

        
        void open(const char* fileName);
        void close();
        void save()const;
        void saveAs(const myString& newFile)const;
        void help()const;
        //void exit();
        void print()const;
        void select(const myString& elementId , const myString& nameOfAtribute)const;
        void set(const myString& elementId , const myString& nameOfAtribute, const myString& newValue);
        void children(const myString& elementId)const;
        void child(const myString& elementId , const myString& key)const;
        void text(const myString& elementId)const;
        void deleteAtr(const myString& elementId, const myString& nameOfAtribute);
        void newChild(const myString& elementId);

    private:
        static const size_t MAX_INPUT_SIZE = 20;
        Parser m_parser;
        myString m_file;

};