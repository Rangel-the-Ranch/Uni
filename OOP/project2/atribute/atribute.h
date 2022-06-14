#pragma once
class atribute{
    private:
        myString name;
        myString value;
    public:
        atribute() = default;
        atribute(const char* newName , const char* newValue);

        void setName(const char* newName);
        const char* getName()const;
        void setValue(const char* newValue);
        const char* getValue()const;
        bool withoutValue()const;
};