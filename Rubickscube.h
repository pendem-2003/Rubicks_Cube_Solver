//
// Created by pendeM on 05-06-2023.
//

#ifndef RUBICKSCUBE_H
#define RUBICKSCUBE_H

#include<bits/stdc++.h>
using namespace std;

/* A base class for all Rubick's Cube Models. There are various representations of Rubick's cube.
   Each one has it's own special kind of definations. This class provides a shared functanality.
   We will see which is best on Performance*/



class Rubickscube {
public:
   enum class COLOR {
      WHITE,
      GREEN,
      RED,
      BLUE,
      ORANGE,
      YELLOW
   };

   enum class FACE {
      UP,
      LEFT,
      FRONT,
      RIGHT,
      BACK,
      DOWN
   };

   enum class MOVE {
      U, UPRIME, U2,
      L, LPRIME, L2,
      F, FPRIME, F2,
      R, RPRIME, R2,
      B, BPRIME, B2,
      D, DPRIME, D2
   };

   static char getColorLetter(COLOR color);

   static string getMove(MOVE id);
};



#endif //RUBICKSCUBE_H
