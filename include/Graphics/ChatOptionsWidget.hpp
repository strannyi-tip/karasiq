//
// Created by strannyi_tip on 24.11.23.
//

#ifndef CHATOPTIONSWIDGET_HPP
#define CHATOPTIONSWIDGET_HPP

#include "ChatContactsWidget.hpp"
#include "CSSableWidget.hpp"
#include "ExtendedStatusWidget.hpp"
#include "Select.hpp"

namespace Graphics
{
    class ChatOptionsWidget final: public Graphics::CSSableWidget
    {
        Q_OBJECT
    public:
        explicit ChatOptionsWidget(QWidget *parent = nullptr);
    private:
        QHBoxLayout *hbox_layout;
        Select *online_status_cb;
        Select *extended_status;
        std::vector<Entity::ExtendedStatusEntity> statuses {
                {-1, ":/rsc/icons/status/sick.png", "Болею"},
                {-1, ":/rsc/icons/status/movie.png", "Кино"},
                {-1, ":/rsc/icons/status/tired.png", "Уставший"},
                {-1, ":/rsc/icons/status/work.png", "Работаю"},
                {-1, ":/rsc/icons/status/relax.png", "Отдыхаю"},
                {-1, ":/rsc/icons/status/code.png", "Кодинг"},
                {-1, ":/rsc/icons/status/free.png", "Свободен"},
                {-1, ":/rsc/icons/status/eating.png", "Кушаю"},
                {-1, ":/rsc/icons/status/looking_for_job.png", "Ищу работу"}
        };
    private slots:
        void slotOnlineStatusChanged(const int &index);
    public slots:
        void slotExtendedStatusIndexChanged(const int &index);
        void slotOnlineStatusChangeAccept(const int &index);
    signals:
        void signalExtendedStatusIndexChanged(const int&);
        void signalOnlineStatusChanged(const int&);
    };
}

#endif //CHATOPTIONSWIDGET_HPP
