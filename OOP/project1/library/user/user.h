#pragma once

class user{
    private:
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
        ~user();
        user& operator= (const user&);

        void setUsername(const char* newUsername);
        void setPassword(const char* newPassword);  
        void setIsAdmin(const bool newIsAdmin);
        const char* getUsername()const;      
        const char* getPassword()const;
        const bool checkPassword(const char* input)const;
        const bool getIsAdmin()const;   

        

};