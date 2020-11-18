//main.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Intro.h"
using namespace std;

//global constants
string editingfile, username;
char diff;
int health;
double seed;




int main(){
  string heart = "♥";
  for (int i = 0; i < 20 ; i++)
    cout<<endl;

  introduction(); //save file is selected

  ifstream fin;
  fin.open("currentfile.txt");
  fin>>editingfile;
  fin.close();

  fin.open(editingfile);
  fin >> seed >> username >> diff >> health;
  fin.close();

  cout<<"\n\n"<<endl;
  cout<<"seed: " <<seed<<endl;
  cout<<"editing: "<<editingfile<<endl;
  cout<<"name: "<<username<<endl;
  cout<<"diff: "<<diff<<endl;
  cout<<"health: ";
  for(int i = 0 ; i < health ; i++)
    cout<<heart;
  cout<<endl;


}
