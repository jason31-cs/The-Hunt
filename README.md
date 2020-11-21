# The-Hunt
### Comp2113 Group Project - Grp 93
#### Contributors:
> Wong Cheuk Kiu, Nadeem Areeb
 
#### Description:
This project is a **text-based horror game**, It draws inspiration from interactive novels and puzzle games where the player is trapped in an unsettling location. Each choice that the player makes and the time that the player used will determine the likelihood of survival from an unknown creature.
 
#### Game Rules:
- Player is spawned in a map where they could make decisions on the path they want to go.
- In each location, there would be a randomly assigned puzzle, the completion of it will open up more paths
- Player can’t turn back from their decision 
- Players will have a health status
  - Losing a specific challenge or using too much time could lead to deduction of health
  - If good choices were made, it might even be possible for gaining health 
- The completion of a specific number of puzzles is required to win the game
- There would be 3 stages to the game
 - two puzzles will be assigned in random orders in the first two stages
 - the last stage will feature an ending game that is difficult to win
#### Game Features: 
1. Generation of random game sets or events:
- Whenever player starts the game, a seed would be generated. This seed would be used to conduct randomized events that the player encounters
- random features are also present in most of the puzzles:
 - riddle game would randomly show a riddle problem
 - number guessing game would have a correct number randomly chosen
 - for the tictactoe game, the computer would chose random squares
 - for the cricket game, random numbers were chosen by the computer
 - for the uno game, random cards are distributed to the computer and the player
 
2. Data structures for storing game status
variables stored in the save files:
- seed
- username
- difficulty
- health status
- game progression: stage player is in, choice that they made, health status, and puzzle completion status 

3. Dynamic memory management
      - When loading games from save files, a dynamic array is implemented in the main.cpp to store past decisions and status 
      - Implemented in the uno game after every move when list of cards is updated, whether to add cards or deduct cards
      
4. File input/output (e.g., for loading/saving game status)
Progress and seed will be stored in a file (eg. slotA) 
When player wants to quit game, progress would still be stored 
When player wants to resume, content from before could be inputted and the game will resume when the player stopped playing the game 

5. Program codes in multiple files
All puzzles are stored in puzzles.cpp
Initiation of the game is done by Intro.cpp 
A main file will be able to call on all of the necessary files to access functions
Eg. save file 

6. Proper indentation and naming styles

7. In-code documentation

