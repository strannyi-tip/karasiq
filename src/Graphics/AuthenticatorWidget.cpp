//
// Created by strannyi_tip on 27.12.23.
//

#include <QApplication>
#include <QScreen>
#include <QDesktopServices>
#include <QFont>

#include "Graphics/AuthenticatorWidget.hpp"
#include "Graphics/VSpase.hpp"
#include "Core/MainWindow.hpp"
#include "Component/FontDatabase.hpp"

Graphics::AuthenticatorWidget::AuthenticatorWidget(QWidget *parent):
vbox_layout(new QVBoxLayout),
login(new LabeledInput("логин")),
password(new LabeledPasswordInput("пароль")),
submit_btn(new QPushButton("подключиться")),
offline_btn(new QPushButton("открыть оффлайн")),
exit_btn(new QPushButton("зайду в другой раз")),
error_lbl(new QLabel),
troubles_lbl(new ClickableLabel("проблемы со входом")),
signup_lbl(new ClickableLabel("регистрация")),
loader(new Core::Loader)
{
    setObjectName("authenticator");
    auto screen = qApp->screens()[0]->size();
    setGeometry({
        screen.width()/2 - 120,
        screen.height()/2 - 140,
        240,
        280
    });
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);

    error_lbl->setObjectName("error_label");
    troubles_lbl->setObjectName("free_size_label");
    signup_lbl->setObjectName("free_size_label");
    submit_btn->setObjectName("styled_button");
    offline_btn->setObjectName("styled_button");
    exit_btn->setObjectName("styled_button_red");
    error_lbl->setAlignment(Qt::AlignCenter);

    auto links_vbox_layout = new QVBoxLayout;
    links_vbox_layout->setContentsMargins({0,0,0,0});
    links_vbox_layout->setSpacing(5);
    links_vbox_layout->setAlignment(Qt::AlignTop);
    vbox_layout->setContentsMargins({20, 20, 20, 20});

    links_vbox_layout->addWidget(troubles_lbl);
    links_vbox_layout->addWidget(signup_lbl);

    vbox_layout->addWidget(login);
    vbox_layout->addWidget(password);
    vbox_layout->addWidget(new VSpase(5));
    vbox_layout->addWidget(submit_btn);
    vbox_layout->addWidget(offline_btn);
    vbox_layout->addWidget(exit_btn);
    vbox_layout->addWidget(new VSpase(10));
    vbox_layout->addLayout(links_vbox_layout);
    vbox_layout->addWidget(error_lbl);

    setLayout(vbox_layout);

    connect(submit_btn, &QPushButton::clicked, this, &AuthenticatorWidget::slotAuthenticate);
    connect(offline_btn, &QPushButton::clicked, this, &AuthenticatorWidget::slotOfflineMode);
    connect(exit_btn, &QPushButton::clicked, [](){
        qApp->exit(EXIT_SUCCESS);
    });
    connect(this, &Graphics::AuthenticatorWidget::signalAuthenticateSuccess, loader, &Core::Loader::slotLoading);
    connect(troubles_lbl, &ClickableLabel::signalClicked, this, &AuthenticatorWidget::slotSigninTroubles);
    connect(signup_lbl, &ClickableLabel::signalClicked, this, &AuthenticatorWidget::slotSignupRequest);
}

void Graphics::AuthenticatorWidget::slotAuthenticate() {
    error_lbl->setText("неверные данные для входа");
}

void Graphics::AuthenticatorWidget::slotOfflineMode() {
    Core::MainWindow::init()->show();
    close();
}

void Graphics::AuthenticatorWidget::slotSigninTroubles() {
    QDesktopServices::openUrl(QUrl("@signin_troubles"));
}

void Graphics::AuthenticatorWidget::slotSignupRequest() {
    QDesktopServices::openUrl(QUrl("@signup_request"));
}
