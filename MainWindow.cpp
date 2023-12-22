#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>

#include "MapWidget.h"

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timer = new QTimer();
    m_timer->start(1000);
    connect(ui->startButton, &QPushButton::clicked, ui->map, &MapWidget::refill);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::timerStart);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::timerAdd);
    ui->bombCounter->display(10);
    //connect(, &MapParams::bombCount, this, &MainWindow::bombMinus);
    m_timer->setInterval(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerStart()
{
    ui->timeCounter->display(0);
    m_timer->start();
}

void MainWindow::timerAdd()
{
    ui->timeCounter->display(ui->timeCounter->intValue() + 1);
}

void MainWindow::bombMinus()
{
    ui->bombCounter->display(ui->bombCounter->intValue() - 1);
}
