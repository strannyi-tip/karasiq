//
// Created by strannyi_tip on 06.12.23.
//

#ifndef KARASIQ_DROPDOWNBODY_HPP
#define KARASIQ_DROPDOWNBODY_HPP

#include <QGridLayout>
#include "CSSableWidget.hpp"
#include "ListWidget.hpp"
#include "ContactList.hpp"

namespace Graphics
{
    class DropDownBody final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit DropDownBody(QWidget *parent = nullptr);
        void setList(ListWidget *new_list);
        void setList(ContactList *new_list);
    private:
        QGridLayout *grid_layout;
        void *list;
        void clearLayout();
        void setWidget(ListWidget *no_void_widget);
        void setWidget(ContactList *no_void_widget);
    private slots:
        void slotItemDoubleClickedModel(const QModelIndex &index);
        void slotItemDoubleClickedID(const int &id);
        void slotItemReturnPressed(const int &id);
    signals:
        void signalItemDoubleClicked(const int&);
        void signalItemReturnPressed(const int &id);
    };
}

#endif //KARASIQ_DROPDOWNBODY_HPP
