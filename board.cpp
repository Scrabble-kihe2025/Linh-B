#include "Board.h"
#include <iostream>

Board::Board() {
    clear();
}

void Board::clear() {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = ' ';
            locked[i][j] = false;
        }
}

bool Board::placeLetter(int row, int col, char letter, bool lock) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
        return false;
    if (locked[row][col])
        return false;

    grid[row][col] = letter;
    if (lock)
        locked[row][col] = true;
    return true;
}

char Board::getLetter(int row, int col) const {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
        return '\0';
    return grid[row][col];
}

bool Board::isLocked(int row, int col) const {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
        return false;
    return locked[row][col];
}

void Board::printConsole() const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
            std::cout << "[" << grid[i][j] << "]";
        std::cout << "\n";
    }
}
