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
unsigned getFileSize(std::fstream &iFile){          //size_t??? //тук се пробвах да го викна само с ifstream обаче не се компилира
	unsigned currentPosition = iFile.tellg();                     //В такъв влучай просто навсякъде fstream ли въпреки че за самата функция не променям неща

	iFile.seekg(0, ios::end);
	unsigned result = iFile.tellg();
	iFile.seekg(currentPosition);
	return result;
}
void viewFile(std::fstream& iFile){  //каква е разликата дали го викам обикновенно или по референция

  unsigned size = getFileSize(iFile); //не е завършено
  //cout<<size;
  iFile.clear();                      //сложих го докато дебъгвах още незнам как работи
  /*
  for(int i=0;i<size;i++){
    char symbol = iFile.get();
    
      cout<<symbol<<" "; 
  }*/

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
  
}

int main(){
  fstream file("file.dat", ios::in | ios::out | ios::binary);
  //const char* source = "file.dat";
  if(!file.is_open()){
    cout<<"ne se otvarq";
    return 0;
  }
  int a = 999999;
  char str[20] = "efo5i124^ub";
  file.write((const char*)&str, sizeof(str));
  //unsigned int size = getFileSize(file); 
  //cout<<size;
  viewFile(file);

  file.close();

}