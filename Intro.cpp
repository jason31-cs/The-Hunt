#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool checkforload(string filename){
  //this function checks whether slot is empty
  // true if file exist, false if it does not
  ifstream check;
  check.open(filename);
  if (check.fail()) return 0;
  return 1;
}

struct file{
  //fn = file name, display = "empty" / "not empty"
  //exist: 1 = file exist, 0  file does not exist
  //checkexist() -> check if file exist thru function checkforload() and updates info
  //existdisplay() -> turns the bool of exist into displayable string
  //update() -> to run all member functions
  string fn, display;
  bool exist;
  void checkexist(){
    exist = checkforload(fn);
  }
  void existdisplay(){
      if (exist) display = "not empty";
      else display = "empty";
  }
  void update(){
    checkexist();
    existdisplay();
  }
};


//global variables:
const int numfiles = 3; // number of files
file files[numfiles]; //global variable for the file info
string filetoedit; //file name of file selected to be edited

void initfiles(){
  //initalizes save files
  //setting names for the save files ---------------------------------
  files[0].fn = "a.txt", files[1].fn = "b.txt", files[2].fn = "c.txt";
  //goes thru each slot and updates info
  for (int i = 0 ; i < numfiles ; i++){
    files[i].update();
  }

}


void displaysave(){
  //looks at existing files
  //displays file status (empty or not empty)
  //changes global status of file

  int width = 15; //changes spacing

  cout<< "A"<<setw(width)<<"B"<<setw(width)<<"C"<<setw(width)<<endl;
  cout<<left;
  for (int i = 0 ; i < numfiles ; i++){
    cout<<setw(width)<< files[i].display ;
  }
  cout<<endl;
}

int chooseslot(){
  char slots[numfiles]={'A','B','C'},userchoice;
  cout << "choose a slot (A/B/C): "<<endl;
  cin >> userchoice;
  while (userchoice != 'A' && userchoice != 'B' && userchoice != 'C'){
    cout << "wrong input, input A, B or C "<<endl;
    cin >> userchoice;
  }
  if (userchoice == 'A'){
    return 0;
  }
  if (userchoice == 'B'){
    return 1;
  }
  if (userchoice == 'C'){
    return 2;
  }
  return 0;
}

// add difficulty()
void newgame(){
  //This function is called when player chooses new game
  //calls for the function displaysave
  char cont ='N';
  int slot;

  cout<<"Open new game in slot"<<endl;
  //displays file status
  displaysave();

  while (cont == 'N'){
    //Lets user choose which slot to save the game at
    slot = chooseslot();
    //prompt for confirmation if file already exisits
    if (files[slot].exist){
      cout<< "File is occupied, Do you want to override? (Y/N)"<<endl;
      cin >> cont;
      while (cont != 'Y' && cont != 'N'){
        cout << "input \'Y\' for yes or  \'N\' for no" <<endl;
        cin >>cont;
      }
    }
    else cont = 'Y'; //breaks while loop
  }

  //overriding file if there are existing file, and open new file if there isnt any

  cout<<"newfile"<<endl;
  ofstream newfile;
  newfile.open(files[slot].fn);
  newfile << "NEW"; // EDIT -------------------------------------
  newfile.close();

  filetoedit = files[slot].fn; //set chosen slot as file to edit
}

void loadgame(){
  //This function is called when player choses to loadgame
  char cont = 'N';
  int slot;
  cout<<"Load a game"<<endl;
  //display file status
  displaysave();


  while (cont == 'N'){
    //Lets user choose which slot to save the game at
    slot = chooseslot();
    //prompt for confirmation if file already exisits
    if (!files[slot].exist){
      cout<< "File is empty, chose another slot"<<endl;
    }
    else cont = 'Y'; //breaks while loop
  }
  filetoedit = files[slot].fn; //set chosen slot as file to edit
}

bool new_or_load(){
  //initializes files with initfiles(), if all files are empty, the game would go straight to starting a new newgame
    //returns true, start new game
  //otherwise:
    //asks player if they want to load a save file or start a new game
    //returns boolean, true if new game, false if load game
  char input;
  bool empty = 1;
  initfiles();

  for (int i = 0 ; i < numfiles ; i++) {
    if (files[i].exist) empty = 0; //checks if there is a file that exist
  }
  if (empty) //no existing files
    return 1;



  cout<< "Do you want to start a new game or load from a save file"<<endl;
  cout<< "enter \'N\' for new game and \'L\' to load: " <<endl;
  cin >> input;
  while (input != 'N' && input != 'L'){
    cout<< "Wrong input, input \'N\' for new game and \'L\' to load" <<endl;
    cin >> input;
  }
  if (input == 'N') return 1;
  else return 0;

}

void difficulty(){
  int width = 15;
  char diff;
  cout << "Choose the difficulty level: " << "Easy" << setw(width) << "Hard" << endl;
  cout << "Please input E for or H for hard: ";
  cin >> diff;
  
  while (diff != 'E' && diff != 'H') {
    cout << "Wrong input. Please enter E for easy or H for hard: ";
    cin >> diff;
  }
  
  return diff;
  //for both difficulties, health bar will remain the same
  //for the hard option, a timer will be added
 }

void introduction (){
  string username;
  //add more details: lore, instructions ...
  cout<<"Hello there!!"<<endl;
  if (new_or_load()) {
    cout<< "starting new game..." <<endl;
    newgame();
  }
  else {
    cout<< "loading game..." <<endl;
    loadgame();
  }


}

//main to check code
int main(){
  introduction();
  cout<< filetoedit;

}
