#pragma once

class Interface{
    public:
        //const char*& getInput()const;
        void menu();
        void help();
    private:
        static const size_t MAX_INPUT_SIZE = 256;
        Parser m_parser;

};