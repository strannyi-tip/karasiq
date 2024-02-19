//
// Created by strannyi_tip on 05.12.23.
//

#ifndef LABELEDINPUT_HPP
#define LABELEDINPUT_HPP

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QKeyEvent>

#include "CSSableWidget.hpp"

namespace Graphics
{
    class LabeledInput final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit LabeledInput(const QString &title, QWidget *parent = nullptr);
        QString text();
        void setText(const QString &text);
        void setAfterSpase(const int &spase);
    private:
        QVBoxLayout *vbox_layout;
        QLabel *label;
        QLineEdit *input;
    private slots:
        void slotTextChanged(const QString &text);
        void slotReturnPressed();
    signals:
        void signalTextChanged(const QString &text);
        void signalReturnPressed(const QString &text);
    };
}

#endif //LABELEDINPUT_HPP
