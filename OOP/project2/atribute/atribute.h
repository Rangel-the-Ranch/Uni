#pragma once
class atribute{
    public:
        atribute() = default;
        atribute(const char* newName , const char* newValue);

        void setName(const char* newName);
        const char* getName()const;
        void setValue(const char* newValue);
        const char* getValue()const;
        bool withoutValue()const;
    private:
        myString name;
        myString value;
};