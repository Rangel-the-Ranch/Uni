#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
    ofstream f("file.dat", ios::binary);
     int a = 155555;
   f.write((const char*)&a, sizeof(int));

}