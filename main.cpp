//main.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Intro.h"
using namespace std;

struct Game_progress {
  char junction;
  int num_games;
};

void update_progress(Game_progress *&progress, int &n, int new_size, char inp) {
  
  Game_progress* temp = new Game_progress[new_size];

 for (int i = 0; i < n; i++) {
   temp[i].junction = progress[i].junction;
   temp[i].num_games = progress[i].num_games;
}

 
for (int i = n; i < new_size;i++) {
  temp[i].junction = inp;
}

progress = new Game_progress[new_size];


n = new_size;

}



//global constants
string editingfile, username;
char diff;
int health,seed;



void setgame(){
  srand(seed);



}

void initialize(){
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

int main(){
  initialize();


}
