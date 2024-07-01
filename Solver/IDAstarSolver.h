//
// Created by Pendem Ganesh
//

#include<bits/stdc++.h>
#include "../Model/Rubickscube.h"
//#include "../Model/PatternDatabase/PatternDatabase.h"
#include "../PatternDatabases/CornerPatternDatabase.h"

#ifndef RUBIKS_CUBE_SOLVER_IDASTARSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDASTARSOLVER_H

template<typename T, typename H>

class IDAstarSolver {
private:
    CornerPatternDatabase cornerDB;
    vector<Rubickscube::MOVE> moves;
    unordered_map<T, Rubickscube::MOVE, H> move_done;
    unordered_map<T, bool, H> visited;

    struct Node {
        T cube;
        int depth;
        int estimate;

        Node(T _cube, int _depth, int _estimate) : cube(_cube), depth(_depth), estimate(_estimate) {};
    };

    struct compareCube {
        bool operator()(pair<Node, int> const &p1, pair<Node, int> const &p2) {
            auto n1 = p1.first, n2 = p2.first;
            if (n1.depth + n1.estimate == n2.depth + n2.estimate) {
                return n1.estimate > n2.estimate;
            } else return n1.depth + n1.estimate > n2.depth + n2.estimate;
        }
    };

    void resetStructure() {
        moves.clear();
        move_done.clear();
        visited.clear();
    }

// returns {solved cube, bound}: if the cube was solved
// returns {rubrickscube, next_bound}, if the cube was not solved
    pair<T, int> IDAStar(int bound) {
//        priority_queue contains pair(Node, move done to reach that)
        priority_queue<pair<Node,int>, vector<pair<Node,int>>, compareCube> pq;
        Node start = Node(rubickscube, 0, cornerDB.getNumMoves(rubickscube));
        pq.push(make_pair(start,0));
        int next_bound = 100;
        while (!pq.empty()) {
            auto p = pq.top();
            Node node = p.first;
            pq.pop();

            if (visited[node.cube]) continue;

            visited[node.cube] = true;
            move_done[node.cube] = Rubickscube::MOVE(p.second);

            if (node.cube.isSolved()) return make_pair(node.cube, bound);
            node.depth++;
            for (int i=0;i<18;i++) {
                auto curr_move = Rubickscube::MOVE(i);
                node.cube.move(curr_move);
                if (!visited[node.cube]) {
                    node.estimate = cornerDB.getNumMoves(node.cube);
                    if (node.estimate + node.depth > bound) {
                        next_bound = min(next_bound, node.estimate + node.depth);
                    } else {
                        pq.push(make_pair(node, i));
                    }
                }
                node.cube.invert(curr_move);
            }
        }
        return make_pair((rubickscube, next_bound));
    }

public:
    T rubickscube;

    IDAstarSolver(T _rubickscube, string fileName) {
        rubickscube = _rubickscube;
        cornerDB.fromFile(fileName);
    }

    vector<Rubickscube::MOVE> solve() {
        int bound = 1;
        auto p = IDAstar(bound);
        while (p.second != bound) {
            resetStructure();
            bound = p.second;
            p = IDAstar(bound);
        }
        T solved_cube = p.first;
        assert(solved_cube.isSolved());
        T curr_cube = solved_cube;
        while (!(curr_cube == rubickscube)) {
            Rubickscube::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubickscube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};

#endif //RUBIKS_CUBE_SOLVER_IDASTARSOLVER_H