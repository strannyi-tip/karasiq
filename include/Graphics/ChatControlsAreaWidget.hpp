//
// Created by strannyi_tip on 27.11.23.
//

#ifndef CHATCONTROLSAREAWIDGET_HPP
#define CHATCONTROLSAREAWIDGET_HPP

#include <QGridLayout>
#include <QToolButton>

#include "CSSableWidget.hpp"
#include "TextArea.hpp"

namespace Graphics
{
    class ChatControlsAreaWidget final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit ChatControlsAreaWidget(QWidget *parent = nullptr);
    private:
        QGridLayout *grid_layout;
        TextArea *textarea;
        QToolButton *smiles_btn;
        QToolButton *attach_btn;
        QToolButton *send_btn;
    private slots:
        void slotSendMessage();
        void slotReturnPressed(const QString &message);
    signals:
        void signalSendMessageRequest(const QString&);
    };
}

#endif //CHATCONTROLSAREAWIDGET_HPP
