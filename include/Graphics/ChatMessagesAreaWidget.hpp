//
// Created by strannyi_tip on 27.11.23.
//

#ifndef CHATBODYAREAWIDGET_HPP
#define CHATBODYAREAWIDGET_HPP

#include <QGridLayout>

#include "CSSableWidget.hpp"
#include "DialogTabs.hpp"

namespace Graphics
{
    class ChatMessagesAreaWidget final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit ChatMessagesAreaWidget(QWidget *parent = nullptr);
    private:
        QGridLayout *grid_layout;
        Graphics::DialogTabs *dialogs;
        std::map<int, QWidget*> views;
        std::map<int, QString> names;
        std::map<int, int> opened_tabs;
        void replaceDialog(const int &contact_id);
    public slots:
        void slotOpenDialog(const int &contact_id, const QString &contact_name);
    };
}

#endif //CHATBODYAREAWIDGET_HPP
