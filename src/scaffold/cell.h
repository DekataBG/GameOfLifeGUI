#pragma once

#include "icell.h"

class Cell : public ICell
{
private:
    int row, col;
    bool selected = false, preparedToSelect = false;

    void copy(const Cell &);

public:
    Cell() = delete;
    Cell(int, int);
    Cell(const Cell &);
    Cell(Cell &&);

    int getRow() const override;
    void setRow(int) override;

    int getCol() const override;
    void setCol(int) override;

    bool getSelected() const override;
    void setSelected(bool) override;

    bool getPreparedToSelect() const override;
    void setPreparedToSelect(bool) override;
};