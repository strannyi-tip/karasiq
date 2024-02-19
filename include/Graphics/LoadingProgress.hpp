//
// Created by strannyi_tip on 22.12.23.
//

#ifndef KARASIQ_LOADINGPROGRESS_HPP
#define KARASIQ_LOADINGPROGRESS_HPP

#include <QVBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include "CSSableWidget.hpp"

namespace Graphics
{
    class LoadingProgress final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit LoadingProgress(const QString &title = {}, const int &count = 0, QWidget *parent = nullptr);
        void resetProgress();
        LoadingProgress *setMinimum(const int &value);
        LoadingProgress *setMaximum(const int &value);
        LoadingProgress *setTitle(const QString &title);
    private:
        QVBoxLayout *vbox_layout;
        QLabel *progress_title;
        QProgressBar *progress_bar;
        int final_count;
    public slots:
        void slotProgress(const int &value);
    signals:
        void signalComplete();
    };
}

#endif //KARASIQ_LOADINGPROGRESS_HPP
