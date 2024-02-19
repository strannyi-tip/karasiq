//
// Created by strannyi_tip on 27.10.23.
//
#include <QDebug>
#include "Graphics/WindowPanel.hpp"
#include "Core/MainWindow.hpp"

Graphics::WindowPanel::WindowPanel(QWidget *parent):
grid_layout(new QGridLayout),
to_tray_btn(new QToolButton),
close_btn(new QToolButton),
fullscreen_btn(new QToolButton),
toggle_btn(new QToolButton),
status_message(new StatusMessageWidget)
{
    setFixedHeight(30);
    setObjectName("window_panel");
    toggle_btn->setObjectName("window_panel_controls");
    toggle_btn->setFixedSize({26, 26});
    toggle_btn->setIcon(QIcon(":/rsc/icons/menu.png"));
    toggle_btn->setIconSize({26, 26});
    to_tray_btn->setObjectName("window_panel_controls");
    fullscreen_btn->setObjectName("window_panel_controls");
    close_btn->setObjectName("window_panel_controls");
    to_tray_btn->setIcon(QIcon(":/rsc/icons/to_tray.png"));
    close_btn->setIcon(QIcon(":/rsc/icons/close.png"));
    fullscreen_btn->setIcon(QIcon(":/rsc/icons/fullscreen.png"));
    to_tray_btn->setFixedSize(26, 26);
    close_btn->setFixedSize(26, 26);
    fullscreen_btn->setFixedSize(26, 26);
    grid_layout->setContentsMargins(10, 5, 10, 10);
    grid_layout->addWidget(toggle_btn, 0, 0, 1, 1, Qt::AlignLeft);
    grid_layout->addWidget(status_message, 0, 1, 1, 1, Qt::AlignLeft);
    grid_layout->addWidget(to_tray_btn, 0, 2, 1, 1, Qt::AlignRight);
    grid_layout->addWidget(fullscreen_btn, 0, 3, 1, 1, Qt::AlignRight);
    grid_layout->addWidget(close_btn, 0, 4, 1, 1, Qt::AlignRight);
    grid_layout->setColumnStretch(1, 5);


    setLayout(grid_layout);

    connect(to_tray_btn, &QToolButton::clicked, this, &Graphics::WindowPanel::slotToTrayClicked);
    connect(fullscreen_btn, &QToolButton::clicked, this, &Graphics::WindowPanel::slotFullscreenClicked);
    connect(close_btn, &QToolButton::clicked, this, &Graphics::WindowPanel::slotCloseClicked);
    connect(toggle_btn, &QToolButton::clicked, this, &Graphics::WindowPanel::slotToggleMenu);
}

void Graphics::WindowPanel::slotToTrayClicked(bool) {
    Core::MainWindow::init()->setWindowState(Qt::WindowMinimized);
}

void Graphics::WindowPanel::slotFullscreenClicked(bool) {
    toggleFullscreen();
}

void Graphics::WindowPanel::slotCloseClicked(bool) {
    Core::MainWindow::init()->close();
}

void Graphics::WindowPanel::slotToggleMenu(bool) {
    emit signalToggleMenuRequest();
}

void Graphics::WindowPanel::mouseDoubleClickEvent(QMouseEvent *event) {
    QWidget::mouseDoubleClickEvent(event);
    toggleFullscreen();
}

void Graphics::WindowPanel::toggleFullscreen() {
    if (Core::MainWindow::init()->isFullScreen()) {
        Core::MainWindow::init()->showNormal();
    } else {
        Core::MainWindow::init()->showFullScreen();
    }
}

void Graphics::WindowPanel::slotChangeStatusMessage(const QString &message) {
    status_message->updateMessage(message);
}

