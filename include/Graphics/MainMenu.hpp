//
// Created by strannyi_tip on 05.12.23.
//

#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <QVBoxLayout>
#include <functional>

#include "AnimatedWidget.hpp"
#include "MainMenuItem.hpp"

namespace Graphics
{
    class MainMenu final: public AnimatedWidget
    {
        typedef std::function<void(void)> MainMenuAction;
        Q_OBJECT
    public:
        explicit MainMenu(QWidget *parent = nullptr);
        MainMenu* addItem(MainMenuItem* item, const MainMenuAction &action);
        void place(const QPoint &point);
        void animateOpen();
        void animateClose();
    private:
        QVBoxLayout *vbox_layout;
        std::map<QString, MainMenuAction> actions;
        std::map<QString, MainMenuItem*> items;
        QLabel *icon_lbl;
    public slots:
        void slotExecuteAction(const QString &item_id);
        void slotItemHovered(const QString &id);
    signals:
        void signalCloseAppRequest();
        void signalUpdateGlobalStatusMessage(const QString&);
        void signalUpdateContactsList();
        void signalRestartAppRequest();
    };
}

#endif //MAINMENU_HPP
