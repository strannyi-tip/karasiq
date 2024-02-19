//
// Created by strannyi_tip on 22.12.23.
//

#include <QDebug>

#include "Graphics/LoadingProgress.hpp"

Graphics::LoadingProgress::LoadingProgress(const QString &title, const int &count, QWidget *parent):
vbox_layout(new QVBoxLayout),
progress_title(new QLabel),
progress_bar(new QProgressBar),
final_count(count)
{
    setParent(parent);
    setObjectName("loading_progress");
    setFixedHeight(80);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    progress_title->setObjectName("label");
    progress_title->setText(title);
    progress_title->setAlignment(Qt::AlignCenter);
    progress_bar->setTextVisible(false);
    progress_bar->setRange(0, final_count);
    progress_bar->setOrientation(Qt::Orientation::Horizontal);
    progress_bar->setFixedHeight(4);

    vbox_layout->setSpacing(5);
    vbox_layout->setContentsMargins({5,5,5,5});
    vbox_layout->addWidget(progress_title);
    vbox_layout->addWidget(progress_bar);

    setLayout(vbox_layout);
}

void Graphics::LoadingProgress::resetProgress() {
    progress_bar->reset();
}

void Graphics::LoadingProgress::slotProgress(const int &value) {
    progress_bar->setValue(value);
    if (value >= final_count - 1) {
        emit signalComplete();
    }
}

Graphics::LoadingProgress *Graphics::LoadingProgress::setMaximum(const int &value) {
    final_count = value;
    progress_bar->setMaximum(final_count);

    return this;
}

Graphics::LoadingProgress *Graphics::LoadingProgress::setMinimum(const int &value) {
    progress_bar->setMinimum(value);

    return this;
}

Graphics::LoadingProgress *Graphics::LoadingProgress::setTitle(const QString &title) {
    progress_title->setText(title);

    return this;
}

