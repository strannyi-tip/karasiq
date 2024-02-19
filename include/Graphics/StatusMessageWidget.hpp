//
// Created by strannyi_tip on 05.11.23.
//

#ifndef IMIN_STATUSMESSAGEWIDGET_HPP
#define IMIN_STATUSMESSAGEWIDGET_HPP

#include <QGridLayout>
#include <QLabel>
#include <QTimer>
#include "CSSableWidget.hpp"

namespace Graphics
{
    class StatusMessageWidget: public Graphics::CSSableWidget
    {
    public:
        static inline int TIMER_TIMEOUT = 500;
        explicit StatusMessageWidget(QWidget *parent = nullptr);
        void updateMessage(const QString &message);
    private:
        QGridLayout *grid_layout;
        QLabel *message_lbl;
        QTimer *timer;
        std::vector<QString> messages;
        int index;
    public slots:
        void slotDoShowMessage();
    };
}

#endif //IMIN_STATUSMESSAGEWIDGET_HPP
