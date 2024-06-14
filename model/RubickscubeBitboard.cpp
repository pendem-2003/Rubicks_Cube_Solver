//
// Created by Pendem Ganesh
//

#include "Rubickscube.h"

class RubickscubeBitboard : public Rubickscube {

private:

    uint64_t solved_side[6]{};

    int arr[3][3] = {{0, 1, 2},
                     {7, 8, 3},
                     {6, 5, 4}};

    uint64_t one_8 = (1<<8) - 1, one_24 = (1<<24) - 1;

    void rotateFace(int ind) {
        uint64_t side = bitboard[ind];
        side = side >> (8*6);
        bitvoard[ind] = (bitboard[ind]<<16) | (side);
    }


};