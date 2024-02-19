//
// Created by strannyi_tip on 27.12.23.
//

#ifndef KARASIQ_AUTHENTICATORWIDGET_HPP
#define KARASIQ_AUTHENTICATORWIDGET_HPP

#include <QPushButton>
#include "CSSableWidget.hpp"
#include "LabeledInput.hpp"
#include "Core/Loader.hpp"
#include "LabeledPasswordInput.hpp"
#include "ClickableLabel.hpp"

namespace Graphics
{
    class AuthenticatorWidget final: public CSSableWidget
    {
        Q_OBJECT
    public:
        explicit AuthenticatorWidget(QWidget *parent = nullptr);
    private:
        QVBoxLayout *vbox_layout;
        LabeledInput *login;
        LabeledPasswordInput *password;
        QPushButton *submit_btn;
        QPushButton *offline_btn;
        QPushButton *exit_btn;
        QLabel *error_lbl;
        ClickableLabel *troubles_lbl;
        ClickableLabel *signup_lbl;
        Core::Loader *loader;
    private slots:
        void slotAuthenticate();
        void slotOfflineMode();
        void slotSigninTroubles();
        void slotSignupRequest();
    signals:
        void signalAuthenticateSuccess();
    };
}

#endif //KARASIQ_AUTHENTICATORWIDGET_HPP
