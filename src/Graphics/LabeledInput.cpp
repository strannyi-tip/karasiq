//
// Created by strannyi_tip on 05.12.23.
//

#include "Graphics/LabeledInput.hpp"
#include "Graphics/VSpase.hpp"
#include "Component/FontDatabase.hpp"

Graphics::LabeledInput::LabeledInput(const QString& title, QWidget* parent):
vbox_layout(new QVBoxLayout),
label(new QLabel),
input(new QLineEdit)
{
    setObjectName("labeled_input");
    label->setObjectName("free_size_label");
    input->setObjectName("input");
    label->setText(title);

    vbox_layout->setContentsMargins({0, 0, 0, 0});
    vbox_layout->setSpacing(5);

    vbox_layout->addWidget(label);
    vbox_layout->addWidget(input);

    setLayout(vbox_layout);

    connect(input, &QLineEdit::textChanged, this, &LabeledInput::slotTextChanged);
    connect(input, &QLineEdit::returnPressed, this, &LabeledInput::slotReturnPressed);
}

QString Graphics::LabeledInput::text()
{
    return input->text();
}

void Graphics::LabeledInput::setText(const QString& text)
{
    input->setText(text);
}

void Graphics::LabeledInput::slotTextChanged(const QString& text)
{
    emit signalTextChanged(text);
}

void Graphics::LabeledInput::slotReturnPressed()
{
    emit signalReturnPressed(input->text());
}

void Graphics::LabeledInput::setAfterSpase(const int &spase) {
    vbox_layout->addWidget(new VSpase(spase));
}
