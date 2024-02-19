//
// Created by strannyi_tip on 27.12.23.
//

#ifndef KARASIQ_MAINMENUITEM_HPP
#define KARASIQ_MAINMENUITEM_HPP

#include <QHBoxLayout>
#include <QLabel>
#include <QToolButton>
#include "CSSableWidget.hpp"

namespace Graphics
{
    class MainMenuItem final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit MainMenuItem(const QString &text_id, const QString &text, const QIcon &icon, QWidget *parent = nullptr);
        QString getId();
        void select();
        void unselect();
    private:
        QHBoxLayout *hbox_layout;
        QLabel *text_lbl;
        QToolButton *icon_btn;
        QString id;
    signals:
        void signalSelected(const QString&);
        void signalMouseEnter(const QString&);
    protected:
        void mousePressEvent(QMouseEvent *event) override;
        void keyPressEvent(QKeyEvent *event) override;
        void enterEvent(QEvent *event) override;
        void leaveEvent(QEvent *event) override;
    };
}

#endif //KARASIQ_MAINMENUITEM_HPP
