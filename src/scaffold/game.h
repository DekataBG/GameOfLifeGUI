#pragma once

#include "board.h"
#include "icell.h"

class Game
{
private:
    static Game *instance_ptr;

    Board board;
    Game(const Board &);

public:
    Game() = delete;
    Game(const Game &) = delete;
    Game(Game &&) = delete;

    Game &operator=(const Game &) = delete;
    Game &operator=(Game &&) = delete;

    static Game *getInstance(const Board &);

    int calculateCellNeighbors(ICell *);

    void manageCell(ICell *);
    void managePreparedCell(ICell *);

    void manageBoard();

    void playGame(int);
};