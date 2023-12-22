#include <algorithm>
#include <assert.h>
#include <QQueue>

#include <QDebug>

#include "Map.h"

Map::Map(int rowCount, int columnCount)
    : m_cells(rowCount, std::vector<MapCell>(columnCount, MapCell()))
{
    assert(rowCount > 0 && columnCount > 0);
}

int Map::rowCount() const
{
    return static_cast<int>(m_cells.size());
}

int Map::columnCount() const
{
    assert(m_cells.size() > 0);
    return static_cast<int>(m_cells[0].size());
}

bool Map::fill(const MapParams &params, const MapCell &startCell)
{
    m_cells.resize(params.rowCount);
    for (std::vector<MapCell> &row : m_cells) {
        row.resize(params.columnCount);
    }
    return fill(params.bombCount, startCell);
}

bool Map::fill(int bombCount, const MapCell &startCell)
{
    if (bombCount > rowCount() * columnCount() - 1) {
        return false;
    }

    for (int i = 0; i < static_cast<int>(m_cells.size()); ++i) {
        for (int j = 0; j < static_cast<int>(m_cells[i].size()); ++j) {
            m_cells[i][j].setValue(MapCell::Value_0);
            m_cells[i][j].setRow(i);
            m_cells[i][j].setColumn(j);
        }
    }

    while (bombCount) {
        int row = rand() % rowCount();
        int column = rand() % columnCount();

        bool canPlaceBomb = m_cells[row][column].value() != MapCell::Bomb &&
            (startCell.row() != row || startCell.column() != column);

        if (!canPlaceBomb) {
            continue;
        }

        m_cells[row][column].setValue(MapCell::Bomb);
        auto neighbours = _neighbours(row, column);
        for (auto *neighbour : neighbours) {
            if (!neighbour->hasBomb()) {
                neighbour->setValue(MapCell::Value(neighbour->value() + 1));
            }
        }

        --bombCount;
    }

    return true;
}

void Map::switchFlag(int row, int column)
{
    m_cells[row][column].setFlag(!m_cells[row][column].hasFlag());
}

bool Map::open(int row, int column)
{
    QQueue<MapCell *> cellsToOpen;
    cellsToOpen.append(&m_cells[row][column]);
    while (!cellsToOpen.empty()) {
        MapCell *cell = cellsToOpen.takeFirst();
        cell->setOpen(true);

        if (cell->hasBomb()) {
            return false;
        } else if (cell->value() == MapCell::Value_0) {
            auto neighbours = _neighbours(row, column);
            for (auto *neighbour : neighbours) {
                if (!neighbour->isOpen() && !cellsToOpen.contains(neighbour)) {
                    cellsToOpen.append(neighbour);
                }
            }
        }
    }
    return true;
}

void Map::open()
{
    for (std::vector<MapCell> &row : m_cells) {
        for (MapCell &cell : row) {
            cell.setOpen(true);
            cell.setFlag(false);
        }
    }
}

void Map::close()
{
    for (std::vector<MapCell> &row : m_cells) {
        for (MapCell &cell : row) {
            cell.setOpen(false);
        }
    }
}

const std::vector<MapCell> &Map::operator[](int row) const
{
    return m_cells.at(row);
}

std::vector<MapCell *> Map::_neighbours(int row, int column)
{
    std::vector<MapCell *> cells;
    for (int i = row - 1; i <= row + 1; ++i) {
        for (int j = column - 1; j <= column + 1; ++j) {
            bool isNeighbour = i >= 0 && j >= 0 && i < rowCount() && j < columnCount()
                            && !(i == row && j == column);
            if (isNeighbour) {
                cells.push_back(&m_cells[i][j]);
            }
        }
    }
    return cells;
}
