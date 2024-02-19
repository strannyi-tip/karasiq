//
// Created by strannyi_tip on 25.11.23.
//

#ifndef EXTENDEDSTATUSWIDGET_HPP
#define EXTENDEDSTATUSWIDGET_HPP

#include <QGridLayout>
#include <QComboBox>
#include <QLabel>

#include "ChatContactsWidget.hpp"
#include "CSSableWidget.hpp"
#include "Entity/ExtendedStatusEntity.hpp"

namespace Graphics
{
    class ExtendedStatusWidget final: public Graphics::CSSableWidget
    {
        Q_OBJECT
    public:
        explicit ExtendedStatusWidget(QWidget *parent = nullptr);
    private:
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
        QGridLayout *grid_layout;
        QComboBox *combo_box;
        QLabel *text_lbl;
        QToolButton *edit_btn;
    private slots:
        void slotIndexChanged(const int &index);
    public slots:
        void slotIndexResponse(const int &index) const;
        void slotTextResponse(const QString &text) const;
    signals:
        void signalIndexChanged(const int&);
    };
}

#endif //EXTENDEDSTATUSWIDGET_HPP
