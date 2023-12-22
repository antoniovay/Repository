#include <QPainter>

#include "MapCellWidget.h"

MapCellWidget::MapCellWidget(const MapCell *cell, QWidget *parent)
    : QPushButton(parent)
    , m_cell(cell)
{
    setFixedSize(40, 40);
    QFont font = this->font();
    font.setPointSize(14);
    setFont(font);

    setClosedStyleSheet();

    connect(this, &MapCellWidget::clicked, [this](){
        if (!m_cell->isOpen()) {
            emit opened(*m_cell);
        }
    });
}

void MapCellWidget::paintEvent(QPaintEvent *event)
{
    assert(m_cell);

    if (m_cell->isOpen()) {
        setOpenedStyleSheet();
    } else {
        setClosedStyleSheet();
    }

    QPushButton::paintEvent(event);
}

void MapCellWidget::setOpenedStyleSheet()
{
    setStyleSheet(
        "QPushButton {"
            "border: 0px;"
            "background-color: white;"
        "}"
    );

    switch (m_cell->value()) {
        case MapCell::Bomb:
            setText("*");
            break;
        case MapCell::Value_0:
            setText("");
            break;
        default:
            setText(QString::number(m_cell->value()));
            break;
    }
}

void MapCellWidget::setClosedStyleSheet()
{
    setStyleSheet(
        "QPushButton {"
            "background-color: lightgray;"
        "}"
    );
    setText("");
}
