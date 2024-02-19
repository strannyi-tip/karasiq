//
// Created by strannyi_tip on 28.11.23.
//

#ifndef LISTWIDGET_HPP
#define LISTWIDGET_HPP

#include <QListWidget>
#include "Interface/Countable.hpp"

namespace Graphics
{
class ListWidget final: public QListWidget, Interface::Countable
    {
        Q_OBJECT
    public:
        explicit ListWidget(QWidget *parent = nullptr);
        int count() override;
    private slots:
        void slotDoubleClicked(const QModelIndex &index);
    signals:
        void signalDoubleClicked(const int &index);
    };
}

#endif //LISTWIDGET_HPP
