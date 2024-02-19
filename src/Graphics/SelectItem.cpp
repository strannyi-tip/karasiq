//
// Created by strannyi_tip on 19.12.23.
//

#include "Graphics/SelectItem.hpp"
#include "Component/RandomIDGenerator.hpp"
#include "Component/SequentlyIDGenerator.hpp"

Graphics::SelectItem::SelectItem(const QString &text, const QIcon &icon, QWidget *parent):
hbox_layout(new QHBoxLayout),
icon_btn(new QPushButton),
text_lbl(new QLabel),
id(Component::SequentlyIDGenerator::init()->generate(true))
{
    setParent(parent);
    setObjectName("select_item");
    setFixedHeight(30);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    icon_btn->setObjectName("impersonal");
    text_lbl->setObjectName("select_text");
    icon_btn->setIcon(icon);
    icon_btn->setFixedSize({26, 26});
    text_lbl->setText(text);

    hbox_layout->addWidget(icon_btn);
    hbox_layout->addWidget(text_lbl);

    setLayout(hbox_layout);
}

Graphics::SelectItem *Graphics::SelectItem::setIconSize(const QSize &size) {
    return this;
}

void Graphics::SelectItem::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);

    emit signalSelected(id);
    emit signalSelected(text_lbl->text());
    emit signalSelected(this);
}

int Graphics::SelectItem::getID() const {
    return id;
}

QIcon Graphics::SelectItem::getIcon() const {
    return icon_btn->icon();
}

QString Graphics::SelectItem::getText() const {
    return text_lbl->text();
}

void Graphics::SelectItem::enterEvent(QEvent *event) {
    QWidget::enterEvent(event);

    emit signalMouseEnter(id);
}
