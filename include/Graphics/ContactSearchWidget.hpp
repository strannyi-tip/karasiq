//
// Created by strannyi_tip on 11.12.23.
//

#ifndef KARASIQ_CONTACTSEARCHWIDGET_HPP
#define KARASIQ_CONTACTSEARCHWIDGET_HPP

#include <QHBoxLayout>
#include <QLineEdit>
#include <QToolButton>
#include "CSSableWidget.hpp"

namespace Graphics
{
    class ContactSearchWidget final: public CSSableWidget
    {
    public:
        explicit ContactSearchWidget(QWidget *parent = nullptr);
    private:
        QHBoxLayout *hbox_layout;
        QLineEdit *search_input;
        QToolButton *search_btn;
    };
}

#endif //KARASIQ_CONTACTSEARCHWIDGET_HPP
