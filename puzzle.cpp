//puzzle.cpp
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

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
//game 1 (guessing number)
bool s1g1(){

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

//Riddle game(stage 1)
//This function asks the user a riddle and returns 1 if answered correctly
bool s1g2() {

  srand(time(NULL));
  string answer;
  int riddle_num = (rand()%3)+1;
  int count = 0;

  cout << """You have to answer a riddle to get access to the locker, that contains the key to the exit door. Keep in mind, you only have three attempts and one hint available. Type in 'H' to use the hint but that would cost you one attempt. So be wise.""" << endl;

  switch (riddle_num) {

    case 1:
    cout << """Q) A man looks at a painting in a museum and says, “Brothers and sisters I have none, but that man’s father is my father’s son.” Who is in the painting? (Please input a one word answer, stating the relationship of the observer of the painting with the man in it. For example, if you think the man himself is in the painting, type in 'himself') Type your answer here:  """;

    cin >> answer;

    if (answer == "H") {
      cout << "_ _ _" << endl;
      cout << "Type your answer here: ";
      cin >> answer;
      count++;
    }

    while (answer != "Son" && answer != "son" && answer != "SON" && count < 2) {
      cout << "Wrong Answer. Please try again: ";

      cin >> answer;

      if (answer == "H") {
        cout << "_ _ _" << endl;
        cout << "Try again: ";
        cin >> answer;
        count++;
      }
      count++;
    }

      if (answer == "Son" || answer == "son" || answer == "SON" ) {
      cout << "Correct answer. You win!" << endl;
      return 1;
      break;
    }

      else if (count == 2) {
      cout << "Wrong answer. Game over. You lose :(" << endl;
      return 0;
      break;
    }

    case 2:
      cout << """Q) What is so fragile that saying its name breaks it? Type your answer here: """;


      cin >> answer;

      if (answer == "H") {
      cout << "s _ l _ _ _ e" << endl;
      cout << "Type your answer here: ";
      cin >> answer;
      count++;
    }

      while (answer != "SILENCE" && answer != "silence" && answer != "Silence" && count < 2) {
        cout << "Wrong Answer. Try again: ";

        cin >> answer;

        if (answer == "H") {
          cout << "s _ l _ _ _ e" << endl;
          cout << "Try again: ";
          cin >> answer;
          count++;
        }
        count++;
      }

        if (answer == "SILENCE" || answer == "silence" || answer == "Silence" ) {
        cout << "Correct answer. You win!" << endl;
        return 1;
        break;
      }

        else if (count == 2) {
        cout << "Wrong answer. Game over. You lose :(" << endl;
        return 0;
        break;
      }

    case 3:
    cout << """Q) I follow you all the time and copy your every move, but you can’t touch me or catch me. What am I? Please type in your answer here: """;

      cin >> answer;

      if (answer == "H") {
      cout << "s _ _ _ _ w" << endl;
      cout << "Type your answer here: ";
      cin >> answer;
      count++;
    }

      while (answer != "SHADOW" && answer != "Shadow" && answer != "shadow" && count < 2) {
      cout << "Wrong answer. Try again: ";

      cin >> answer;

      if (answer == "H") {
        cout << "s _ _ d _ _" << endl;
        cout << "Type your answer here: ";
        cin >> answer;
        count++;

      }
      count++;
    }

      if (answer == "SHADOW" || answer == "Shadow" || answer == "shadow") {
        cout << "Correct answer. You win!" << endl;
        return 1;
        break;

      }
      else if (count == 2) {
        cout << "Game Over" << endl;
        return 0;
      }

  }
  return 0;
}


//stage 2 games:
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
bool s2g1(){
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
      cout<<"You won!, the metal locks on the door opened up. You opened it and see..."<<endl;
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

//Cricket game (stage 2)
bool s2g2 () {
  //exit guarded by cricket player
  //you have to win to escape
  //prompt user for toss
  //whoever wins toss, gets to decide whether to bat/bowl first
  //if the batsman scores 50 runs without getting out, he wins
  // if score 10 < score < 50, target has to be beaten to win
  cout << """The exit to the corridor is guarded by a ghost, who died a 100 years ago. He used to be a cricket enthusiast in his lifetime and will not let you escape till you play with him and beat him. Terrifying as he is, you have no option but to take the challenge.""" << endl;

  cout << "Here are the game rules: " << endl;
  cout << """1.) First a coin toss is conducted, which decides who bats first.""" << endl;
  cout << """2.) While batting/bowling, you can only input a number between 1-6. If the the number input by the user and the number chosen by the computer are the same, whoever is batting gets out.""" << endl;
  cout << """3.) If the first batsman scores 50 runs without getting out, he wins.""" << endl;
  cout << """4.) If his score is less than 50 and he gets out, the opponent will bat and has to beat first batsman's target to win.""" << endl;

  cout << endl;

  srand(time(NULL));

  cout << "He flips a coin to decide who gets to bat first. Do you choose 'Heads' or 'Tails'? Please input your choice (H/T). ";

  char user_toss;
  cin >> user_toss;
  cout << endl;

  while (user_toss != 'H' && user_toss != 'T') {
    cout << "Please input your choice again (H/T): ";
    cin >> user_toss;
    cout << endl;
  }

  int comp_toss;

  comp_toss = (rand() % 2)+1;

  char coin_flip;

  if (comp_toss == 1) {
    coin_flip = 'H';
  }
  else {
    coin_flip = 'T';
  }

  string bat_or_bowl;

  if (coin_flip == user_toss ) {
    cout << "The coin shows " << user_toss << ". ";
    cout << "You win the toss. Would you like to bat or bowl first? Please enter your choice (Bat/Bowl): ";

    cin >> bat_or_bowl;

    cout << endl;

  }

  else {
    if (coin_flip == 'H') {
      cout << "Coin shows " << coin_flip << ". ";
      cout << "He chooses to bat first. You bowl." << endl;
      cout << endl;
      bat_or_bowl = "Bowl";
    }
    else {
      cout << "Coin shows " << coin_flip << ". ";
      cout << "He chooses to bowl first. You bat." << endl;
      cout << endl;
      bat_or_bowl = "Bat";
    }
  }

  int user_score = 0; //total runs made by user
  int runs_per_ball; // runs made per bowl by user/comp
  int comp_ball; // comp's bowling score
  int comp_score = 0; // total runs made by comp
  int user_ball;

  if (bat_or_bowl == "Bat") {
    cout << "Please get prepared to start batting. He is gearing up for the first ball. Please input your score: ";

    comp_ball = (rand()%6) + 1;
    cin >> runs_per_ball;

    while (runs_per_ball < 1 || runs_per_ball > 6){
      cout << "Please enter a number in the range 1-6: "<<endl;
      cin >> runs_per_ball;
    }


     while (user_score < 50 && runs_per_ball != comp_ball) {

       cout << "Good shot! ";

       user_score += runs_per_ball;
       cout << "Total score: " << user_score << endl;

       if (user_score >= 50) {
         return 1;
       }
       cout << "Please enter your score on the next ball: ";

       cin >> runs_per_ball;
       while (runs_per_ball < 1 || runs_per_ball > 6){
         cout << "Please enter a number in the range 1-6: "<<endl;
         cin >> runs_per_ball;
       }

       comp_ball = (rand()%6)+1;

     }

     if (user_score >= 50) {
       cout << "You have secured a half-century with a score of " << user_score << ". Congratulations, you win!";

       return 1;

     }



     else if ( runs_per_ball == comp_ball ) {
       cout << "You got out. It's your turn to bowl now. You have to stop him from beating your score of " << user_score << ". " << " It's your first bowl. Please input your bowling score: ";

       cin >> user_ball;
       while (user_ball < 1 || user_ball > 6){
         cout << "Please enter a number in the range 1-6: "<<endl;
         cin >> user_ball;
       }
       runs_per_ball = (rand()%6)+1;


       if (user_ball == runs_per_ball) {
         if (user_score == comp_score) {
           cout << "wow! You blasted his wicket on the first ball. Match ends in a tie. However, he is satisfied and lets you win. Congratulations! :)" << endl;

           return 1;

         }

         else {
           cout << "Wow! You blasted his wicket on the first ball. You win. Congratulations! :)" << endl;
           return 1;
         }
       }

       comp_score += runs_per_ball;

       if (comp_score > user_score) {
         cout << "He beat your target with a score of " << comp_score << ". You lose:(" << endl;
         return 0;
       }

       while (comp_score <= user_score && user_ball !=   runs_per_ball) {
         cout << "Not out. He scored " << runs_per_ball << endl;


         cout << "Opponent's total score: " << comp_score << endl;

         cout << "Please input next bowl's score: ";

         cin >> user_ball;
         while (user_ball < 1 || user_ball > 6){
         cout << "Please enter a number in the range 1-6: "<<endl;
         cin >> user_ball;
         }

         runs_per_ball = (rand()%6) +1;

         if (comp_score == user_score && user_ball == runs_per_ball) {
         cout << "Match ends in a tie. However, you played well and you will be allowed to escape. Congratulations!" << endl;
         return 1;
       }

         if (user_ball == runs_per_ball) {
         cout << "Good swing. You blasted his wicket. He's out with a total score of " << comp_score << ". before he could beat your score. You win, Congratulations!" << endl;

         return 1;
       }



         comp_score += runs_per_ball;

         if (comp_score  > user_score) {
         cout << "Opponent scored " << comp_score << ". " << "He beat your score. You lose :(" << endl;

         return 0;
       }

     }

     }

  }

  else if (bat_or_bowl == "Bowl") {
    cout << "Please get prepared to start bowling. Please input your score on the first ball: ";

    cin >> user_ball;
    while (user_ball < 1 || user_ball > 6){
         cout << "Please enter a number in the range 1-6: "<<endl;
         cin >> user_ball;
    }
    runs_per_ball = (rand()%6) + 1;

    comp_score += runs_per_ball;

    if (user_ball == runs_per_ball) {
      cout << "Good swing! He's out on the first ball. It's your turn to bat now and beat his target of 0" << endl;
      comp_score = 0;
    }


     while (comp_score < 50 && runs_per_ball != user_ball) {



       cout << "Not out. He scored " << runs_per_ball << ". Computer's Total score: " << comp_score << endl;

       cout << "Please enter your score for the next ball: ";

       cin >> user_ball;
       while (user_ball < 1 || user_ball > 6){
         cout << "Please enter a number in the range 1-6: "<<endl;
         cin >> user_ball;
       }
       runs_per_ball = (rand()%6) + 1;

       if ( runs_per_ball == user_ball ) {
       cout << "Good swing. You blasted his wicket. He's out. It's your turn to bat and beat his score of " << comp_score << "." << endl;
       break;
       }


       comp_score += runs_per_ball;
       if (comp_score >= 50) {
       cout << "He has secured a half-century by scoring " << comp_score << ". You lose :(" << endl;

       return 0;
       }
     }

     if ( runs_per_ball == user_ball ) {

       cout << "Please input your batting score on the first ball: ";

       cin >> runs_per_ball;
       while (runs_per_ball < 1 || runs_per_ball > 6){
         cout << "Please enter a number in the range 1-6: "<<endl;
         cin >> runs_per_ball;
       }

       comp_ball = (rand()%6)+1;

       if (runs_per_ball == comp_ball) {
         if (comp_score == 0) {
         cout << "Oops, you're out on the first ball. Match ends in a tie. However, he is satisfied and lets you escape! :)" << endl;
         return 1;
         }

         else {
           cout << "Oops you're out on the first ball. You lose! :(" << endl;
           return 0;
         }
       }
       user_score += runs_per_ball;




       while (user_score <= comp_score && comp_ball != runs_per_ball) {
         cout << "Good shot! ";
         cout << "Your total score: " << user_score << endl;
         cin >> runs_per_ball;
         while (runs_per_ball < 1 || runs_per_ball > 6){
         cout << "Please enter a number in the range 1-6: "<<endl;
         cin >> runs_per_ball;
         }

         comp_ball = (rand()%6) +1;

         if (comp_ball == runs_per_ball) {
           break;
         }
         user_score += runs_per_ball;

       }

       if (user_score  > comp_score) {
         cout << "You beat his target by scoring " << user_score << ". Congratulations, you win!" << endl;

         return 1;
       }
       else if (comp_ball == runs_per_ball && user_score== comp_score) {
         cout << "You got out at a score of " << user_score << ". Match ends in a tie. However, he is satisfied and lets you escape! :)" << endl;
         return 1;
       }


       else if (comp_ball == runs_per_ball) {
         cout << "You got out with a score of " << user_score << " before you could beat his target. you lose:(" << endl;

         return 1;
       }


        else if (comp_score == user_score && user_ball == runs_per_ball) {
         cout << "Match ends in a tie. However, you played well and you will be allowed to escape. Congratulations!" << endl;

         return 0;
       }


     }
   }
  return 0;
}
//Cricket game ends here


//UNO game (stage 3)
struct card {
    string color;
    int num;
  };

//this function makes sure that the card input by the user is present in the user's list of cards
bool check_correct_input_card (card *&user_cards, int n,string user_move, int &index)  {

   if (user_move == "draw two") {
    for (int i = 0; i < n; i++){
      if (user_cards[i].color == "draw two") {
        index = i;
        return true;
      }
    }

  }
  else if (user_move == "wild") {
     for (int i = 0; i < n; i++){
      if (user_cards[i].color == "wild") {
        index = i;
        return true;
      }
     }

  }
  else if (user_move == "pass"){
    return true;
  }

  int idx = user_move.find(' ');
   char a = user_move[idx+1];

   string colour = user_move.substr(0,idx);


  for (int i = 0; i < n;i++) {
    if (colour == user_cards[i].color && int(int(a)-48) == user_cards[i].num) {

      index = i;
      return true;
    }

  }

  return false;

}
//this function returns true if the card played by the user is valid and false, if otherwise
bool check_cardincentre_and_user_move (string user_move, card card_in_round, string &wild_color, card *&user_cards, int n, int index ) {
  if (user_move == "draw two"){
    for (int i = 0; i < n;i++) {
      if (user_cards[i].color == "draw two") {
        index = i;
      }
    }
    return true;
  }
  else if (user_move == "wild" ) {
    for (int i = 0; i < n;i++) {
      if (user_cards[i].color == "wild") {
        index = i;
      }
    }
    return true;
  }
  else if (user_move == "pass"){
    return true;
  }
  int idx = user_move.find(' ');
  char a = user_move[idx+1];

  string colour = user_move.substr(0,idx);

  if (card_in_round.color == colour && card_in_round.num == int(int(a)-48)) {
    for (int i = 0; i < n; i++) {
      if (colour == user_cards[i].color && int(int(a)-48) == user_cards[i].num) {
        index = i;
      }
    }
     return true;
  }
  else if (card_in_round.color == colour) {
    for (int i = 0; i < n; i++) {
      if (user_cards[i].color == colour) {
        index = i;
      }
    }
    return true;
  }
  else if (card_in_round.num == int(int(a)-48)) {
    for (int i = 0; i < n; i++) {
      if (user_cards[i].num == int(int(a)-48)) {
        index = i;
      }
    }
    return true;
  }
  else if (card_in_round.color == "draw two" || card_in_round.color == "wild") {
    return true;
  }
  else if (colour == wild_color) {
    return true;
  }

  else {
    return false;
  }
}
//this function ensures the card played by the computer is valid and according to game rules
int comp_move (card *&b, int N, card card_in_round, int &idx, string &wild_color) {
  for (int i = 0; i < N; i++) {
    if (b[i].color == card_in_round.color && b[i].num == card_in_round.num) {
      cout << "Computer plays " << b[i].color << " " << b[i].num << endl;

      idx = i;
      return 1;

    }
    else if (b[i].color == card_in_round.color && b[i].num != card_in_round.num) {
      cout << "Computer plays a " <<b[i].color << " " << b[i].num << endl;

      idx = i;
      return 1;
    }
    else if (b[i].num == card_in_round.num && b[i].color != card_in_round.color) {
      cout << "Computer plays a " << b[i].color << " " << b[i].num << endl;

      idx = i;
      return 1;
    }


    else if (b[i].color == "draw two" ){
      cout << "Computer plays a draw two. Oops, you have to pick up 2 cards now." << endl;
      return 3;
    }
    else if (b[i].color == "wild") {
      cout << "Computer plays a wild card and chooses the colour ";
      int rand_color = (rand()%4)+1;
      if (rand_color == 1) {
      cout << "red. The color of the card in the current round is red. ";
      card_in_round.color = "red";
      wild_color = "red";
      card_in_round.num = -1;


    }
    else if (rand_color == 2) {
      cout << "blue. The color of the card in the current round is blue.";
      card_in_round.color = "blue";
      wild_color = "blue";
      card_in_round.num = -1;
    }
    else if (rand_color == 3) {
      cout << "green. The color of the card in the current round is green.";
      card_in_round.color = "green";
      wild_color = "green";
      card_in_round.num = -1;
    }
    else {
      cout << "yellow. The color of the card in the current round is yellow.";
      card_in_round.color = "yellow";
      wild_color = "yellow";
      card_in_round.num = -1;
    }
    return 4;
    }

    }
  cout << "Computer is going to pass. Your turn!" << endl;

  return 2;
  }
//this fucntion makes sure computer plays a draw two if it is present and if the user is about to win
bool check_comp_has_drawtwo (card *&b, int N, int &idx) {

  for (int i = 0; i < N; i++) {
    if (b[i].color == "draw two") {
      idx = i;
      return true;
    }

  }
  return false;

}
//this function deletes the cards played by the user and computer respectively, thus handling the dynamic lists of cards
void delete_a_card (card *&user_cards, int&n, int index) {

 for (int i = index; i < n-1; i++) {
   user_cards[i].color = user_cards[i+1].color;
   user_cards[i].num = user_cards[i+1].num;
 }

 n = n-1;

}
//this function appends new cards to the user's and computer's list of cards respectively
void add_new_cards(card *&user_cards, int &n, int new_size) {

 card * list_cards = new card[new_size];

 for (int i = 0; i < n; i++) {
   list_cards[i].color = user_cards[i].color;
   list_cards[i].num = user_cards[i].num;

 }

  int random_num;
  int random_color;
  for (int i = n; i < new_size; i++) {
     random_num = (rand()%12);
    if (random_num == 10) {
      list_cards[i].color = "wild";
    }
    else if (random_num == 11) {
     list_cards[i].color = "draw two";
    }
    else {
      list_cards[i].num = random_num;

      random_color = (rand()%4) +1;
    if (random_color == 1) {
      list_cards[i].color = "red";
    }
    else if (random_color == 2) {
      list_cards[i].color = "blue";
    }
    else if (random_color == 3) {
      list_cards[i].color = "green";
    }
    else {
      list_cards[i].color = "yellow";
    }

  }

  }



 user_cards = new card[new_size];

  for (int i = 0; i < new_size; i++) {
    user_cards[i].color = list_cards[i].color;
    user_cards[i].num = list_cards[i].num;
  }

  n = new_size;
}

bool s3_UNO() {

  srand(time(NULL));
  int random_color, random_num;

  int n = 5;
  int N = 5;

  card * user_cards = new card[n];
  card * b = new card[N];


//the following for-loops distribute cards randomly to the user and computer
  for (int i = 0; i < n; i++) {

    random_num = (rand()%12);
    if (random_num == 10) {
      user_cards[i].color = "wild";
    }
    else if (random_num == 11) {
      user_cards[i].color = "draw two";
    }
    else {
      user_cards[i].num = random_num;

      random_color = (rand()%4) +1;
    if (random_color == 1) {
      user_cards[i].color = "red";
    }
    else if (random_color == 2) {
      user_cards[i].color = "blue";
    }
    else if (random_color == 3) {
      user_cards[i].color = "green";
    }
    else {
      user_cards[i].color = "yellow";
    }
  }

 }

  for (int i = 0; i < N; i++) {
      random_num = (rand()%12);
    if (random_num == 10) {
      b[i].color = "wild";
    }
    else if (random_num == 11) {
     b[i].color = "draw two";
    }
    else {
      b[i].num = random_num;


      random_color = (rand()%4) +1;
    if (random_color == 1) {
      b[i].color = "red";
    }
    else if (random_color == 2) {
      b[i].color = "blue";
    }
    else if (random_color == 3) {
      b[i].color = "green";
    }
    else {
      b[i].color = "yellow";
    }
    }
 }

   card card_in_round;
   card_in_round.num = rand()%10;

   random_color = rand()%4;

   if (random_color == 1) {
     card_in_round.color = "red";
   }
   else if  (random_color == 2) {
     card_in_round.color = "blue";
   }
   else if  (random_color == 3) {
     card_in_round.color = "green";
   }
   else {
     card_in_round.color = "yellow";
   }

   string user_move;
   string new_color;
   string colour;
   string wild_color;
   string card;
   int index;
   int idx;
   cout<<""<<endl;
   cout<<"In front of the exit is an octopus looking creature, it raised its voice and said \" You"<<endl;
   cout<<"will not leave this place until you have won me in a game of UNO\" "<<endl;
   int needhelp;
   cout << "Do you know the rules? \'Y\' for yes, \'N\' for no"<<endl;
   string poss_ans_uno[2]={"Y","N"};
   puzzle_inputcheck(needhelp,poss_ans_uno, 2);
   needhelp+=48;
   if(needhelp == 'Y'){
     cout << """This is the UNO card game, where both you and your opponent will be initially distributed 5 random UNO cards (cards can be repeated) that include number cards (of four colors), draw two's, and wild cards. You and your opponent will play your moves on top of the card in the centre. Here are the game rules: """ << endl;

     cout << """1.) You can either play the same number card, same color card, or both, relative to the card in the centre of the current round.""" << endl;
     cout << """2.) Playing a draw two will make either player pick up two random cards.""" <<endl;
     cout << """3.) Playing a wild card will allow you to change the color of the card in the current round.""" << endl;
     cout <<"""4.) You can also pass if you are out of options, however, you will have to pick a random card then.""" << endl;
     cout << """5.) The first player to empty his list of cards wins!""" << endl;
   }




  while (n > 0 && N > 0) {

     cout << endl;
     cout << "x - - - - - - - - - -  - - - - - - -  - - - - - x" << endl;
     cout << endl;

     cout << "Your updated list of cards: " << endl;
     cout << endl;
     for (int i = 0; i < n; i++) {
       if (user_cards[i].color == "draw two") {
         cout << user_cards[i].color << endl;
       }
       else if (user_cards[i].color == "wild") {
         cout << user_cards[i].color << endl;
       }

       else {
         cout << user_cards[i].color << " " << user_cards[i].num << endl;
       }

     }

     cout << endl;

    if (card_in_round.num == -2) {
      cout << "The card in the centre is ";
      cout << "a draw two." << endl;
    }

    else if (card_in_round.num != -1) {
      cout << "The card in the centre is ";
      cout << card_in_round.color << " " << card_in_round.num << "." <<endl;
    }

    cout << endl;

    cout << "Please input your move in the correct format (for eg 'red 7'/ 'blue 8'/ 'wild'/ 'draw two!!'): ";

    getline(cin, user_move);

    cout << endl;

    bool c = check_correct_input_card (user_cards, n , user_move, index);

    while (c != true) {
      cout << "You do not have this card. Please use one of the cards from your list of cards and and provide your input in the correct format (for eg 'red 7'/ 'blue 8'/ 'wild'/ 'draw two' / 'pass'): ";
      getline(cin, user_move);

      cout << endl;

      c = check_correct_input_card (user_cards, n , user_move, index);
    }

    char y = check_cardincentre_and_user_move(user_move, card_in_round, wild_color, user_cards, n, index );



    while (y != true ) {
      cout << "This card cannot be played. Please play the correct card. " << endl;
      getline(cin, user_move);
      cout << endl;
      y = check_cardincentre_and_user_move(user_move, card_in_round, wild_color, user_cards, n, index );
    }

    if (user_move == "wild") {
      if (n == 1) {
        break;
      }
      cout << "Please type in the new colour in lowercase letter: ";
      getline(cin, new_color);
      delete_a_card (user_cards, n, index);
      if (n == 0) {
        break;
      }
      card_in_round.color = new_color;
      card_in_round.num = -1;

      if (check_comp_has_drawtwo (b, N, idx) == true && n == 1 ) {

        cout << "Oops. Computer plays a draw two." << endl;
        if (N== 1) {
          break;
        }
        cout <<" You have to pick up two cards now." << endl;
        delete_a_card (b, N, idx );
        add_new_cards (user_cards, n, n+2);
        card_in_round.color = "draw two";

      }

     else  {
       int f;
       f = comp_move(b, N, card_in_round, idx, wild_color);

       if (f ==1) {
         if (N== 1) {
           break;
         }
         card_in_round.color = b[idx].color;
         card_in_round.num = b[idx].num;
         delete_a_card(b, N, idx);
       }
       else if (f == 2) {

         add_new_cards(b, N, N+1);
       }
       else if (f==3) {
         if (N== 1) {
           break;
       }
         add_new_cards(user_cards, n, n+2);
         card_in_round.color = "draw two";
         card_in_round.num = -2;
         delete_a_card(b, N, idx);
       }
       else if( f == 4) {
         if (N== 1) {
           break;
         }
         card_in_round.num = -1;
         delete_a_card(b, N, idx);
       }

     }

    if (N==0) {
      break;
    }

   }

   else if (user_move == "pass"){
     cout << "The card in the centre remains ";
     if (card_in_round.num == -1 ){
       cout << wild_color << endl;
     }

     else {
     cout << card_in_round.color << " " << card_in_round.num << "." <<endl;
     }
     add_new_cards(user_cards, n, n+1);


    if (check_comp_has_drawtwo (b, N, idx) == true && n == 1 ) {
      if (N== 1) {
      break;
    }
    cout << "Oops. Computer plays a draw two. You have to pick up two cards now." << endl;
    delete_a_card (b, N, idx );
    add_new_cards (user_cards, n, n+2);
    card_in_round.color = "draw two";
    }

   else {
     int f;
     f = comp_move(b, N, card_in_round, idx, wild_color);

     if (f ==1) {
       if (N== 1) {
         break;
       }
       card_in_round.color = b[idx].color;
       card_in_round.num = b[idx].num;
       delete_a_card(b, N, idx);
     }
     else if (f == 2) {
       add_new_cards(b, N, N+1);
     }
     else if (f==3) {
       if (N== 1) {
         break;
       }
       add_new_cards(user_cards, n, n+2);
       card_in_round.color = "draw two";
       card_in_round.num = -2;
       delete_a_card(b, N, idx);
     }
     else if( f == 4) {
       if (N== 1) {
         break;
       }
       card_in_round.num = -1;
       delete_a_card(b, N, idx);
     }


  }

   if (N == 0) {
       break;
   }
  }
  else if (user_move != "wild" && user_move != "pass" && user_move != "draw two") {
     if( n==1) {
       break;
     }
     cout << "The card in the centre is " << user_cards[index].color << " " << user_cards[index].num << endl;
     card_in_round.color = user_cards[index].color;
     card_in_round.num = user_cards[index].num;
     delete_a_card (user_cards, n, index);
     if (n == 0) {
       break;
     }

    if (check_comp_has_drawtwo (b, N, idx) == true && n == 1 ) {
      if (N== 1) {
        break;
      }
    cout << "Oops. Computer plays a draw two. You have to pick up two cards now." << endl;
    delete_a_card (b, N, idx );
    add_new_cards (user_cards, n, n+2);
    card_in_round.color = "draw two";
    }

   else {  int f = comp_move(b, N, card_in_round, idx, wild_color);

     if (f ==1) {
       if (N== 1) {
         break;
       }
      card_in_round.color = b[idx].color;
      card_in_round.num = b[idx].num;
      delete_a_card(b, N, idx);

     }
     else if (f == 2) {
       add_new_cards(b, N, N+1);
     }
     else if (f==3) {
       if (N== 1) {
      break;
       }
       add_new_cards(user_cards, n, n+2);
       card_in_round.color = "draw two";
       card_in_round.num = -2;
       delete_a_card(b, N, idx);
     }
     else if( f == 4) {
       if (N== 1) {
         break;
       }

       card_in_round.num = -1;
       delete_a_card(b, N, idx);
     }
   }

   if (N == 0) {
       break;
   }
  }


  else if (user_move == "draw two" ) {
    if( n ==1) {
      break;
    }
    cout << "The card in the centre is a draw two" << endl;
    delete_a_card (user_cards, n, index);
    if (n == 0) {
       break;
    }
    card_in_round.color = "draw two";
    card_in_round.num = -2;
    add_new_cards(b, N, N+2);

    if (check_comp_has_drawtwo (b, N, idx) == true && n == 1 ) {
      if (N== 1) {
        break;
      }
      cout << "Oops. Computer plays a draw two. You have to pick up two cards now." << endl;
      delete_a_card (b, N, idx );
      add_new_cards (user_cards, n, n+2);
      card_in_round.color = "draw two";
    }

    else {
      int rando = rand()%N;
      delete_a_card(b, N, rando);
      if (b[rando].color == "draw two") {

        cout << "Computer plays a " << b[rando].color << "card. You have to pick up two cards now." << endl;
        add_new_cards(user_cards, n, n+2);

        card_in_round.color = "draw two";
        card_in_round.num = -2;
      }

      else if (b[rando].color == "wild") {
        cout << "Computer plays a wild card and chooses the color ";
        int rand_color = (rand()%4)+1;
        if (rand_color == 1) {
        cout << "red.";
        card_in_round.color = "red";

        card_in_round.num = -1;

        }
      else if (rand_color == 2) {
        cout << "blue.";
        card_in_round.color = "blue";

        card_in_round.num = -1;
      }
      else if (rand_color == 3) {
        cout << "green.";
        card_in_round.color = "green";

        card_in_round.num = -1;
      }
      else {
        cout << "yellow.";
        card_in_round.color = "yellow";

        card_in_round.num = -1;
      }

    }

    else if (b[rando].color != "draw two" && b[rando].color != "wild") {

      cout << "Computer plays a " << b[rando].color << " " << b[rando].num << endl;
      card_in_round.color = b[rando].color;
      card_in_round.num = b[rando].num;
    }


  }
    if (N == 0) {
       break;
    }

   }

  }


  if (n == 0 || n == 1) {
    cout << "you win!" << endl;
    return 1;
    cout << endl;

  }

  else if (N == 0 || N == 1) {
    cout << "You lose!" << endl;
    return 0;
    cout << endl;
  }
  else return 0;

}

//put game functions here
bool puzzle_collection(int stage, int num){
  bool pass = 1;
  switch (stage){
    //stage 1
    case 1:
      switch (num){
        case 1: //game 1, tictactoe
          pass = s1g1();
          break;

        case 2:
          pass = s1g2();
          break;

        default:
        cout<<"game out of range"<<endl;
        cout<< "default: " << num <<endl;
      }
    break;

    //stage 2
    case 2:
      switch (num){
        case 1: //game 1, number guessing
          pass = s2g1();
          break;
        case 2:
          pass = s2g2();
          break;

        default:
        cout<<"game out of range"<<endl;
        cout<< "default: " << num <<endl;
      }
    break;
    //stage 3
    case 3:
      pass = s3_UNO();
      break;

    default:
      cout<< "stage out of bound"<<endl;
  }
  return pass;
}
