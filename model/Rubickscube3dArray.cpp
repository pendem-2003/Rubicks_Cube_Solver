//
// Created by pende on 05-06-2024.
//

#include "Rubickscube.h"

class Rubickscube3dArray : public Rubickscube {
private:

    void rotateFace(int ind) {
        char temp[3][3] = {};
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                temp[i][j] = cube[ind][i][j];
            }
        }
        for (int i=0;i<3;i++)cube[ind][0][i] = temp[2-i][0];
        for (int i=0;i<3;i++)cube[ind][i][2] = temp[0][i];
        for (int i=0;i<3;i++)cube[ind][2][2-i] = temp[i][2];
        for (int i=0;i<3;i++)cube[ind][2-i][0] = temp[2][2-i];
    }

public:
    char cube[6][3][3]{};

    Rubickscube3dArray() {
        for (int i=0;i<6;i++) {
            for (int j=0;j<3;j++) {
                for (int k=0;k<3;k++) {
                    cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[int(face)][row][col];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for (int i=0;i<6;i++) {
            for (int j=0;j<3;j++) {
                for (int k=0;k<3;k++) {
                    if (this->cube[i][j][k]==getColorLetter(COLOR(i)))continue;
                    return false;
                }
            }
        }
        return true;
    }

    Rubickscube &u() override {
        this->rotateFace(0);

        char temp[3] = {};
        for (int i=0;i<3;i++)temp[i] = cube[4][0][2-i];
        for (int i=0;i<3;i++)cube[4][0][2-i] = cube[1][0][2-i];
        for (int i=0;i<3;i++)cube[1][0][2-i] = cube[2][0][2-i];
        for (int i=0;i<3;i++)cube[2][0][2-i] = cube[3][0][2-i];
        for (int i=0;i<3;i++)cube[3][0][2-i] = temp[i];

        return *this;
    }

    Rubickscube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    Rubickscube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    Rubickscube &l() override {
        this->rotateFace(1);

        char temp[3] = {};
        for (int i=0;i<3;i++)temp[i] = cube[0][i][0];
        for (int i=0;i<3;i++)cube[0][i][0] = cube[4][2-i][2];
        for (int i=0;i<3;i++)cube[4][2-i][2] = cube[5][i][0];
        for (int i=0;i<3;i++)cube[5][i][0] = cube[2][i][0];
        for (int i=0;i<3;i++)cube[2][i][0] = temp[i];
    }

    Rubickscube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    Rubickscube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    Rubickscube &f() override {
        this->rotateFace(2);

        char temp[3] = {};
        for (int i=0;i<3;i++)temp[i] = cube[0][2][i];
        for (int i=0;i<3;i++)cube[0][2][i] = cube[1][2-i][2];
        for (int i=0;i<3;i++)cube[1][2-i][2] = cube[5][0][2-i];
        for (int i=0;i<3;i++)cube[5][0][2-i] = cube[3][i][0];
        for (int i=0;i<3;i++)cube[3][i][0] = temp[i];

        return *this;
    }

    Rubickscube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    Rubickscube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    Rubickscube &r() override {
        this->rotateFace(3);

        char temp[3] = {};
        for (int i=0;i<3;i++) temp[i] = cube[0][2 - i][2];
        for (int i=0;i<3;i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i=0;i<3;i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i=0;i<3;i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i=0;i<3;i++) cube[4][i][0] = temp[i];

        return *this;
    }

    Rubickscube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    Rubickscube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    Rubickscube &b() override {
        this->rotateFace(4);

        char temp[3] = {};
        for (int i=0;i<3;i++) temp[i] = cube[0][0][2 - i];
        for (int i=0;i<3;i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i=0;i<3;i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i=0;i<3;i++) cube[5][2][i] = cube[1][i][0];
        for (int i=0;i<3;i++) cube[1][i][0] = temp[i];

        return *this;
    }

    Rubickscube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    Rubickscube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    Rubickscube &d() override {
        this->rotateFace(5);

        char temp[3] = {};
        for (int i=0;i<3;i++) temp[i] = cube[2][2][i];
        for (int i=0;i<3;i++) cube[2][2][i] = cube[1][2][i];
        for (int i=0;i<3;i++) cube[1][2][i] = cube[4][2][i];
        for (int i=0;i<3;i++) cube[4][2][i] = cube[3][2][i];
        for (int i=0;i<3;i++) cube[3][2][i] = temp[i];

        return *this;
    }

    Rubickscube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    Rubickscube &d2() override {
        this->d();
        this->d();

        return *this;
    }


};
