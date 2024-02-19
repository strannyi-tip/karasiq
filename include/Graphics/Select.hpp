//
// Created by strannyi_tip on 19.12.23.
//

#ifndef KARASIQ_SELECT_HPP
#define KARASIQ_SELECT_HPP

#include <QVBoxLayout>
#include <QTimer>
#include <QMenu>

#include "CSSableWidget.hpp"
#include "SelectItem.hpp"
#include "SelectHead.hpp"
#include "SelectBody.hpp"

namespace Graphics
{
    class Select final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit Select(QWidget *parent = nullptr);
        Select *addItem(SelectItem *item);
    private:
        QGridLayout *grid_layout;
        SelectHead *head;
        QTimer *body_growth_timer;
        QTimer *body_decrease_timer;
        int body_height;
        bool is_first_item;
        QMenu *menu;
        std::map<int, SelectItem*> items;
    private slots:
        void slotOpenAccept();
        void slotCloseAccept();
    public slots:
        void slotSelectItem(const int &index);
    signals:
        void signalSetHeadDefault(const QString&, const QIcon&);
        void signalItemChanged(const QString&, const QIcon&);
        void signalItemIdChanged(const int&);
    };
}

#endif //KARASIQ_SELECT_HPP
