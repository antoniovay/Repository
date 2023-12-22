#include <QDebug>
#include <QGridLayout>
#include <QMessageBox>
#include <QPaintEvent>
#include <QPainter>

#include "MapWidget.h"


MapWidget::MapWidget(QWidget *parent)
    : MapWidget({}, parent)
{}

MapWidget::MapWidget(const MapParams &params, QWidget *parent)
    : QWidget(parent)
    , m_params(params)
    , m_map(params.rowCount, params.columnCount)
{
    m_layout = new QGridLayout();
    m_layout->setSpacing(1);
    this->setLayout(m_layout);
    fill(params);
}

void MapWidget::fill(const MapParams &params)
{
    m_params = params;
    m_needRefill = true;
    for (auto *cell : m_cells) {
        m_layout->removeWidget(cell);
        delete cell;
    }
    m_cells.clear();

    for (int i = 0; i < params.rowCount; ++i) {
        for (int j = 0; j < params.columnCount; ++j) {
            MapCellWidget *cell = new MapCellWidget(&m_map[i][j], this);
            connect(cell, &MapCellWidget::opened, this, &MapWidget::onCellOpened);
            m_layout->addWidget(cell, i, j);
        }
    }
}

void MapWidget::refill() {

    m_map.close();
    update();
    m_needRefill = true;

}

void MapWidget::onCellOpened(const MapCell &cell)
{
    if (m_needRefill) {
        m_map.fill(m_params, cell);
        m_needRefill = false;
    }
    bool gameOver = !m_map.open(cell.row(), cell.column());
    update();
    if (gameOver) {
        QMessageBox::critical(this, "GAME OVER", "Вы подорвались на мине!");
    }
}

void MapWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}
