#include "game.h"
#include "board.h"

Game *Game::instance_ptr = nullptr;

Game::Game(const Board &board) : board(board) {}

Game *Game::getInstance(const Board &board)
{
    if (Game::instance_ptr == nullptr)
    {
        Game::instance_ptr = new Game(board);
    }

    return instance_ptr;
}

int Game::calculateCellNeighbors(ICell *cell)
{
    int ctr = 0;

    if (board.isSelected(board.getCell(cell->getRow() - 1, cell->getCol() - 1)))
    {
        ctr++;
    }
    if (board.isSelected(board.getCell(cell->getRow() - 1, cell->getCol())))
    {
        ctr++;
    }
    if (board.isSelected(board.getCell(cell->getRow() - 1, cell->getCol() + 1)))
    {
        ctr++;
    }
    if (board.isSelected(board.getCell(cell->getRow(), cell->getCol() - 1)))
    {
        ctr++;
    }
    if (board.isSelected(board.getCell(cell->getRow(), cell->getCol() + 1)))
    {
        ctr++;
    }
    if (board.isSelected(board.getCell(cell->getRow() + 1, cell->getCol() - 1)))
    {
        ctr++;
    }
    if (board.isSelected(board.getCell(cell->getRow() + 1, cell->getCol())))
    {
        ctr++;
    }
    if (board.isSelected(board.getCell(cell->getRow() + 1, cell->getCol() + 1)))
    {
        ctr++;
    }

    return ctr;
}

void Game::manageCell(ICell *cell)
{
    int neighbors = calculateCellNeighbors(cell);

    if (board.isSelected(cell))
    {
        if (neighbors == 2 || neighbors == 3)
        {
            board.prepareCell(cell);
        }
        else
        {
            board.unprepareCell(cell);
        }
    }
    else
    {
        if (neighbors == 3)
        {
            board.prepareCell(cell);
        }
    }
}

void Game::managePreparedCell(ICell *cell)
{
    bool isPrepared = cell->getPreparedToSelect();
    cell->setSelected(isPrepared);

    board.unprepareCell(cell);
}

void Game::manageBoard()
{
    for (int i = 0; i < board.getRows(); i++)
    {
        for (int j = 0; j < board.getCols(); j++)
        {
            manageCell(board.getCell(i, j));
        }
    }

    for (int i = 0; i < board.getRows(); i++)
    {
        for (int j = 0; j < board.getCols(); j++)
        {
            managePreparedCell(board.getCell(i, j));
        }
    }
}

void Game::playGame(int rounds)
{
    board.print(); // for testing

    for (int i = 0; i < rounds; i++)
    {
        manageBoard();
        board.print(); // for testing
    }
}
