//
// Created by strannyi_tip on 26.10.23.
//

#ifndef IMIN_MAINWINDOW_HPP
#define IMIN_MAINWINDOW_HPP

#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>
#include "Graphics/MainWidget.hpp"

namespace Core
{
    class MainWindow: public QMainWindow
    {
        Q_OBJECT
    public:
        MainWindow(const MainWindow&)=delete;
        MainWindow &operator=(const MainWindow&)= delete;

    private:
        QPoint position;
        static MainWindow *instance;
        Graphics::MainWidget *widget;
        explicit MainWindow();
        ~MainWindow() override =default;
    public:
        static MainWindow *init();
    protected:
        void mousePressEvent(QMouseEvent *event) override;
        void mouseMoveEvent(QMouseEvent *event) override;
        void moveEvent(QMoveEvent* event) override;
    public slots:
        void slotCloseAppAccept();
        void slotRestartAppRequest();
    signals:
        void signalRestartAppRequest();
        void signalCloseAppRequest();
    };
}

#endif //IMIN_MAINWINDOW_HPP
