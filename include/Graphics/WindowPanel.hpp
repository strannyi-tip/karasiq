//
// Created by strannyi_tip on 27.10.23.
//

#ifndef IMIN_WINDOWPANEL_HPP
#define IMIN_WINDOWPANEL_HPP

#include <QGridLayout>
#include <QToolButton>
#include "CSSableWidget.hpp"
#include "StatusMessageWidget.hpp"

namespace Graphics
{
    class WindowPanel: public Graphics::CSSableWidget
    {
        Q_OBJECT
    public:
        explicit WindowPanel(QWidget *parent = nullptr);
    private:
        QGridLayout *grid_layout;
        QToolButton *to_tray_btn;
        QToolButton *close_btn;
        QToolButton *fullscreen_btn;
        QToolButton *toggle_btn;
        StatusMessageWidget *status_message;
        void toggleFullscreen();
    private slots:
        void slotToTrayClicked(bool);
        void slotFullscreenClicked(bool);
        void slotCloseClicked(bool);
        void slotToggleMenu(bool);
    public slots:
        void slotChangeStatusMessage(const QString &message);
    signals:
        void signalToggleMenuRequest();

    protected:
        void mouseDoubleClickEvent(QMouseEvent *event) override;
    };
}

#endif //IMIN_WINDOWPANEL_HPP
