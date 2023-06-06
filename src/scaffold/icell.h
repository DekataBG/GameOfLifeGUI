#pragma once

class ICell
{
public:
    virtual ICell *clone() = 0;

    virtual int getRow() const = 0;
    virtual void setRow(int) = 0;

    virtual int getCol() const = 0;
    virtual void setCol(int) = 0;

    virtual bool getSelected() const = 0;
    virtual void setSelected(bool) = 0;

    virtual bool getPreparedToSelect() const = 0;
    virtual void setPreparedToSelect(bool) = 0;
};