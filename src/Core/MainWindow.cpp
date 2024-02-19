//
// Created by strannyi_tip on 26.10.23.
//
#include <QApplication>
#include <QProcess>
#include "Core/MainWindow.hpp"

#include "Core/DatabasePreloader.hpp"
#include "Core/SystemPreloader.hpp"

Core::MainWindow* Core::MainWindow::instance = nullptr;
Core::MainWindow::MainWindow():
widget(new Graphics::MainWidget(this))
{
    setCentralWidget(widget);
    setMinimumSize({880, 680});
    setObjectName("main_window");
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    setWindowIcon(QIcon(":/rsc/icons/logo.png"));
    setWindowIconText("Karasiq");
    DatabasePreloader::preload();
    SystemPreloader::preload();

    connect(widget, &Graphics::MainWidget::signalCloseAppRequest, this, &MainWindow::slotCloseAppAccept);
    connect(widget, &Graphics::MainWidget::signalRestartAppRequest, this, &MainWindow::slotRestartAppRequest);
}

Core::MainWindow *Core::MainWindow::init() {
    if (nullptr == instance) {
        instance = new MainWindow;
    }

    return instance;
}

void Core::MainWindow::mousePressEvent(QMouseEvent *event) {
    position = event->pos();
}

void Core::MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (position.y() > 0 && position.y() < 30) {
        if (event->buttons() & Qt::LeftButton) {
            QPoint diff = event->pos() - position;
            QPoint new_pos = this->pos() + diff;

            this->move(new_pos);
        }
    }
}

void Core::MainWindow::moveEvent(QMoveEvent* event)
{
    widget->setParentPosition(event->pos());
    QMainWindow::moveEvent(event);
}

void Core::MainWindow::slotCloseAppAccept()
{
    qApp->quit();
}

void Core::MainWindow::slotRestartAppRequest() {
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

