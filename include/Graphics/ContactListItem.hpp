//
// Created by strannyi_tip on 17.12.23.
//

#ifndef KARASIQ_CONTACTLISTITEM_HPP
#define KARASIQ_CONTACTLISTITEM_HPP

#include <QGridLayout>
#include <QLabel>
#include <QToolButton>
#include <QKeyEvent>
#include "CSSableWidget.hpp"
#include "Entity/ContactEntity.hpp"

namespace Graphics
{
    class ContactListItem final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit ContactListItem(const Entity::ContactEntity &contact_entity);
        [[nodiscard]] int getID() const;
        void select();
        void unselect();
    private:
        QGridLayout *grid_layout;
        QLabel *name_lbl;
        QToolButton *icon_status_btn;
        QToolButton *remove_btn;
        Entity::ContactEntity entity;
    private slots:
        void slotActionRemove();
        void slotActionErase();
        void slotActionAccept();
        void slotActionInfo();
    protected:
        void mouseDoubleClickEvent(QMouseEvent *event) override;

        void mousePressEvent(QMouseEvent *event) override;

        void keyPressEvent(QKeyEvent *event) override;
    signals:
        void signalRemoveRequest(const int&);
        void signalEraseRequest(const int&);
        void signalAcceptRequest(const int&);
        void signalInfoRequest(const int&);
        void signalDoubleClicked(const int&);
        void signalReturnPressed(const int&);
        void signalSelected(const int&);
    };
}

#endif //KARASIQ_CONTACTLISTITEM_HPP
