#include "my_cell.h"

MyCell::MyCell(wxWindow *parent, int row, int col)
    : wxButton(parent, wxID_ANY), row(row), col(col) {}

ICell *MyCell::clone()
{
    MyCell *cell = new MyCell(m_parent, getRow(), getCol());

    cell->setSelected(getSelected());
    cell->setPreparedToSelect(getPreparedToSelect());

    return cell;
}

int MyCell::getRow() const
{
    return row;
}

void MyCell::setRow(int row)
{
    this->row = row;
}

int MyCell::getCol() const
{
    return col;
}

void MyCell::setCol(int col)
{
    this->col = col;
}

bool MyCell::getSelected() const
{
    return this->GetBackgroundColour() == wxColour(255, 255, 0);
}

void MyCell::setSelected(bool flag)
{
    if (flag)
    {
        this->SetBackgroundColour(wxColour(255, 255, 0)); // Set yellow color
    }
    else
    {
        this->SetBackgroundColour(wxColour(192, 192, 192)); // Set gray color
    }
}

bool MyCell::getPreparedToSelect() const
{
    return preparedToSelect;
}

void MyCell::setPreparedToSelect(bool flag)
{
    preparedToSelect = flag;
}
