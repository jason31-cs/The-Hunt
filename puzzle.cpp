//puzzle.cpp
#include <iostream>
#include <ctime>

using namespace std;

//games need to return boolean, 1 for winning, 0 for loosing
//skeleton
void puzzle_inputcheck(int & ans,string poss_ans[],int num_ans){
  bool valid = 0;
  string temp_ans;
  while (!valid){
    cin >> temp_ans;
    for (int i = 0; i < num_ans ; i++){
      if (temp_ans == poss_ans[i]){
        valid = 1;
      }
    }

    if (!valid){

      if(temp_ans == "help" ){
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
  ans = temp_ans[0]-48;
}


//stage 1 games:
//game 1 (tictactoe):


void displaygrid(char grid[][3]){
  cout <<"======================================================"<<endl;
  cout<<"column\t   1     2     3"<<endl;
  cout<<"   row"<<endl;
  cout<<"\t      |     |     "<<endl;
  cout<<"\t1  "<<grid[0][0]<<"  |  "<<grid[0][1]<<"  |  "<<grid[0][2]<<"  "<<endl;
  cout<<"\t _____|_____|_____"<<endl;
  cout<<"\t      |     |     "<<endl;
  cout<<"\t2  "<<grid[1][0]<<"  |  "<<grid[1][1]<<"  |  "<<grid[1][2]<<"  "<<endl;
  cout<<"\t _____|_____|_____"<<endl;
  cout<<"\t      |     |     "<<endl;
  cout<<"\t3  "<<grid[2][0]<<"  |  "<<grid[2][1]<<"  |  "<<grid[2][2]<<"  "<<endl;
  cout<<"\t      |     |     "<<endl;
  cout<<endl<<"======================================================"<<endl;
}

bool check_connect(char grid[][3]){
  int sum;
  //check row
  for (int r = 0 ; r < 3 ; r ++){
    sum = 0;
    for (int c = 0 ; c < 3 ; c++){
      sum += grid[r][c];
    }
    if (sum == 264 || sum == 237){
      cout<<"connected row "<< r+1 <<"!!!"<<endl;
      return 1;
    }
  }

  //check column

  for (int c = 0 ; c < 3 ; c++){
    sum = 0;
    for (int r = 0 ; r < 3 ; r++){
      sum += grid[r][c];
    }
    if (sum == 264 || sum == 237){
      cout<<"connected column "<< c+1 <<"!!!"<<endl;
      return 1;
    }
  }
  //check diagonals
  sum = 0;
  for (int i = 0 ; i < 3 ; i++){
    sum += grid[i][i];
  }
  if (sum == 264 || sum == 237){
    cout<<"connected 1st diagonal!!!"<<endl;
    return 1;
  }

  sum = 0;
  for (int i = 0 ; i < 3 ; i++){
    sum += grid[2-i][i];
  }
  if (sum == 264 || sum == 237){
    cout<<"connected 2nd diagonal!!!"<<endl;
    return 1;
  }
  return 0;
}

bool s1g1(){
  //tic tac toe
  //winner 0 = comp, 1 = player
  int row,column;
  string poss_ans[3]={"1","2","3"};
  char grid[3][3],comp = 'O', player = 'X';
  bool empty = 1, invalid = 1;
  for(int r = 0; r < 3 ; r++){
    for (int c = 0; c < 3 ; c++){
      grid[r][c] = '-';
    }
  }


  cout<< "A door right across of you, on it is a metal tablet that shows this" <<endl;
  //add grid here
  displaygrid(grid);
  cout<< "Under it is a sign that reads: To open, win against the computer"<<endl;
  cout<< "in a game of tictactoe. "<<endl;


  while(!check_connect(grid) && empty){
    invalid = 1;
    //check if user input is valid
    cout<<"Your turn, choose where to put: "<<endl;
    while(invalid){
      cout<<"Input row: "<<endl;
      puzzle_inputcheck(row,poss_ans,3);
      cout <<"Input column: "<<endl;
      puzzle_inputcheck(column,poss_ans,3);
      if(grid[row-1][column-1] == '-'){
        invalid = 0;
      }
      else{
        cout<< "Invalid, select an empty block" <<endl;
      }
    }
    //adds user input
    grid[row-1][column-1] = 'X';
    displaygrid(grid);

    if (check_connect(grid)){
      cout<<"You won!, the metal locks on the door opened up."<<endl;
      return 1;
    }
    empty = 0;
    for(int r = 0; r < 3 ; r++){
      for (int c = 0; c < 3 ; c++){
        if(grid[r][c] == '-'){
          empty = 1;
        }
      }
    }
    if (!check_connect(grid) && empty){
      cout<<"Computer's turn: "<<endl;
      //comp's move
      invalid = 1;
      while(invalid){
        row = rand()%3;
        column = rand()%3;
        if(grid[row][column] == '-'){
          invalid = 0;
        }
      }
      grid[row][column] = 'O';
      displaygrid(grid);
      if(check_connect(grid)){
        cout<< "Comp wins, a black liquid sprayed down from ontop of the door"<<endl;
        cout<< "It scorched your skin, health is deducted"<<endl;
        return 0;
      }
    }

    empty = 0;
    for(int r = 0; r < 3 ; r++){
      for (int c = 0; c < 3 ; c++){
        if(grid[r][c] == '-'){
          empty = 1;
        }
      }
    }
  }
  cout<<"TIED, unable to access door"<<endl;
  return 0;
}


//stage 2 games:
//game 1 (guessing number)
bool s2g1(){

  int userin;
  string poss_ans[10]={"1","2","3","4","5","6","7","8","9","0"};
  cout<<" "<<endl;
  cout<<"A dark corridor leading to a  chamber, there are doors covering the far end, "<<endl;
  cout<<"labelled from 0 - 9. On the ceiling you noticed that there are carvings which reads"<<endl;
  cout<<"\"10 doors appear infront of you, only one leads to your escape, guess too many times and it will be"<<endl;
  cout<<"your demise.\""<<endl;
  cout<<"Which one would you want to go through?"<<endl;
  int correctdoor = rand()%10;
  for(int tries = 3 ; tries > 0 ; tries--){
      puzzle_inputcheck(userin,poss_ans,10);
      if (userin == correctdoor){
        cout<< "You twisted the knob of the door and you can hear the locks clicking and maneuvering around the door frame"<<endl;
        cout << "You pushed the door, revealing a staircase that leads downwards."<<endl;
        cout<< "After traversing down the pathway, you landed in another huge chamber, and see..."<<endl;
        return 1;
      }
      cout<< "You twisted the knob of the door but it did not unlock, yet you hear mechanisms clicking on the ceiling"<<endl;
      if (userin < correctdoor){
        cout << "A voice wispeared in your ears saying \'bigger\'"<<endl;
      }
      else if (userin > correctdoor){
        cout << "A voice wispeared in your ears saying \'smaller\'"<<endl;
      }
      cout<<tries - 1 << " tries remaining"<<endl;
  }
  cout<<"It is too late, this time, a trap door ontop of you suddenly opened, and a dozon of snakes dropped down"<<endl;
  cout<<"A few of them bit you, health is deducted"<<endl;
  return 0;
}

//put game functions here
bool puzzle_collection(int stage, int num){
  bool pass = 1;
  switch (stage){
    //stage 1
    case 1:
      cout<<"stage 1"<<endl;
      switch (num){
        case 1: //game 1, tictactoe
        pass = s1g1();
        break;

        case 2:
        cout<<"game 2" <<endl;
        break;

        case 3:
        cout << "game 3" <<endl;
        break;

        case 4:
        cout << "game 4" <<endl;
        break;

        default:
        cout<<"game out of range"<<endl;
        cout<< "default: " << num <<endl;
      }
    break;

    //stage 2
    case 2:
      cout<<"stage 2"<<endl;
      switch (num){
        case 1: //game 1, number guessing
        pass = s2g1();
        break;

        case 2:
        cout<<"game 2" <<endl;
        break;

        case 3:
        cout << "game 3" <<endl;
        break;

        case 4:
        cout << "game 4" <<endl;
        break;

        default:
        cout<<"game out of range"<<endl;
        cout<< "default: " << num <<endl;
      }
    break;
    //stage 3
    case 3:
    cout << "ending uno"<<endl;
    break;

    default:
      cout<< "stage out of bound"<<endl;
  }
  return pass;
}
