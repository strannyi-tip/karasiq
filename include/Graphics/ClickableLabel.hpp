//
// Created by strannyi_tip on 30.12.23.
//

#ifndef KARASIQ_CLICKABLELABEL_HPP
#define KARASIQ_CLICKABLELABEL_HPP

#include <QLabel>

namespace Graphics
{
    class ClickableLabel: public QLabel
    {
        Q_OBJECT
    public:
        explicit ClickableLabel(const QString &text = {}, QWidget *parent = nullptr);
    protected:
        void mousePressEvent(QMouseEvent *event) override;
    signals:
        void signalClicked();
    };
}

#endif //KARASIQ_CLICKABLELABEL_HPP
