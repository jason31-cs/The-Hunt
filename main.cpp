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
int stage, choice,c_health,prog_size = 0;
bool a_done, b_done;

struct Game_progress {
  bool a_done;
  int b_done;
  int stage;
  int choice;
  int c_health;
};

void update_progress(Game_progress * &progress, int &size, int stage, int choice,int c_health ,bool a_done, int b_done){
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
  progress[size].a_done = a_done;
  progress[size].b_done = b_done;
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
    sin >> a_done;
    sin >> b_done;
    while(sin>>extra){
      cout<<"extra"<<extra;
    }
    update_progress(progress,prog_size,stage,choice,c_health,a_done,b_done);
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
    cout<< " a_done " << progress[i].a_done;
    cout << " b_done " << progress[i].b_done;
    cout <<endl;
  }

}

void mainappendfile(string content,string filename){
  ofstream fout;
  fout.open(filename,ios::app);
  fout<<content<<endl;
  fout.close();
}

void update_save(int stage, int choice,int c_health ,bool a_done, int b_done){
  //updates savefile
  ostringstream status (ostringstream::ate);
  status << stage << " " << choice << " "<< c_health << " "<< a_done << " "<<b_done;
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

void running_puzzles(int Stage, int num, int c_health){
  bool pass = 0;
  while (c_health > 0 && !pass){
    pass = puzzle_collection(Stage, num);
    if (!pass){
      c_health--;
      display_health(c_health);
    }
  }
  if (c_health == 0){
    gameover();
  }
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

int junction2(){
  //-1 if gameover, 0 for choice R and 1 for choice L
  string userin;
  bool failed = 1;
  // junction 2
  while(c_health > 0 && failed){
    cout<<""<<endl;
    cout<<"You reached the end of the corridor, you can hear the thuds of the footsteps that"<<endl;
    cout<<"you have heard earlier. You know that whatever it is, it is hunting for you. Following"<<endl;
    cout<<"the tracks that you have left. "<<endl;
    cout<<""<<endl;
    cout<<"To your right there is a staircase that circles downwards into the darkness. To your"<<endl;
    cout<<"left there is an old looking elevator that does not seem to have been maintained for years."<<endl;
    cout<<"But you remember the saying that until you faced your demons head on, nothing"<<endl;
    cout<<"good will come out of your life. "<<endl;
    cout<<""<<endl;
    cout<<"======================================================"<<endl;
    cout<<""<<endl;
    cout<<"You can either choose to go right \'R\', left \'L\' or turn around and face your demon \'stay\'"<<endl;

    string ans1[3]={"R","L","stay"};
    inputcheck(userin,ans1,3);
    //if user stays
    if (userin == "stay"){
      cout<<""<<endl;
      cout<<"You puffed up your chest, put yourself into a battle stance like position that"<<endl;
      cout<<"you have recalled from an action movie. The loud thuds grow stronger and stronger."<<endl;
      cout<<"In the distance, you could see a dark shadowy figure crawling from the corridor that you"<<endl;
      cout<<"just came from. It popped his head out of the side, seemingly recognised you. The dark"<<endl;
      cout<<"figure dashed towards you. It was at this moment that you realised you have made the"<<endl;
      cout<<"wrong decision. This is not a demon you can face. "<<endl;
      cout<<"You have lost a health."<<endl;
      c_health -= 1;
      display_health(c_health);
    }
    //taking the stairs
    else if (userin == "R"){
      cout<<""<<endl;
      cout<<"You raced towards the stairs, thinking it would be a safe choice, you tumbled down the"<<endl;
      cout<<"staircase for what seemed like an eternity until you reached the end of the stairs."<<endl;
      cout<<"Although you sustained severe injuries, you might have gained a lead on the "<<endl;
      cout<<"creature. "<<endl;
      cout<<""<<endl;
      cout<<"Your health decreased by one"<<endl;
      c_health -=1;
      display_health(c_health);
      cout<<""<<endl;
      cout<<"You stood up with the last of your might and see… "<<endl;
      failed = 0; //passed
      return 0;
    }
    //taking the elevator
    else if (userin == "L"){
      cout<<""<<endl;
      cout<<"You pressed the down button on the wall next to the elevator. To your surprise,"<<endl;
      cout<<"the elevator door opened up smoothly. You went in and found that there was"<<endl;
      cout<<"only one button on the control panel. \'G\' You pressed it and the elevator door closed."<<endl;
      cout<<""<<endl;
      cout<<"As you feel that the elevator is slowly descending, a soothing lobby music starts"<<endl;
      cout<<"playing in the background. You became more calm and collected. "<<endl;
      cout<<""<<endl;
      cout<<"Your health increased by one"<<endl;
      c_health ++;
      display_health(c_health);
      cout<<""<<endl;
      cout<<"After what seems like an eternity, the elevator door opened, and you see…"<<endl;
      failed = 0; //passed
      return 1;
    }
  }
  //gameover sequence
  if (c_health == 0){
    gameover();
    return -1;
  }
  return -1;
}

int main(){
  int userchoice,choice0,choice1,game_a,game_b;
  const int no_stage1puzzles = 4;
  const int no_stage2puzzles = 4;
  int stage1[no_stage1puzzles]={1,2,3,4}; // 4 games in stage 1 of the hunt
  int stage2[no_stage2puzzles]={1,2,3,4}; // 4 games in stage 2 of the hunt

  initialize();

  // Show results , finished game
  if (stage == 4){
    cout<<endl<< "You have already completed the game in this file ";
    switch(diff){
      case 'E':
      cout<<"at easy difficulty. Try the game again in Hard mode."<<endl;
      break;
      case'H':
      cout<<"at Hard difficulty. Congrats!"<<endl;
      break;
      default:
      cout<< "diff error";
    }
  }

  while (c_health >  0 && stage < 4) { // not dead
    srand(seed); // set seed

    // stage 0 + junction 1
    if (stage == 0){
        userchoice = junction1();
        choice = userchoice;
        stage++;
        a_done = 0;
        b_done = 0;
        update_save(stage,choice,c_health,a_done,b_done); //save game
    }

    // stage 1 + junction 2
    else if (stage == 1){
      choice0 = rand()%no_stage1puzzles;
      choice1 = rand()%no_stage1puzzles;
      if (b_done == 0){
        switch (choice){
          case 0: //choice vent
          //set game a and game b  from choice

          game_a = stage1[choice0];
          stage1[choice0] = 0;
          game_b = stage1[rand()%no_stage1puzzles];
          while(game_b == 0)
            game_b = stage1[rand()%no_stage1puzzles]; //makes sure game is not replicated

          if(!a_done) // check if game a is complete
          running_puzzles(stage,game_a,c_health); //game a

          if (c_health > 0){ // check if player died in game a
            a_done = 1;
            update_save(stage,choice,c_health,a_done,b_done); // save game
            running_puzzles(stage,game_b,c_health); //game b
          }
          break;

          case 1: //choice door
          game_a = stage1[choice1];
          stage1[choice1] = 0;
          game_b = stage1[rand()%no_stage1puzzles];
          while(game_b == 0)
            game_b = stage1[rand()%no_stage1puzzles]; // makes sure game is not replicated

            if(!a_done) // check if game a is complete
            running_puzzles(stage,game_a,c_health); //game a

            if (c_health > 0){ // check if player died in game a
              a_done = 1;
              update_save(stage,choice,c_health,a_done,b_done); // save game
              running_puzzles(stage,game_b,c_health); //game b
            }
          break;
        }
      }
      if (c_health > 0){
        b_done = 1;
        update_save(stage,choice,c_health,a_done,b_done); //save game
        stage++; // increase stage by 1, stage == 2
        a_done = 0;
        b_done = 0;
        userchoice = junction2();
        choice = userchoice;
        update_save(stage,choice,c_health,a_done,b_done); //save game
      }
    }

    //stage 2
    else if (stage == 2){
      choice0 = rand()%no_stage2puzzles;
      choice1 = rand()%no_stage2puzzles;
      switch (choice){
        case 0: //choice right (stairs)
        //set game a and game b  from choice
        game_a = stage2[choice0];
        stage2[choice0] = 0;
        game_b = stage1[rand()%no_stage2puzzles];
        while(game_b == 0)
          game_b = stage2[rand()%no_stage2puzzles]; //makes sure game is not replicated

        if(!a_done) // check if game a is complete
        running_puzzles(stage,game_a,c_health); //game a

        if (c_health > 0){ // check if player died in game a
          a_done = 1;
          update_save(stage,choice,c_health,a_done,b_done); // save game
          running_puzzles(stage,game_b,c_health); //game b
        }
        break;

        case 1: //choice left (elevator)
        game_a = stage2[choice1];
        stage2[choice1] = 0;
        game_b = stage2[rand()%no_stage2puzzles];
        while(game_b == 0)
          game_b = stage2[rand()%no_stage2puzzles]; // makes sure game is not replicated

          if(!a_done) // check if game a is complete
          running_puzzles(stage,game_a,c_health); //game a

          if (c_health > 0){ // check if player died in game a
            a_done = 1;
            update_save(stage,choice,c_health,a_done,b_done); // save game
            running_puzzles(stage,game_b,c_health); //game b
          }
        break;
      }

      b_done = 1;
      update_save(stage,choice,c_health,a_done,b_done);
      b_done = 0;
      a_done = 0;
      stage++;
      update_save(stage,choice,c_health,a_done,b_done);

    }

    //stage 3 (ending)
    else if (stage ==3){
      cout<<""<<endl;
      cout<<"The exit of the hospital! It is right in front of you!!! It is so close, that you could almost "<<endl;
      cout<<"reach it."<<endl;
      running_puzzles(stage,1,c_health);
      if(c_health > 0){
          stage++;
          cout<<""<<endl;
          cout<<"The entrance opened, you ran outside immediately. Once you were outside"<<endl;
          cout<<"and looked back at the nightmare that you just escaped from, you see unordinary "<<endl;
          cout<<"except for an abandon hospital, nothing seems to be chasing you to the outside. "<<endl;
          cout<<""<<endl;
          cout<<"You have no idea how you got there in the first place, but intuition tells you to not "<<endl;
          cout<<"think about it ever again. "<<endl;
          update_save(stage,choice,c_health,a_done,b_done);
          cout<<"████████╗██╗  ██╗███████╗    ███████╗███╗   ██╗██████╗ "<<endl;
          cout<<"╚══██╔══╝██║  ██║██╔════╝    ██╔════╝████╗  ██║██╔══██╗"<<endl;
          cout<<"   ██║   ███████║█████╗      █████╗  ██╔██╗ ██║██║  ██║"<<endl;
          cout<<"   ██║   ██╔══██║██╔══╝      ██╔══╝  ██║╚██╗██║██║  ██║"<<endl;
          cout<<"   ██║   ██║  ██║███████╗    ███████╗██║ ╚████║██████╔╝"<<endl;
          cout<<"   ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚══════╝╚═╝  ╚═══╝╚═════╝ "<<endl;
      }
    }

    }


  }
