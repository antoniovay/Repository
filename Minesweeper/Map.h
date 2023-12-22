#pragma once

#include <vector>

#include "MapCell.h"

struct MapParams
{
    int rowCount = 10;
    int columnCount = 10;
    int bombCount = 10;
};

class Map
{
public:
    Map(int rowCount = 10, int columnCount = 10);

    int rowCount() const;
    int columnCount() const;

    bool fill(const MapParams &params, const MapCell &startCell);
    bool fill(int bombCount, const MapCell &startCell);

    void switchFlag(int row, int column);
    bool open(int row, int column);
    void open();
    void close();
    void getBombCount();

    const std::vector<MapCell> &operator[](int row) const;

private:
    std::vector<MapCell *> _neighbours(int row, int column);

private:
    std::vector<std::vector<MapCell>> m_cells;
};
