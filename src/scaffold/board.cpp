#include <iostream>

#include "board.h"

Board::Board(std::vector<ICell *> board, int rows, int cols) : board(board), rows(rows), cols(cols) {}

Board::Board(const Board &other)
{
    copy(other);
}

Board::Board(Board &&other) : board(std::move(other.board)), rows(other.rows), cols(other.cols) {}

Board::~Board()
{
    free();
}

Board &Board::operator=(const Board &other)
{
    if (this != &other)
    {
        free();

        copy(other);
    }

    return *this;
}

Board &Board::operator=(Board &&other)
{
    if (this != &other)
    {
        free();

        board = std::move(other.board);
        rows = other.rows;
        cols = other.cols;
    }

    return *this;
}

int Board::getRows() const
{
    return rows;
}

int Board::getCols() const
{
    return cols;
}

ICell *Board::getCell(int row, int col) const
{
    if (isInside(row, col))
    {
        return board[cols * row + col];
    }

    return nullptr;
}

void Board::selectCell(ICell *cell)
{
    if (isInside(cell->getRow(), cell->getCol()))
    {
        cell->setSelected(true);
    }
}

void Board::unselectCell(ICell *cell)
{
    if (isInside(cell->getRow(), cell->getCol()))
    {
        cell->setSelected(false);
    }
}

void Board::prepareCell(ICell *cell)
{
    if (isInside(cell->getRow(), cell->getCol()))
    {
        cell->setPreparedToSelect(true);
    }
}

void Board::unprepareCell(ICell *cell)
{
    if (isInside(cell->getRow(), cell->getCol()))
    {
        cell->setPreparedToSelect(false);
    }
}

bool Board::isSelected(ICell *cell) const
{
    return cell != nullptr && isInside(cell->getRow(), cell->getCol()) && cell->getSelected();
}

void Board::print() const
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << getCell(i, j)->getSelected() << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "= = = = = = = = = =" << std::endl;
}

bool Board::isInside(int row, int col) const
{
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

void Board::copy(const Board &other)
{
    if (other.board.size())
    {
        for (size_t i = 0; i < other.rows; i++)
        {
            for (size_t j = 0; j < other.cols; j++)
            {
                board.push_back(other.board[other.cols * i + j]);
            }
        }
    }

    rows = other.rows;
    cols = other.cols;
}

void Board::free()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (board[cols * i + j] != NULL)
            {
                board[cols * i + j] = NULL;
                delete board[cols * i + j];
            }
        }
    }
}
