#pragma once

#include "board.h"
#include "icell.h"

class Game
{
private:
    Board board;

public:
    Game() = delete;
    Game(const Board &);

    int calculateCellNeighbors(ICell *);

    void manageCell(ICell *);
    void managePreparedCell(ICell *);

    void manageBoard();

    void playGame(int);
};