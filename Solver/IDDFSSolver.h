//
// Created by Pendem Ganesh
//

#include <bits/stdc++.h>
#include "../Model/Rubickscube.h"
#include "DFSSolver.h"

#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H

template<typename T, typename H>
class IDDFSSolver {

private:
    int max_search_depth;
    vector<Rubickscube::MOVE> moves;


public:
    T rubickscube;

    IDDFSSolver(T _rubickscube, int _max_search_depth = 7) {
        rubickscube = _rubickscube;
        max_search_depth = _max_search_depth;
    }

//   Used DFSSolver with increasing max_search_depth and returning in minimim steps
    vector<Rubickscube::MOVE> solve() {
        for (int i=1;i<=max_search_depth;i++) {
            DFSSolver<T, H> dfssolver(rubickscube, i);
            moves = dfssolver.solve();
            if (dfssolver.rubickscube.isSolved()) {
                rubickscube = dfssolver.rubickscube;
                break;
            }
        }
        return moves;
    }
};

#endif //RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H