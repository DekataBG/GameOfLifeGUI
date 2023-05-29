#include "game.h"

#include <iostream>

int main()
{
    const int ROWS = 10, COLS = 10;

    std::vector<ICell *> cells;

    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            cells.push_back(new Cell(i, j));
        }
    }

    Board b(cells, 10, 10);
    b.selectCell(b.getCell(0, 0));
    b.selectCell(b.getCell(0, 1));
    b.selectCell(b.getCell(0, 2));
    b.selectCell(b.getCell(1, 0));
    b.selectCell(b.getCell(2, 0));
    b.selectCell(b.getCell(1, 1));

    Game game(b);

    game.playGame(5);

    return 0;
}