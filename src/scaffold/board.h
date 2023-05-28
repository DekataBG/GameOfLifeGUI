#pragma once

#include <vector>

#include "cell.h"

class Board
{
private:
    int rows, cols;

    bool isInside(int, int) const;

    void copy(const Board &);
    void free();

public:
    std::vector<ICell *> board;

    Board() = delete;
    Board(std::vector<ICell *>, int, int);
    Board(const Board &);
    Board(Board &&);
    ~Board();

    Board &operator=(const Board &);
    Board &operator=(Board &&);

    int getRows() const;
    int getCols() const;

    ICell *getCell(int, int) const;

    void prepareCell(ICell *);
    void unprepareCell(ICell *);

    void selectCell(ICell *);
    void unselectCell(ICell *);

    bool isSelected(ICell *) const;

    void print() const;
};