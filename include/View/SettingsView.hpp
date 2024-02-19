//
// Created by strannyi_tip on 05.12.23.
//

#ifndef SETTINGSVIEW_HPP
#define SETTINGSVIEW_HPP

#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>

#include "Graphics/CSSableWidget.hpp"
#include "Graphics/LabeledInput.hpp"
#include "Graphics/LabeledPasswordInput.hpp"
#include "Graphics/AnimatedWidget.hpp"

namespace View
{
    class SettingsView final: public Graphics::AnimatedWidget
    {
        Q_OBJECT
    public:
        explicit SettingsView(QWidget *parent = nullptr);
        void animateOpen();
        void animateClose();
    private:
        static inline int TIMER_TIMEOUT = 1000;
        QGridLayout *grid_layout;
        QGroupBox *connect_gb;
        QGroupBox *contacts_gb;
        Graphics::LabeledInput *connect_address_input;
        Graphics::LabeledInput *connect_port_input;
        QPushButton *connect_save_btn;
        QPushButton *close_btn;
        QCheckBox *is_group_contacts_chb;
        QCheckBox *is_show_counter_chb;
        QPushButton *contacts_save_btn;
        QLabel *status_message;
        QTimer *timer;
        void updateStatusMessage(const QString &message);
    public slots:
        void slotSaveConnect(bool);
        void slotSaveContacts(bool);
        void slotClearStatusMessage();
    signals:
        void signalUpdateGlobalStatusMessage(const QString&);
        void signalUpdateContactsList();
        void signalRestartAppRequest();
    };
}

#endif //SETTINGSVIEW_HPP
