#include <assert.h>

#include "MapCell.h"

MapCell::MapCell(const int row, const int column)
    : m_row(row)
    , m_column(column)
{}

bool MapCell::isDigit() const
{
    return m_value >= Value_1 && m_value <= Value_8;
}

bool MapCell::isOpen() const
{
    return m_isOpen;
}

bool MapCell::hasFlag() const
{
    return m_hasFlag;
}

bool MapCell::hasBomb() const
{
    return m_value == Bomb;
}

MapCell::Value MapCell::value() const
{
    return m_value;
}

int MapCell::row() const
{
    return m_row;
}

int MapCell::column() const
{
    return m_column;
}

void MapCell::setRow(const int row)
{
    assert(row >= 0);
    m_row = row;
}

void MapCell::setColumn(const int column)
{
    assert(column >= 0);
    m_column = column;
}

void MapCell::setOpen(bool isOpen)
{
    m_isOpen = isOpen;
}

void MapCell::setFlag(bool hasFlag)
{
    m_hasFlag = hasFlag;
}

void MapCell::setValue(Value value)
{
    m_value = value;
}
