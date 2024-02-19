//
// Created by strannyi_tip on 11.12.23.
//

#ifndef KARASIQ_LISTGROUP_HPP
#define KARASIQ_LISTGROUP_HPP

#include "CSSableWidget.hpp"
#include "DropDownList.hpp"

namespace Graphics
{
    class ListGroup final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit ListGroup(QWidget *parent = nullptr);
        ListGroup *addList(DropDownList *list);
    private:
        std::map<QString, DropDownList*> lists;
    private slots:
        void slotOpenList(const QString &name);
    };
}

#endif //KARASIQ_LISTGROUP_HPP
