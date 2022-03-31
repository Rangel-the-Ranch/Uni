#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
/*
class File{
  private:

  public:
    //const char* file;
    const char* source;
    std::ifstream file(source);
    File(){
      std::ifstream file(source);
    }
    void print();

    bool isFileOpen(const char* source)const {
      if(file.is_open() == false){
        return false;
      }else{
        return true;
      }
    }
    

};*/
bool viewFile(const char* source, int size){
  //const char* source;
  ifstream iFile(source, ios::binary);
  if(iFile.is_open() == false){
    return false;
  }
  
  for(int i=0;i<size;i++){
    char symbol = iFile.get();
    
      cout<<symbol<<" "; 
  }
  iFile.seekg(ios::beg);

  for(int i=0;i<size;i++){
    char symbol;
    iFile.read((char*)&symbol , sizeof(char));
    if( (symbol >=  65 && symbol <= 90 ) || (symbol >= 97 && symbol<=122 ) ){
      cout<<symbol;
    }else{
      cout<<".";
    }
  }
  iFile.close();
  return true;
}

int main(){
  ofstream file("file.dat", ios::binary);
  const char* source = "file.dat";
  int a = 999999;
  char str[20] = "efo5i124^ub";
  file.write((const char*)&str, sizeof(str));
  file.close();
  viewFile(source , sizeof(str));

}