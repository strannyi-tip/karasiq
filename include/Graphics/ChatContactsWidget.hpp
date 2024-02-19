//
// Created by strannyi_tip on 22.11.23.
//

#ifndef CHATCONTACTSWIDGET_HPP
#define CHATCONTACTSWIDGET_HPP


#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QToolButton>

#include "CSSableWidget.hpp"
#include "ListWidget.hpp"
#include "DropDownList.hpp"
#include "ListGroup.hpp"

namespace Graphics
{
    class ChatContactsWidget final: public Graphics::CSSableWidget
    {
        Q_OBJECT
    public:
        explicit ChatContactsWidget(QWidget *parent = nullptr);
    private:
        QVBoxLayout *vbox_layout;
        QHBoxLayout *hbox_layout;
        Graphics::DropDownList *online_list;
        Graphics::DropDownList *offline_list;
        Graphics::DropDownList *inbox_list;
        QLineEdit *search_input;
        QToolButton *search_btn;
        std::vector<QListWidgetItem*> contacts;
        Graphics::ListGroup *list_group;
        Graphics::ContactList *contacts_list;
        void updateList();
        void clearLayout();
    private slots:
        void slotContactDoubleClicked(const int &index);
    public slots:
        void slotUpdateList();
    signals:
        void signalContactClicked(const int&);
    };
}

#endif //CHATCONTACTSWIDGET_HPP
