//
// Created by strannyi_tip on 27.10.23.
//

#ifndef IMIN_TEXTAREA_HPP
#define IMIN_TEXTAREA_HPP

#include <QTextEdit>

namespace Graphics
{
    class TextArea: public QTextEdit
    {
        Q_OBJECT
    protected:
        void focusInEvent(QFocusEvent *e) override;
        void focusOutEvent(QFocusEvent *e) override;
        void keyPressEvent(QKeyEvent *e) override;
    signals:
        void signalFocusIn();
        void signalFocusOut();
        void signalReturnPressed(const QString &message);
    };
}

#endif //IMIN_TEXTAREA_HPP
