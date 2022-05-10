#pragma once

class user{
    private:
        static const size_t MAX_PARAMATERS_LEN = 100;
        char* username;
        char* password;
        bool isAdmin;


        const bool isValidUsername(const char* name)const;
        void free();
        void copyFrom(const user&);

    public:
        user(const char* newUsernam , const char* newPassword , const bool isAdmin);
        user();
        user(const user& other);
        user(const char* location);
        
        ~user();
        user& operator= (const user&);

        void setUsername(const char* newUsername);
        void setPassword(const char* newPassword);  
        void setIsAdmin(const bool newIsAdmin);
        void setAll(const char* newUsername, const char* newPassword, const bool newIsAdmin);
        const char* getUsername()const;      
        const char* getPassword()const;
        const bool checkPassword(const char* input)const;
        const bool checkUsername(const char* input)const;
        const bool getIsAdmin()const;  
        const size_t getMAX_PARAMETER_LEN()const; 

        void createUserFile()const;
        void importFile(const char* location);
        const char* getUserFileLocation()const;

};