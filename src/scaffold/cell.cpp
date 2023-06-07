#include "cell.h"

Cell::Cell(int row, int col) : row(row), col(col) {}

int Cell::getRow() const
{
    return row;
}

void Cell::setRow(int row)
{
    this->row = row;
}

int Cell::getCol() const
{
    return col;
}

void Cell::setCol(int col)
{
    this->col = col;
}

bool Cell::getSelected() const
{
    return selected;
}

void Cell::setSelected(bool flag)
{
    selected = flag;
}

bool Cell::getPreparedToSelect() const
{
    return preparedToSelect;
}

void Cell::setPreparedToSelect(bool flag)
{
    preparedToSelect = flag;
}
