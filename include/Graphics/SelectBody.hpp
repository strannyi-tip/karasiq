//
// Created by strannyi_tip on 20.12.23.
//

#ifndef KARASIQ_SELECTBODY_HPP
#define KARASIQ_SELECTBODY_HPP

#include <QScrollArea>
#include "CSSableWidget.hpp"
#include "SelectItem.hpp"

namespace Graphics
{
    class SelectBody final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit SelectBody(QWidget *parent = nullptr);
        SelectBody *addItem(SelectItem *item);
        int count();
    private:
        std::vector<SelectItem*> items;
        QVBoxLayout *vbox_layout;
        QGridLayout *grid_layout;
        QWidget *scroll_widget;
        QScrollArea *scroll;
    private slots:
        void slotItemMouseEnter(const int &id);
        void slotItemSelected(const int &id);
        void slotItemSelected(const QString &text);
    signals:
        void signalItemSelected(const int&);
        void signalItemSelected(const QString&);
    };
}

#endif //KARASIQ_SELECTBODY_HPP
