#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstring>

using namespace std;

//Game1 for first junction
char Game_riddles() {
  
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
      return 'W';
      break;
    }

      else if (count == 2) {
      cout << "Wrong answer. Game over. You lose :(" << endl;
      return 'L';
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
        return 'W';
        break;
      }

        else if (count == 2) {
        cout << "Wrong answer. Game over. You lose :(" << endl;
        return 'L';
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
        return 'W';
        break;
      }
      else if (count == 2) {
        cout << "Game Over" << endl;
        return 'L';
      }
        
      
  }
}

//Game2 for second junction
char Game_cricket () {
  //exit guarded by cricket player
  //you have to win to escape
  //prompt user for toss
  //whoever wins toss, gets to decide whether to bat/bowl first
  //if the batsman scores 50 runs without getting out, he wins
  // if bowler takes wicket before batsman's score reaches 10, bowler wins
  // if score 10 < score < 50, target has to be beaten to win
  cout << "The exit to the corridor is guarded by a ghost, who died a 100 years ago. He used to be a cricket enthusiast in his lifetime and will not let you escape till you play with him and beat him. Terrifying as he is, you have no option but to take the challenge." << endl;
  cout << "He flips a coin to decide who gets to bat first. Do you choose 'Heads' or 'Tails'? Please input your choice (H/T). ";

  char user_toss;
  cin >> user_toss;

  int comp_toss;
  srand(time(NULL));
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

  }

  else {
    if (coin_flip == 'H') {
      cout << "Coin shows " << coin_flip << ". ";
      cout << "He chooses to bat first. You bowl." << endl;
      bat_or_bowl = "Bowl";
    }
    else {
      cout << "Coin shows " << coin_flip << ". ";
      cout << "He chooses to bowl first. You bat." << endl;
      bat_or_bowl = "Bat";
    }
  }

  int user_score = 0; //total runs made by user
  int runs_per_ball; // runs made per bowl by user/comp
  int comp_ball; // comp's bowling score
  int comp_score; // total runs made by comp
  int user_ball;

  if (bat_or_bowl == "Bat") {
    cout << "Please get prepared to start batting. He is gearing up for the first ball. Please input your score: ";
    
    comp_ball = (rand()%6) + 1;
    cin >> runs_per_ball;
    

     while (user_score < 50 && runs_per_ball != comp_ball) {
       
       cout << "Good shot! ";
       
       user_score += runs_per_ball;
       cout << "Total score: " << user_score << endl;
       cout << "Please enter your score on the next ball: ";

       cin >> runs_per_ball;
       comp_ball = (rand()%6)+1;
       
     }

     if (user_score >= 50) {
       cout << "You scored a half-century. Congratulations, you win!";

       return 'W';
     
     }

     else if ( runs_per_ball == comp_ball ) {
       cout << "You got out. It's your turn to bowl now. You have to stop him from beating your score of " << user_score << ". " << " It's your first bowl. Please input your bowling score: ";

       cin >> user_ball;
       runs_per_ball = (rand()%6)+1;
       comp_score += runs_per_ball;
        
      
       
       while (comp_score <= user_score && user_ball != runs_per_ball) {
         cout << "Not out. ";

         
         cout << "Opponent's total score: " << comp_score << endl;

         cout << "Please input next bowl's score: ";
         
         cin >> user_ball;
         runs_per_ball = (rand()%6) +1;
         comp_score += runs_per_ball;

         
         

        
         
       }

       if (comp_score  > user_score) {
         cout << "Opponent scored " << comp_score << ". " << "He beat your score. You lose :(" << endl;
         
         return 'L';
       }
       else if (user_ball == runs_per_ball) {
         cout << "Good swing. You blasted his wicket. He's out before he could beat your score. You win, Congratulations!" << endl;

         return 'W';
       }

       else if (comp_score == user_score && user_ball == runs_per_ball) {
         cout << "Match ends in a tie. However, you played well and you will be allowed to escape. Congratulations!" << endl;
         return 'W';
       }


     }






  }

  if (bat_or_bowl == "Bowl") {
    cout << "Please get prepared to start bowling. Please input your score on the first ball: ";
    
    cin >> user_ball;
    runs_per_ball = (rand()%6) + 1;
    comp_score += runs_per_ball;
  
     while (comp_score < 50 && runs_per_ball != user_ball) {

       
       
       cout << "Not out. Computer's Total score: " << comp_score << endl;
       
       cout << "Please enter your score for the next ball: ";

       cin >> user_ball;
       runs_per_ball = (rand()%6) + 1; 
       comp_score += runs_per_ball;      
       
     }

     if (comp_score >= 50) {
       cout << "He scored a half-century. You lose :(";

       return 'L';
     
     }

     else if ( runs_per_ball == user_ball ) {
       cout << "Good swing. You blasted his wicket. He's out. It's your turn to bat and beat his score of " << comp_score << "." << endl;
       
       cout << "Please input your score on the first ball: ";

       cin >> runs_per_ball;
       comp_ball = (rand()%6)+1;
       user_score += runs_per_ball;

       while (user_score <= comp_score && comp_ball != runs_per_ball) {
         cout << "Good shot! ";
         cout << "Your total score: " << user_score << endl;
         cin >> runs_per_ball;
         user_score += runs_per_ball;
         comp_ball = (rand()%6) +1;
         
       }

       if (user_score  > comp_score) {
         cout << "You beat his score. Congratulations, you win!" << endl;
         
         return 'W';
       }
       else if (comp_ball == runs_per_ball) {
         cout << "You got out before you could beat his score. you lose:(" << endl;

         return 'L';
       }

        else if (comp_score == user_score && user_ball == runs_per_ball) {
         cout << "Match ends in a tie. However, you played well and you will be allowed to escape. Congratulations!" << endl;

         return 'W';
       }


     }

  }
}
