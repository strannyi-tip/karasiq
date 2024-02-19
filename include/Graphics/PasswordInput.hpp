//
// Created by strannyi_tip on 06.11.23.
//

#ifndef IMIN_PASSWORDINPUT_HPP
#define IMIN_PASSWORDINPUT_HPP

#include <QLineEdit>
#include <QGridLayout>
#include <QToolButton>
#include <QKeyEvent>
#include "CSSableWidget.hpp"

namespace Graphics
{
    class PasswordInput: public Graphics::CSSableWidget
    {
        Q_OBJECT
    public:
        explicit PasswordInput(QWidget *parent = nullptr);
        QString text();
        void clear();
        void setText(const QString &text);
    private:
        static const inline QString VISIBLE_ICON = ":/rsc/icons/open_eye.png";
        static const inline QString INVISIBLE_ICON = ":/rsc/icons/close_eye.png";
        QGridLayout *grid_layout;
        QLineEdit *visible_input;
        QToolButton *visibility_btn;
        bool is_visible;
        void updateVisibilityIcon();
    protected:
        void keyPressEvent(QKeyEvent *event) override;
    public slots:
        void slotInputDataChanged(const QString &data);
        void slotToggleVisibility(bool);
    signals:
        void signalInputDataChanged(const QString &data);
        void signalInputEnterPressed(const QString &data);
    };
}

#endif //IMIN_PASSWORDINPUT_HPP
