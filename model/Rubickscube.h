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

   //Return first letter of the colour
   //Eg : GREEN gives G
   static char getColorLetter(COLOR color);

   //Return move is string Format
   static string getMove(MOVE id);

   //Peform a move on cube with id face
   Rubickscube &move(MOVE id);

   //Perform invert move on cube with id face
   Rubickscube &invert(MOVE id);

   //Printing the whole cube configuratiom
   void print() const;

   virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

   virtual bool isSolved() const = 0;

   virtual Rubickscube &f() = 0;

   virtual Rubickscube &fPrime() = 0;

   virtual Rubickscube &f2() = 0;

   virtual Rubickscube &b() = 0;

   virtual Rubickscube &bPrime() = 0;

   virtual Rubickscube &b2() = 0;

   virtual Rubickscube &r() = 0;

   virtual Rubickscube &rPrime() = 0;

   virtual Rubickscube &r2() = 0;

   virtual Rubickscube &l() = 0;

   virtual Rubickscube &lPrime() = 0;

   virtual Rubickscube &l2() = 0;

   virtual Rubickscube &u() = 0;

   virtual Rubickscube &uPrime() = 0;

   virtual Rubickscube &u2() = 0;

   virtual Rubickscube &d() = 0;

   virtual Rubickscube &dPrime() = 0;

   virtual Rubickscube &d2() = 0;

   string getCornerColorString(uint8_t ind) const;

   uint8_t getCornerIndex(uint8_t ind) const;

   uint8_t getCornerOrientation(uint8_t ind) const;


   //Shuffle the cube with 'times' moves and return the moves performed
   vector<MOVE> randomShufflCube(unsigned int times);

};



#endif //RUBICKSCUBE_H
