//
// Created by strannyi_tip on 06.12.23.
//

#ifndef DROPDOWNLIST_HPP
#define DROPDOWNLIST_HPP


#include <QGridLayout>
#include <QLabel>

#include "CSSableWidget.hpp"
#include "ListWidget.hpp"
#include "DropDownButton.hpp"
#include "DropDownBody.hpp"
#include "Interface/Countable.hpp"

namespace Graphics
{
    class DropDownList final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit DropDownList(const QString &text, const QString &icon = {}, const DropDownButton::CounterType &type = DropDownButton::CounterType::Countable, QWidget *parent = nullptr);
        template <typename T>
        void setList(T *list) {
            body->setList(list);
            emit signalCounterChanged(list->count());
        }
        void setName(const QString &unique_name);
        QString getName();
        void closeDrop();
        void openDrop();
        void setCounterType(const DropDownButton::CounterType &type);
    private:
        QGridLayout *main_grid_layout;
        DropDownButton *head;
        DropDownBody *body;
        QString name;
    public slots:
        void slotToggleList(const DropDownButton::IconState &state);
    private slots:
        void slotItemDoubleClicked(const int &index);
        void slotItemReturnPressed(const int &index);
    signals:
        void signalCounterChanged(const int&);
        void signalDropOpened(const QString &name);
        void signalDropClosed(const QString &name);
        void signalChangeHeadIconState(const DropDownButton::IconState&);
        void signalDoubleClicked(const int&);
    };
}

#endif //DROPDOWNLIST_HPP
