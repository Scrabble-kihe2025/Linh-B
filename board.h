#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#pragma once
#include <string>

class Board {
public:
    static const int SIZE = 15;

    Board();

    bool placeLetter(int row, int col, char letter, bool lock = false);
    char getLetter(int row, int col) const;
    bool isLocked(int row, int col) const;

    void clear();
    void printConsole() const;

private:
    char grid[SIZE][SIZE];
    bool locked[SIZE][SIZE];
};



#endif // BOARD_H_INCLUDED
