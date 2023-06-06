#pragma once

#include <wx/wx.h>
#include "scaffold/icell.h"

class MyCell : public wxButton, public ICell
{
private:
    int row, col;
    bool preparedToSelect = false;

public:
    MyCell(wxWindow *parent, int row, int col);

    ICell *clone() override;

    int getRow() const override;
    void setRow(int) override;

    int getCol() const override;
    void setCol(int) override;

    bool getSelected() const override;
    void setSelected(bool) override;

    bool getPreparedToSelect() const override;
    void setPreparedToSelect(bool) override;
};