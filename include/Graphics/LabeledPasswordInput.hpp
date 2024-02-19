//
// Created by strannyi_tip on 05.12.23.
//

#ifndef LABELEDPASSWORDINPUT_HPP
#define LABELEDPASSWORDINPUT_HPP

#include <QVBoxLayout>
#include <QLabel>

#include "CSSableWidget.hpp"
#include "PasswordInput.hpp"

namespace Graphics
{
    class LabeledPasswordInput final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit LabeledPasswordInput(const QString &title, QWidget *parent = nullptr);
        QString text();
        void setText(const QString &text);
        void setAfterSpase(const int &spase);
    private:
        QVBoxLayout *vbox_layout;
        QLabel *label;
        PasswordInput *input;
    private slots:
        void slotTextChanged(const QString &text);
        void slotReturnPressed();
    signals:
        void signalTextChanged(const QString &text);
        void signalReturnPressed(const QString &text);
    };
}

#endif //LABELEDPASSWORDINPUT_HPP
