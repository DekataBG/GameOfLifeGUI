#include "cell.h"

Cell::Cell(int row, int col) : row(row), col(col) {}

Cell::Cell(const Cell &other)
{
    copy(other);
}

Cell::Cell(Cell &&other)
{
    copy(other);
}

ICell *Cell::clone()
{
    Cell *cell = new Cell(getRow(), getCol());

    cell->setSelected(getSelected());
    cell->setPreparedToSelect(getPreparedToSelect());

    return cell;
}

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

void Cell::copy(const Cell &other)
{
    row = other.row;
    col = other.col;

    selected = other.selected;
    preparedToSelect = other.preparedToSelect;
}
