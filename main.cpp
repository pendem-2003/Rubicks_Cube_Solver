#include <bits/stdc++.h>

#include "model/RubickscubeBitboard.cpp"
#include "model/Rubickscube1dArray.cpp"
#include "model/Rubickscube3dArray.cpp"

int main() {
    Rubickscube1dArray c1;
    Rubickscube3dArray c2;
    RubickscubeBitboard c3;

    c1.print();
    c1.r();
    c1.print();

    cout<<c1.isSolved()<<"\n";


    c2.print();
    c2.l();
    c2.print();

    c3.print();
    c3.l();
    c3.print();

    return 0;
}
