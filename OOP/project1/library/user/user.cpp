const bool user::isValidUsername(const char* name)const{
    size_t sizeOfUsername = sizeof( name );
    if( strstr(name , " " ) == nullptr ){
        return true;

    }else{
        return false;
    }
}

void user::setUsername(const char* newUsername){
    delete []this->username;
    this->username = new char[ sizeof(newUsername) ];
    if( isValidUsername(newUsername) == true ){
        strcpy(username , newUsername);
        
    }else{
        this->username == nullptr;    
    }
}
const char* user::getUsername()const{
    return this->username;
}
void user::setPassword(const char* newPasswrod){
    delete []this->password;
    this->password = new char[ sizeof(newPasswrod) ];
    strcpy(this->password , newPasswrod);
}
const char* user::getPassword()const{
    return this->password;
}
const bool user::checkPassword(const char* input)const{
    if( strcmp(this->password , input) == 0 ){
        return true;
    }else{
        return false;
    }
}
void user::setIsAdmin(const bool newIsAdmin){
    this->isAdmin = newIsAdmin;
}
const bool user::getIsAdmin()const{
    return this->isAdmin;
}

void user::copyFrom(const user& other){
    setUsername( other.getUsername() );
    setPassword( other.getPassword() );
    setIsAdmin( other.getIsAdmin() );

}
user& user::operator=(const user& other){
    if(this != &other ){
        free();
        copyFrom(other);
    }
    return *this;
}

void user::free(){
    delete []this->username;
    delete []this->password;
}


user::user(){
    this->username = nullptr;
    this->password = nullptr;
    this->isAdmin = false;
}
user::user(const char* newUsername , const char* newPassword , const bool newIsAdmin){
    this->username = nullptr;
    this->password = nullptr;

    setUsername(newUsername);
    setPassword(newPassword);
    setIsAdmin(newIsAdmin);
}
user::user(const user& other){
    this->username = nullptr;
    this->password = nullptr;
    copyFrom(other);
}
user::~user(){
    free();
}



