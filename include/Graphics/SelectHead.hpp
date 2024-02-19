//
// Created by strannyi_tip on 19.12.23.
//

#ifndef KARASIQ_SELECTHEAD_HPP
#define KARASIQ_SELECTHEAD_HPP

#include <QHBoxLayout>
#include <QToolButton>
#include <QLabel>
#include "CSSableWidget.hpp"

namespace Graphics
{
    class SelectHead final: public CSSableWidget
    {
        Q_OBJECT
    public:
        enum State {
            Closed,
            Opened
        };
        explicit SelectHead(QWidget *parent = nullptr);
        void setIconSize(const QSize &size);
    private:
        QHBoxLayout *hbox_layout;
        QToolButton *icon_btn;
        QToolButton *arrow_icon;
        QLabel *text_lbl;
        State state;
        void updateState(const State &new_state);
        void applayState();
        void toggleState();
    protected:
        void mousePressEvent(QMouseEvent *event) override;
    public slots:
        void slotChangeSelected(const QString &text, const QIcon &icon);
        void slotSelectDefault(const QString &text, const QIcon &icon);
    signals:
        void signalOpenRequest();
        void signalCloseRequest();
    };
}

#endif //KARASIQ_SELECTHEAD_HPP
