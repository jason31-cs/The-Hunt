# The-Hunt
### Comp2113 Group Project - Grp 93
#### Contributors:
> Wong Cheuk Kiu, Nadeem Areeb
 
#### Description:
This project is a **text-based horror game**, It draws inspiration from interactive novels and puzzle games where the player is trapped in an unsettling location. Each choice that the player makes and the time that the player used will determine the likelihood of survival from the Chucky the doll.
 
#### Game Rules:
- Player is spawned in a map where they could make decisions on the path they want to go.
- In each location, there would be a different puzzle, the completion of it will open up more paths
- Player can’t turn back from their decision 
- Time that the player has taken will be taken note of
- Alerts or texts will be outputted if player is taking too long 
- Players will have a health bar
  - Losing a specific challenge or using too much time could lead to deduction of health
- The completion of a specific number of puzzles is required to win the game
#### Game Features: 
1. Generation of random game sets or events:
Whenever player starts the game,  a random decision tree will be made which is based on the machine time as the seed for random function 
In this random tree, random junctions and events would be implemented
2. Data structures for storing game status
Variables will be used to store seed for construction of decision tree and the time the player has taken
Array will be used to store player input (decisions) 
3. Dynamic memory management
      - 	After every user input, a function will be called which makes a new array with extra space that                    stores all the player inputs, allowing for dynamic memory allocation 
      -	This way, the progress of the player could be continuously tracked and stored without having an unnecessarily big array. 
4. File input/output (e.g., for loading/saving game status)
Progress and seed will be stored in a file (eg. slotA) 
When player wants to quit game, content will be displayed
When player wants to resume, content from before could be inputted and the game will resume when the player stopped playing the game 
5. Program codes in multiple files
All puzzles and functions will be stored in multiple files
A main file will be able to call on all of the necessary files to access functions
Eg. save file 
6. Proper indentation and naming styles
7. In-code documentation

