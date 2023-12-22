#pragma once

#include <QPushButton>

#include "MapCell.h"

class MapCellWidget : public QPushButton
{
    Q_OBJECT

public:
    MapCellWidget(const MapCell *cell = nullptr, QWidget *parent = nullptr);

    void setOpenedStyleSheet();
    void setClosedStyleSheet();

signals:
    void opened(const MapCell &cell);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    const MapCell *m_cell = nullptr;
};

