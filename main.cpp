

#include <QApplication>
#include <QFile>
#include <QIODevice>
#include <QObject>
#include "Resources.hpp"
#include "tests/tests.hpp"
#include "Component/QtMethodLogger.hpp"
#include "Core/MainWindow.hpp"
#include "Graphics/AuthenticatorWidget.hpp"
#include "Component/FontDatabase.hpp"

int main(int argc, char* argv[]) {
    tests();
    auto app = new QApplication(argc, argv);
    auto font_family = Component::FontDatabase::get(":/rsc/fonts/GroteskThin.otf");
    auto font = new QFont(font_family);
    font->setCapitalization(QFont::SmallCaps);
    font->setPointSize(10);
    QApplication::setFont(*font);
    auto logger = new Component::QtMethodLogger();
    auto authenticator = new Graphics::AuthenticatorWidget();
    QFile file(":/rsc/theme.qss");
    if(file.open(QIODevice::ReadOnly)) {
        app->setStyleSheet(QString::fromUtf8(file.readAll()));
    } else {
        logger->warning("Файл темы :/rsc/theme.qss не найден");
    }
    authenticator->show();

    return QApplication::exec();
}
