//
// Created by Pendem Ganesh
//

#include <bits/stdc++.h>
#include "../model/Rubickscube.h"

#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

// Typename T : Rubickscube Representation used (3d, 1d, Bitboard)
// Typename H : Corresponding Hash Function

template<typename T, typename H>
class BFSSolver {
private:
    vector<Rubickscube::MOVE> moves;
    unordered_map<T, bool, H> visited;
    unordered_map<T, Rubickscube::MOVE, H> move_done;

//   bfs() -> performs breadth - first - search and returns a solved Runbricks Cube
//   move_done[] -> Back-Pointer map as to how we reached the state
    T bfs() {
        queue<T> q;
        q.push(rubickscube);
        visited[rubickscube] = true;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (it.isSolved()) {
                return it;
            }
            for (int i=0;i<18;i++) {
                auto cur_move = Rubickscube::MOVE(i);
                it.move(cur_move);
                if (!visited[it]) {
                    visited[it] = true;
                    move_done[it] = cur_move;
                    q.push(it);
                }
                it.invert(cur_move);
            }
        }
        return rubickscube;
    }

public:
    T rubickscube;

    BFSSolver(T _rubickscube) {
        rubickscube = _rubickscube;
    }

    // Performing BFS and returns the vector of moves done to solve the cube
    vector<Rubickscube::MOVE> solve() {
        T solved_cube = bfs();
        assert(solved_cube.isSolved());
        T cur_cube = solved_cube;
        while (!(cur_cube==rubickscube)) {
            Rubickscube::MOVE cur_move = move_done[cur_cube];
            moves.push_back(cur_move);
            cur_cube.invert(cur_move);
        }
        rubickscube = solved_cube;
        reverse(moves.begin(),moves.end());
        return moves;
    }
};

#endif //RUBIKS_CUBE_SOLVER_BFSSOLVER_H

