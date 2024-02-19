//
// Created by strannyi_tip on 27.11.23.
//

#include "Graphics/ChatControlsAreaWidget.hpp"

Graphics::ChatControlsAreaWidget::ChatControlsAreaWidget(QWidget* parent):
grid_layout(new QGridLayout),
textarea(new TextArea),
smiles_btn(new QToolButton),
attach_btn(new QToolButton),
send_btn(new QToolButton)
{
    setParent(parent);
    setObjectName("chat_controls_area");
    setFixedHeight(70);

    textarea->setObjectName("textarea");
    textarea->setFixedHeight(60);
    textarea->setUndoRedoEnabled(true);

    smiles_btn->setObjectName("styled_button");
    attach_btn->setObjectName("styled_button");
    send_btn->setObjectName("styled_button");

    smiles_btn->setFixedSize({28, 28});
    attach_btn->setFixedSize({28, 28});
    send_btn->setFixedSize({60, 60});

    smiles_btn->setIconSize({20, 20});
    attach_btn->setIconSize({20, 20});
    send_btn->setIconSize({30, 30});

    smiles_btn->setIcon(QIcon(":/rsc/icons/smile.png"));
    attach_btn->setIcon(QIcon(":/rsc/icons/attach.png"));
    send_btn->setIcon(QIcon(":/rsc/icons/send.png"));

    const auto grid_controls_layout = new QGridLayout;
    grid_controls_layout->setContentsMargins({0,0,0,0});
    grid_controls_layout->setSpacing(5);
    grid_controls_layout->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    grid_controls_layout->addWidget(smiles_btn, 0, 0, 1, 1);
    grid_controls_layout->addWidget(send_btn, 0, 1, 1, 1);
    grid_controls_layout->addWidget(attach_btn, 1, 0, 1, 1);

    grid_layout->setContentsMargins({5,5,5,5});
    grid_layout->addWidget(textarea, 0, 0, 1, 1);
    grid_layout->addLayout(grid_controls_layout, 0, 1, 1, 1);

    setLayout(grid_layout);

    connect(send_btn, &QToolButton::clicked, this, &ChatControlsAreaWidget::slotSendMessage);
    connect(textarea, &TextArea::signalReturnPressed, this, &ChatControlsAreaWidget::slotReturnPressed);
}

void Graphics::ChatControlsAreaWidget::slotSendMessage() {
    emit signalSendMessageRequest(textarea->toPlainText());
}

void Graphics::ChatControlsAreaWidget::slotReturnPressed(const QString &message) {
    emit signalSendMessageRequest(message);
}
