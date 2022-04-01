#include<iostream>
#include<fstream>
#include<cstring>

//using namespace std;
class classFile{
  private:

    const char* source;
    unsigned int size;
    char* text = new char[size];

    unsigned int getFileSize(std::ifstream& iFile){ 
	    unsigned int currentPosition = iFile.tellg();
	    iFile.seekg(0, std::ios::end);
	    unsigned int result = iFile.tellg();
	    iFile.seekg(currentPosition);
	    return result;                          
    }
    char hexCnv(int sym){
      if(sym <=9){
        return sym + '0';
      }else{
        return sym + 'A' -10;
      }
    }
  public:
    
    classFile( const char* addr){
      setSource(addr);
      std::ifstream ifile(addr ,std::ios::binary);
      if(!ifile.is_open()){
        std::cout<<"Error opening file on reading";
        this->~classFile();
      }
      this->size = getFileSize(ifile);
      for(int i=0;i<size;i++){
        text[i] = ifile.get();
      }
      ifile.close();
    }
    ~classFile(){
      delete []text;
    }
    void setSource(const char* addr){
      this->source = addr;
    }
    
    void viewFile(){ 
      for(int i=0;i<size-1;i++){
        int symbol = text[i];
        char hex[2];
        if ( (symbol /16 ) != 0){
            
            hex[1] = hexCnv(symbol%16);
            symbol=symbol/16;
            hex[0] = hexCnv(symbol%16);
        }else{
          hex[0] = '0';
          hex[1] = hexCnv( symbol%16 );
        }
        std::cout<<hex[0]<<hex[1]<<" "; 
      }
      std::cout<<std::endl;
      for(int i=0;i<size-1;i++){            
        char symbol = text[i];
        if( (symbol >=  65 && symbol <= 90 ) || (symbol >= 97 && symbol<=122 ) ){
          std::cout<<symbol<<"  ";
        }else{
          std::cout<<symbol<<"  ";
        }
     }
    }
    void change(char newSym, int pos){
      this->text[pos] = newSym;
    }
    void remove(){
      this->text[size-1] = '\0';
      this->size--;
    }
    void add(char newSym){
      this->text[size-1] = newSym;
      this->size++; 
    }
    void save(){
      std::fstream ofile(source ,std::ios::binary | std::ios::trunc);
      if(!ofile.is_open()){
        std::cout<<"Error opening file on writing";
      }else{
        ofile.seekp(std::ios::beg);
        ofile.write((char*)text ,this->size);
        ofile.close();
      }
    }
    void saveAs(const char* newSource){
      std::fstream ofile(newSource ,std::ios::binary | std::ios::trunc);
      if(!ofile.is_open()){
        std::cout<<"Error opening new file on writing";
      }else{
        ofile.seekp(std::ios::beg);
        ofile.write((char*)text ,this->size);
        ofile.close();
      }
      
    }

};




int main(){


const char* fileOne = "file1.dat";
const char* fileTwo = "file2.dat";
const char* fileThree = "file3.dat";

const char* activeFile = fileTwo;
std::fstream file(activeFile ,std::ios::binary | std::ios::in | std::ios::out);
//unsigned size = getFileSize(file);

//viewFile( array , size);
//std::cout<<array;
//activeFile = fileTwo;
file.close();
classFile A(fileOne);

//A.add('E');
//A.add('A');
//A.add('y');
A.remove();
A.remove();
A.remove();
A.remove();
A.remove();
A.remove();
A.remove();
A.remove();
A.remove();
A.remove();
A.remove();
A.remove();
A.remove();
A.remove();
A.viewFile();
A.save();
}