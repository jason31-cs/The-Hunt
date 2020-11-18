//main.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Intro.h"
using namespace std;

//global constants
string editingfile, username;
char diff;
int health,seed;

int stage,choice,c_health,done;
bool b_done;

struct Game_progress {
  bool b_done;
  int done;
  int stage;
  int choice;
  int c_health;
};

void update_progress(Game_progress * &progress, int &size, int stage, int choice,int c_health ,bool b_done, int done){
	Game_progress * temp = new Game_progress[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = progress[i];
	}

	delete [] progress;
	progress = temp;
  progress[size].stage = stage;
  progress[size].choice = choice;
  progress[size].c_health = c_health;
  progress[size].b_done = b_done;
  progress[size].done = done;
	size ++;
	return;
}


void initialize(){
  //Look at save file and edit progress values 
  string input,extra;

  int size = 0;
  Game_progress * progress = new Game_progress[size];

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

  fin.open("a.txt");

  for (int i = 0; i < 4 ; i++){
    getline(fin,input);
  }

  while (getline(fin,input)){

    istringstream sin(input);
    sin >> stage;
    sin >> choice;
    sin >> c_health;
    sin >> b_done;
    sin >> done;
    while(sin>>extra){
      cout<<"extra"<<extra;
    }
    update_progress(progress,size,stage,choice,c_health,b_done,done);
  }
  fin.close();

  cout<<"=================================================="<<endl;
  cout<<"seed: " <<seed<<endl;
  cout<<"editing: "<<editingfile<<endl;
  cout<<"name: "<<username<<endl;
  cout<<"diff: "<<diff<<endl;
  cout<<"health: ";
  for(int i = 0 ; i < health ; i++)
    cout<<heart;
  cout<<endl;

  //test
  for (int i = 0; i < size ; i++){
    cout<< "stage " << progress[i].stage;
    cout<< " choice " << progress[i].choice;
    cout<< " health " << progress[i].c_health;
    cout<< " b_done " << progress[i].b_done;
    cout << " done " << progress[i].done;
    cout <<endl;
  }

}

int main(){
  initialize();

}
