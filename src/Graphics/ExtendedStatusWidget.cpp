//
// Created by strannyi_tip on 25.11.23.
//

#include <QDebug>
#include "Graphics/ExtendedStatusWidget.hpp"

Graphics::ExtendedStatusWidget::ExtendedStatusWidget(QWidget* parent):
grid_layout(new QGridLayout),
combo_box(new QComboBox),
text_lbl(new QLabel),
edit_btn(new QToolButton)
{
    setParent(parent);
    setObjectName("extended_status");

    grid_layout->setContentsMargins({0,0,0,0});
    text_lbl->setFixedWidth(250);
    text_lbl->setObjectName("extended_status_text");
    combo_box->setFixedWidth(120);
    combo_box->setIconSize({12, 12});
    text_lbl->setAlignment(Qt::AlignLeft);
    edit_btn->setObjectName("styled_button");
    edit_btn->setFixedSize({28, 28});
    edit_btn->setIconSize({13, 13});
    edit_btn->setIcon(QIcon(":/rsc/icons/edit.png"));

    for (const auto & [id, icon, text]:statuses)
    {
        combo_box->addItem(QIcon(QString::fromStdString(icon)), QString::fromStdString(text));
    }

    grid_layout->addWidget(combo_box, 0, 0, 1, 1);
    grid_layout->addWidget(edit_btn, 0, 1, 1, 1);
    grid_layout->addWidget(text_lbl, 0, 2, 1, 1);

    setLayout(grid_layout);

    connect(combo_box, qOverload<int>(&QComboBox::currentIndexChanged), this, &Graphics::ExtendedStatusWidget::slotIndexChanged);
}

void Graphics::ExtendedStatusWidget::slotIndexChanged(const int& index)
{
    emit signalIndexChanged(index);
}

void Graphics::ExtendedStatusWidget::slotIndexResponse(const int& index) const
{
    combo_box->setCurrentIndex(index);
}

void Graphics::ExtendedStatusWidget::slotTextResponse(const QString& text) const
{
    text_lbl->setText(text);
}
