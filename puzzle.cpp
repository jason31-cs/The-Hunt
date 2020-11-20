//puzzle.cpp
#include <iostream>
#include "puzzle.h"
using namespace std;



bool puzzle_collection(int stage, int num){
  bool survived = 1;
  switch (stage){
    case 1:
      cout<<"stage 1";
    break;

    default:
      cout<< "stage out of bound"<<endl;
  }

  return survived;
}
