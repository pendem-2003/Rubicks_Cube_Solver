//
// Created by pendem Ganesh on 05-06-2023.
//

#include "Rubickscube.h"

char Rubickscube::getColorLetter (COLOR color) {
    switch(color) {
        case COLOR::BLUE:
            return 'B';
        case COLOR::RED:
            return 'R';
        case COLOR::GREEN:
            return 'G';
        case COLOR::WHITE:
            return 'W';
        case COLOR::ORANGE:
            return 'O';
        case COLOR::YELLOW:
            return 'Y';
    }
}

string Rubickscube::getMove(MOVE id) {
    switch (id) {
        case MOVE::U:
            return "U";
        case MOVE::UPRIME:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::DPRIME:
            return "D'";
        case MOVE::D2:
            return "D2";
        case MOVE::F:
            return "F";
        case MOVE::FPRIME:
            return "F'";
        case MOVE::F2:
            return "F2";
        case MOVE::B:
            return "B";
        case MOVE::BPRIME:
            return "B'";
        case MOVE::B2:
            return "B2";
        case MOVE::L:
            return "L";
        case MOVE::LPRIME:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RPRIME:
            return "R'";
        case MOVE::R2:
            return "R2";
    }
}

Rubickscube &Rubickscube::move(MOVE id) {
    switch(id) {
        case MOVE::U:
            return this->u();
        case MOVE::UPRIME:
            return this->uPrime();
        case MOVE:: U2:
            return this->u2();
        case MOVE::D:
            return this->d();
        case MOVE::DPRIME:
            return this->dPrime();
        case MOVE:: D2:
            return this->d2();
        case MOVE::L:
            return this->l();
        case MOVE::LPRIME:
            return this->lPrime();
        case MOVE:: L2:
            return this->l2();
        case MOVE::R:
            return this->r();
        case MOVE::RPRIME:
            return this->rPrime();
        case MOVE:: R2:
            return this->r2();
        case MOVE::F:
            return this->f();
        case MOVE::FPRIME:
            return this->fPrime();
        case MOVE:: F2:
            return this->f2();
        case MOVE::B:
            return this->b();
        case MOVE::BPRIME:
            return this->bPrime();
        case MOVE:: B2:
            return this->b2();
    }
}

Rubickscube &Rubickscube::invert(MOVE id) {
    switch(id) {
        case MOVE::U:
            return this->uPrime();
        case MOVE::UPRIME:
            return this->u();
        case MOVE:: U2:
            return this->u2();
        case MOVE::D:
            return this->dPrime();
        case MOVE::DPRIME:
            return this->d();
        case MOVE:: D2:
            return this->d2();
        case MOVE::L:
            return this->lPrime();
        case MOVE::LPRIME:
            return this->l();
        case MOVE:: L2:
            return this->l2();
        case MOVE::R:
            return this->rPrime();
        case MOVE::RPRIME:
            return this->r();
        case MOVE:: R2:
            return this->r2();
        case MOVE::F:
            return this->fPrime();
        case MOVE::FPRIME:
            return this->f();
        case MOVE:: F2:
            return this->f2();
        case MOVE::B:
            return this->bPrime();
        case MOVE::BPRIME:
            return this->b();
        case MOVE::B2:
            return this->b2();
    }
}

void Rubickscube::print() const{
    cout<<"Rubick's Cube :"<<"\n";
    cout<<"\n";

    for (int row=0;row<=2;row++) {

        for (int i=0;i<7;i++)cout<<" ";

        for (int col=0;col<=2;col++) {
            cout<<getColorLetter(getColor(FACE::UP, row, col)) <<" ";
        }

        cout<<"\n";

    }
    cout<<"\n";

    for (int row = 0; row<=2; row++) {

        for (int col=0;col<=2;col++) {
            cout<<getColorLetter(getColor(FACE::LEFT, row, col))<<" ";
        }
        cout<<" ";


        for (int col=0;col<=2;col++) {
            cout<<getColorLetter(getColor(FACE::FRONT, row, col))<<" ";
        }
        cout<<" ";


        for (int col=0;col<=2;col++) {
            cout<<getColorLetter(getColor(FACE::RIGHT, row, col))<<" ";
        }
        cout<<" ";


        for (int col=0;col<=2;col++) {
            cout<<getColorLetter(getColor(FACE::BACK, row, col))<<" ";
        }
        cout<<" ";

        cout<<"\n";

    }

    cout<<"\n";

    for (int row=0;row<=2;row++) {

        for (int i=0;i<7;i++)cout<<" ";

        for (int col=0;col<=2;col++) {
            cout<<getColorLetter(getColor(FACE::DOWN, row, col))<<" ";
        }

        cout<<"\n";

    }
    cout<<"\n";

}

string Rubickscube::getCornerColorString(uint8_t ind) const {
    string st = "";

    switch(ind) {
        //UFR
        case 0:
            st += getColorLetter(getColor(FACE::UP, 2, 2));
            st += getColorLetter(getColor(FACE::FRONT, 0, 2));
            st += getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;

        //UFL
        case 1:
            st += getColorLetter(getColor(FACE::UP, 2, 0));
            st += getColorLetter(getColor(FACE::FRONT, 0, 0));
            st += getColorLetter(getColor(FACE::LEFT, 0, 2));
            break;

        //UBL
        case 2:
            st += getColorLetter(getColor(FACE::UP, 0, 0));
            st += getColorLetter(getColor(FACE::BACK, 0, 2));
            st += getColorLetter(getColor(FACE::LEFT, 0, 0));
            break;

        //UBR
        case 3:
            st += getColorLetter(getColor(FACE::UP, 0, 2));
            st += getColorLetter(getColor(FACE::BACK, 0, 0));
            st += getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;

        //DFR
        case 4:
            st += getColorLetter(getColor(FACE::DOWN, 0, 2));
            st += getColorLetter(getColor(FACE::FRONT, 2, 2));
            st += getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;

        //DFL
        case 5:
            st += getColorLetter(getColor(FACE::DOWN, 0, 0));
            st += getColorLetter(getColor(FACE::FRONT, 2, 0));
            st += getColorLetter(getColor(FACE::LEFT, 2, 2));
            break;

        //DBR
        case 6:
            st += getColorLetter(getColor(FACE::DOWN, 2, 2));
            st += getColorLetter(getColor(FACE::BACK, 2, 0));
            st += getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;

        //DBL
        case 7:
            st += getColorLetter(getColor(FACE::DOWN, 2, 0));
            st += getColorLetter(getColor(FACE::BACK, 2, 2));
            st += getColorLetter(getColor(FACE::LEFT, 2, 0));
            break;
    }
    return st;
}





