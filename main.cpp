#include <bits/stdc++.h>

#include "model/RubickscubeBitboard.cpp"
#include "model/Rubickscube1dArray.cpp"
#include "model/Rubickscube3dArray.cpp"
#include "Solver/DFSSolver.h"

using namespace std;

int main() {
    // Rubickscube1dArray c1;
    // Rubickscube3dArray c2;
    // RubickscubeBitboard c3;
    //
    // c1.print();
    // c1.r();
    // c1.print();
    //
    // cout<<c1.isSolved()<<"\n";
    //
    //
    // c2.print();
    // c2.l();
    // c2.print();
    //
    // c3.print();
    // c3.l();
    // c3.print();
    //
    // Rubickscube3dArray cl1, cl2;
    // cl1.print();
    // cl2.r();
    // cl2.print();
    // unordered_map<Rubickscube3dArray, int, Hash3d> mp;
    // mp[cl1] = 1;
    //
    // if (mp[cl1])cout<<"It is Present"<<"\n";
    // else cout<<"Not Present"<<"\n";
    //
    // if (mp[cl2])cout<<"It is Present"<<"\n";
    // else cout<<"Not Present"<<"\n";

    Rubickscube3dArray r1, r2;
    r1.print();

    vector<Rubickscube::MOVE> movestoshuffle = r1.randomShufflCube(5);
    r1.print();

    for (auto move : movestoshuffle)cout<<r1.getMove(move)<<" ";
    cout<<"\n";

    DFSSolver<Rubickscube3dArray, Hash3d> dfssolver(r1, 7);
    vector<Rubickscube::MOVE> movestosolve = dfssolver.solve();
    dfssolver.rubickscube.print();
    for (auto move : movestosolve)cout<<r1.getMove(move)<<" ";
    cout<<"\n";
    return 0;

}
