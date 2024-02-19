//
// Created by strannyi_tip on 12.12.23.
//

#ifndef KARASIQ_DIALOGTABS_HPP
#define KARASIQ_DIALOGTABS_HPP

#include <QTabWidget>
#include <QLabel>

namespace Graphics
{
    class DialogTabs final: public QTabWidget
    {
    public:
        explicit DialogTabs(QWidget *parent = nullptr);
    protected:
        void paintEvent(QPaintEvent *event) override;
    };
}

#endif //KARASIQ_DIALOGTABS_HPP
