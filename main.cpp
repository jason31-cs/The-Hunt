//main.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Intro.h" //for introduction
#include "puzzle.h" //for puzzles
using namespace std;

//global constants
string editingfile, username;
char diff;
const int HEADERSIZE = 3;
int seed;
int stage, choice,c_health,done,prog_size = 0;
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
  Game_progress * progress = new Game_progress[prog_size];
  for (int i = 0; i < 20 ; i++)
    cout<<endl;

  introduction(); //save file is selected

  ifstream fin;
  fin.open("currentfile.txt");
  fin>>editingfile;
  fin.close();

  fin.open(editingfile);
  fin >> seed >> username >> diff;
  fin.close();

  fin.open(editingfile);

  for (int i = 0; i < HEADERSIZE ; i++){
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
    update_progress(progress,prog_size,stage,choice,c_health,b_done,done);
  }
  fin.close();

  cout<<"=================================================="<<endl;
  cout<<"seed: " <<seed<<endl;
  cout<<"editing: "<<editingfile<<endl;
  cout<<"name: "<<username<<endl;
  cout<<"diff: "<<diff<<endl;

  //test
  for (int i = 0; i < prog_size ; i++){
    cout<< "stage " << progress[i].stage;
    cout<< " choice " << progress[i].choice;
    cout<< " health " << progress[i].c_health;
    cout<< " b_done " << progress[i].b_done;
    cout << " done " << progress[i].done;
    cout <<endl;
  }

}

void mainappendfile(string content,string filename){
  ofstream fout;
  fout.open(filename,ios::app);
  fout<<content<<endl;
  fout.close();
}

void update_save(int stage, int choice,int c_health ,bool b_done, int done){
  //updates savefile
  ostringstream status (ostringstream::ate);
  status << stage << " " << choice << " "<< c_health << " "<< b_done << " "<<done<<endl;
  string content = status.str();
  mainappendfile(content, editingfile);

}

//game start

void inputcheck(string & ans,string poss_ans[],int num_ans){
  bool valid = 0;
  while (!valid){
    cin >> ans;
    for (int i = 0; i < num_ans ; i++){
      if (ans == poss_ans[i]){
        valid = 1;
      }
    }

    if (!valid){

      if(ans == "help" ){
        cout<<"possible ans:";
        for (int i = 0; i < num_ans ; i++){
          cout<< " \' "<<poss_ans[i]<< " \' ";
        }
        cout<<", please input again" <<endl;
      }
      else {
        cout<< "Invalid Input, input \'help\' for possible answers"<<endl;
      }
    }
  }
}

void gameover(){
  cout<<"You have lost all health \n \n "<<endl;
  cout<<" ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗ "<<endl;
  cout<<"██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗"<<endl;
  cout<<"██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝"<<endl;
  cout<<"██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗"<<endl;
  cout<<"╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║"<<endl;
  cout<<" ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝"<<endl;
}

void display_health(int health){
  string heart = "♥";
  cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<"Current health: ";
  for (int i = 0 ; i < health ; i++){
    cout<< heart;
  }
  cout<<endl<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}

int junction1(){
  //-1 if gameover, 0 for choice 1 and 1 for choice 2
  string userin;
  bool failed = 1;
  //part 1 of junction 1
  while(c_health > 0 && failed){
    cout<<""<<endl;
    cout<<"The low hum of the wind passing through the old vents of the hospital "<<endl;
    cout<<"and the crackling of rusted pipes fills the background. As you regained"<<endl;
    cout<<"consciousness, you noticed that you are strapped by a worn out leather"<<endl;
    cout<<"strap onto a cold silver examination table. "<<endl;
    cout<<""<<endl;
    cout<<"You hear footsteps coming closer and closer from a distance in the corridor "<<endl;
    cout<<"to your right "<<endl;
    cout<<""<<endl;
    cout<<"Your gut tells you to get out of there at that very instance. "<<endl;
    cout<<"======================================================"<<endl;
    cout<<""<<endl;
    cout<<"You can either pretend to be unconscious or you can try tugging your wrist"<<endl;
    cout<<"straps to get out of there"<<endl;
    cout<<"\'1\' to pretend to be unconscious or \'2\' to try and get out of there"<<endl;
    string ans1[2]={"1","2"};
    inputcheck(userin,ans1,2);
    if (userin == "1"){
      cout<<""<<endl;
      cout<<"You have made the wrong choice, a dark figure appeared from the corridor"<<endl;
      cout<<"You quickly closed ur eyes, held your breath and spent every ounce of your"<<endl;
      cout<<"energy to stay still. "<<endl;
      cout<<""<<endl;
      cout<<"You hear the deep sounding footsteps getting closer and closer to you"<<endl;
      cout<<""<<endl;
      cout<<"Your curiosity is too much for you to bear, you peak and see the most"<<endl;
      cout<<"horrendous thing you have ever seen. "<<endl;
      cout<<""<<endl;;
      cout<<"You have lost a health."<<endl;
      c_health -= 1;
      display_health(c_health);
    }
    else if (userin == "2"){
      cout<<""<<endl;
      cout<<"You pulled your wrist with every ounce of your body strength,  the leather strap"<<endl;
      cout<<"broke along side with the metal parts that secure it in place The metal part hits"<<endl;
      cout<<"the floor making a loud \'clank\' !!!! You can hear the footstep switching from a"<<endl;
      cout<<"slow calm pace to a rapid pattern of thuds with increasing volume. "<<endl;
      cout<<""<<endl;
      cout<<"You look around and see a metallic door in front of you, and a vent to your left"<<endl;
      cout<<"covered by a fragile looking cover. "<<endl;
      cout<<"======================================================"<<endl;
      cout<<""<<endl;
      cout<<"You can either choose the vent \'V\' or the door \'D\'. "<<endl;
      userin = ""; //reset userin
      failed = 0; //passed
      string ans2[2] = {"V","D"};
      inputcheck(userin,ans2,2);
    }
  }

  //gameover sequence
  if (c_health == 0){
    gameover();
    return -1;
  }
  //part 2 of junction 1
  if (userin == "V"){
    cout<<""<<endl;
    cout<<"You ran towards to vent, as you have guessed, the cover is extremely loose. One tug "<<endl;
    cout<<"and it came off. "<<endl;
    cout<<"You quickly scurry inside the vents, and crawled as fast as you can. You come "<<endl;
    cout<<"out of the vent and see…"<<endl;
    return 0;
  }
  else if (userin == "D"){
    cout<<""<<endl;
    cout<<"You ran towards to metallic door, the door is sturdy and heavy. Luckily for you"<<endl;
    cout<<"it is unlocked. You open it and find yourself in a dark room. The door closed "<<endl;
    cout<<"behind you and locked itself.  As you walk towards the end of the room you "<<endl;
    cout<<"accidentally flicked on a light switch and you see…"<<endl;
    return 1;
  }
  else return -1;

}

int main(){
  int userchoice, choice_1, choice_2;

  initialize();
  while (c_health >  0 && stage < 4) { // not dead and havent finished game
    srand(seed); // randomize number
    choice_1 = rand();
    choice_2 = rand();
    if (stage == 0){
        userchoice = junction1();
        choice = userchoice;
        stage++;
        b_done = 0;
        done = 0;
        update_save(stage,choice,c_health,b_done,done);
    }

  }







}
