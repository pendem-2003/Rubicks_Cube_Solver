//
// Created by Pendem Ganesh
//

#include <bits/stdc++.h>
#include "../model/Rubickscube.h"

#ifndef RUBICKS_CUBE_SOLVE_DFSSOLVER_H
#define RUBICKS_CUBE_SOLVE_DFSSOLVER_H

// Typename T : Rubickscube represenation used (3d, 1d, Bitboard)
// Typename H : Corresponding Hash Function

template<typename T, typename H>
class DFSSolver {
private:

    vector<Rubickscube::MOVE> moves;
    int max_search_depth;

//    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        if (rubickscube.isSolved())return true;
        if (dep>max_search_depth)return false;
        for (int i=0;i<18;i++) {
            rubickscube.move(Rubickscube::MOVE(i));
            moves.push_back(Rubickscube::MOVE(i));
            if (dfs(dep+1))return true;
            moves.pop_back();
            rubickscube.invert(Rubickscube::MOVE(i));
        }
        return false;
    }


public:
    T rubickscube;

    DFSSolver(T _rubickscube, int _max_search_depth = 8) {
        rubickscube = _rubickscube;
        max_search_depth = _max_search_depth;
    }

    vector<Rubickscube::MOVE> solve() {
        dfs(1);
        return moves;
    }
};


#endif //RUBICKS_CUBE_SOLVE_DFSSOLVER_H