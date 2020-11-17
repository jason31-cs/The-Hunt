#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> 
#include "Intro.h"

using namespace std;
int main(){
  string editingfile;
  for (int i = 0; i < 30 ; i++){
    cout<<"=";
  }
  for (int i = 0; i < 20 ; i++){
    cout<<endl;
  }
  introduction();
  ifstream fin;
  fin.open("currentfile.txt");
  fin>>editingfile;
  cout<<endl<<editingfile<<endl;

}
