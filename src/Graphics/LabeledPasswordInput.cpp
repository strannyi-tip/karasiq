//
// Created by strannyi_tip on 05.12.23.
//

#include "Graphics/LabeledPasswordInput.hpp"
#include "Graphics/VSpase.hpp"
#include "Component/FontDatabase.hpp"

Graphics::LabeledPasswordInput::LabeledPasswordInput(const QString& title, QWidget* parent):
vbox_layout(new QVBoxLayout),
label(new QLabel),
input(new PasswordInput)
{
    label->setObjectName("free_size_label");
    label->setText(title);

    vbox_layout->setContentsMargins({0, 0, 0, 0});

    vbox_layout->addWidget(label);
    vbox_layout->addWidget(input);

    setLayout(vbox_layout);

    connect(input, &PasswordInput::signalInputDataChanged, this, &LabeledPasswordInput::slotTextChanged);
    connect(input, &PasswordInput::signalInputEnterPressed, this, &LabeledPasswordInput::slotReturnPressed);
}

QString Graphics::LabeledPasswordInput::text()
{
    return input->text();
}

void Graphics::LabeledPasswordInput::setText(const QString& text)
{
    input->setText(text);
}

void Graphics::LabeledPasswordInput::slotTextChanged(const QString& text)
{
    emit signalTextChanged(text);
}

void Graphics::LabeledPasswordInput::slotReturnPressed()
{
    emit signalReturnPressed(input->text());
}

void Graphics::LabeledPasswordInput::setAfterSpase(const int &spase) {
    vbox_layout->addWidget(new VSpase(spase));
}
