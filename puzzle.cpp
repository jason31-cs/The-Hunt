//puzzle.cpp
#include <iostream>
#include <ctime>
#include "puzzle.h"
using namespace std;




bool puzzle_collection(int stage, int num){
  bool pass = 1;
  switch (stage){
    //stage 1
    case 1:
      cout<<"stage 1"<<endl;
      switch (num){
        case 1:
        cout<<"game 1" <<endl;
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
        case 1:
        cout<<"game 1" <<endl;
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
