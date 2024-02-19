//
// Created by strannyi_tip on 12.12.23.
//

#ifndef KARASIQ_DIALOGTABVIEW_HPP
#define KARASIQ_DIALOGTABVIEW_HPP

#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include "Graphics/CSSableWidget.hpp"
#include "Entity/MessageEntity.hpp"

namespace View
{
    class DialogTabView final: public Graphics::CSSableWidget
    {
        Q_OBJECT
    public:
        explicit DialogTabView(QWidget *parent = nullptr);
        void loadFromHistory(const int &contact_id);
    private:
        QGridLayout *grid_layout;
        QVBoxLayout *vbox_layout;
        QLabel *no_messages_lbl;
        QScrollArea *scroll;
        void clearLayout();
    public slots:
        void slotUpdateDialog(const Entity::MessageEntity &entity);
    };
}

#endif //KARASIQ_DIALOGTABVIEW_HPP
