#pragma once

#include <QWidget>

#include "Map.h"
#include "MapCellWidget.h"

class QGridLayout;

class MapWidget : public QWidget
{
public:
    MapWidget(QWidget *parent = nullptr);
    MapWidget(const MapParams &params = {}, QWidget *parent = nullptr);


    void fill(const MapParams &params);
    void refill();

public slots:
    void onCellOpened(const MapCell &cell);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    bool m_needRefill = true;
    MapParams m_params;
    Map m_map;
    QGridLayout *m_layout = nullptr;
    QVector<MapCellWidget *>m_cells;
};

