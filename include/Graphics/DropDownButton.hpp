//
// Created by strannyi_tip on 06.12.23.
//

#ifndef KARASIQ_DROPDOWNBUTTON_HPP
#define KARASIQ_DROPDOWNBUTTON_HPP

#include <QGridLayout>
#include <QLabel>
#include <QToolButton>
#include "CSSableWidget.hpp"

namespace Graphics
{
    class DropDownButton final: public CSSableWidget
    {
        Q_OBJECT
    public:
        typedef enum {
            Countable,
            Muted
        } CounterType;
        typedef enum {
            Down,
            Up
        } IconState;
        explicit DropDownButton(const QString &text, const QString &icon = {}, const CounterType &type = CounterType::Countable, QWidget *parent = nullptr);
        void setCounterType(const CounterType &type);
    private:
        QGridLayout *grid_layout;
        QLabel *title_lbl;
        QLabel *counter_lbl;
        QToolButton *icon_lbl;
        QToolButton *icon_btn;
        IconState icon_state;
        void updateCounter(const int &count);
        void toggleIcon();

    protected:
        void mousePressEvent(QMouseEvent *event) override;
    public slots:
        void slotChangeCounter(const int &count);
        void slotChangeIconState(const IconState &state);
    signals:
        void signalToggleList(const IconState&);
    };
}

#endif //KARASIQ_DROPDOWNBUTTON_HPP
