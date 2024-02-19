//
// Created by strannyi_tip on 19.12.23.
//

#ifndef KARASIQ_SELECTITEM_HPP
#define KARASIQ_SELECTITEM_HPP

#include <QIcon>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "CSSableWidget.hpp"

namespace Graphics
{
    class SelectItem final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit SelectItem(const QString &text, const QIcon &icon = {}, QWidget *parent = nullptr);
        SelectItem *setIconSize(const QSize &size);
        [[nodiscard]] int getID() const;
        [[nodiscard]] QIcon getIcon() const;
        [[nodiscard]] QString getText() const;
    private:
        int id;
        QHBoxLayout *hbox_layout;
        QPushButton *icon_btn;
        QLabel *text_lbl;
    protected:
        void mousePressEvent(QMouseEvent *event) override;
        void enterEvent(QEvent *event) override;
    signals:
        void signalSelected(const QString&);
        void signalSelected(const int&);
        void signalSelected(const SelectItem*);
        void signalMouseEnter(const int&);
    };
}

#endif //KARASIQ_SELECTITEM_HPP
