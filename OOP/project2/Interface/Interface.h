#pragma once

#include<cstring>
#include<iostream>

class Interface{
    public:
        void begin();

        
        void open(const char* fileName);
        void close();
        void save()const;
        void saveAs(const myString& newFile);
        void help()const;
        bool exit();
        void print()const;

    private:
        static const size_t MAX_INPUT_SIZE = 20;
        Parser m_parser;
        myString m_file;
        bool unsavedChanges = true;


        void select(const myString& elementId , const myString& nameOfAtribute)const;
        void set(const myString& elementId , const myString& nameOfAtribute, const myString& newValue);
        void children(const myString& elementId)const;
        void child(const myString& elementId , const myString& key)const;
        void text(const myString& elementId)const;
        void deleteAtr(const myString& elementId, const myString& nameOfAtribute);
        void newChild(const myString& elementId);
        void xpath(const myString& elementId , const myString& xpath)const;
};