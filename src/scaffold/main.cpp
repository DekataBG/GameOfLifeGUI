#include "game.h"

#include <iostream>

int main()
{
    Board b(10, 10);
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