//
// Created by strannyi_tip on 11.12.23.
//

#include "Graphics/ListGroup.hpp"

Graphics::ListGroup::ListGroup(QWidget *parent) {

}

Graphics::ListGroup *Graphics::ListGroup::addList(Graphics::DropDownList *list) {
    lists[list->getName()] = list;
    connect(list, &Graphics::DropDownList::signalDropOpened, this, &ListGroup::slotOpenList);

    return this;
}

void Graphics::ListGroup::slotOpenList(const QString &name) {
    for (const auto &list: lists) {
        if (list.second->getName() != name) {
            list.second->closeDrop();
        }
    }
}

