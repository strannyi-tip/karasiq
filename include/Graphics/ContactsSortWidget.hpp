//
// Created by strannyi_tip on 24.11.23.
//

#ifndef SEARCHCONTACTSORTWIDGET_HPP
#define SEARCHCONTACTSORTWIDGET_HPP

#include <QHBoxLayout>
#include <QToolButton>

#include "CSSableWidget.hpp"

namespace Graphics
{
    class ContactsSortWidget final: public Graphics::CSSableWidget
    {
        Q_OBJECT
    public:
        explicit ContactsSortWidget(QWidget *parent = nullptr);
    private:
        QHBoxLayout *hbox_layout;
        QToolButton *readed_status_btn;
        QToolButton *name_alpha_btn;
        QToolButton *prog_lang_btn;
        QToolButton *chat_count_btn;
    private slots:
        void slotReadedStatusClicked(bool);
        void slotNameAlphaClicked(bool);
        void slotProgLangClicked(bool);
        void slotChatCountClicked(bool);
    signals:
        void signalReadedSortRequest();
        void signalNameSortRequest();
        void signalProgLangSortRequest();
        void signalChatCountSortRequest();
    };
}

#endif //SEARCHCONTACTSORTWIDGET_HPP
