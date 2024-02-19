//
// Created by strannyi_tip on 05.12.23.
//

#include <QDebug>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>

#include "View/SettingsView.hpp"
#include "Component/EntitySchema.hpp"
#include "Entity/SystemEntity.hpp"
#include "Entity/UserEntity.hpp"
#include "Graphics/VSpase.hpp"

View::SettingsView::SettingsView(QWidget* parent):
        grid_layout(new QGridLayout),
        connect_gb(new QGroupBox),
        contacts_gb(new QGroupBox),
        connect_address_input(new Graphics::LabeledInput("адрес")),
        connect_port_input((new Graphics::LabeledInput("порт"))),
        connect_save_btn(new QPushButton("сохранить")),
        is_group_contacts_chb(new QCheckBox),
        is_show_counter_chb(new QCheckBox),
        contacts_save_btn(new QPushButton("сохранить")),
        close_btn(new QPushButton("закрыть настройки")),
        status_message(new QLabel),
        timer(new QTimer)
{
    setParent(parent);
    setObjectName("menu_view");

    connect_gb->setTitle("подключение");
    contacts_gb->setTitle("контакты");

    connect_save_btn->setObjectName("styled_button");
    contacts_save_btn->setObjectName("styled_button");
    close_btn->setObjectName("styled_button");
    status_message->setObjectName("label");
    is_group_contacts_chb->setObjectName("checkbox");
    is_show_counter_chb->setObjectName("checkbox");
    is_group_contacts_chb->setText("группировать контакты");
    is_show_counter_chb->setText("отображать счетчики");

    contacts_save_btn->setSizePolicy({QSizePolicy::Fixed, QSizePolicy::Fixed});
    connect_save_btn->setSizePolicy({QSizePolicy::Fixed, QSizePolicy::Fixed});
    close_btn->setSizePolicy({QSizePolicy::Fixed, QSizePolicy::Fixed});

    connect_address_input->setFixedHeight(50);
    connect_port_input->setFixedHeight(50);

    const auto connect_gb_layout = new QGridLayout;
    const auto system_gb_layout = new QGridLayout;

    connect_gb_layout->setContentsMargins(5, 20, 5, 5);
    system_gb_layout->setContentsMargins(5, 30, 5, 5);
    system_gb_layout->setAlignment(Qt::AlignLeft);

    connect_gb_layout->addWidget(connect_address_input, 1, 0, 1, 1);
    connect_gb_layout->addWidget(connect_port_input, 1, 1, 1, 1);
    connect_gb_layout->addWidget(connect_save_btn, 2, 0, 1, 1);

    system_gb_layout->addWidget(is_group_contacts_chb, 0, 0, 1, 1);
    system_gb_layout->addWidget(is_show_counter_chb, 0, 1, 1, 1);
    system_gb_layout->addWidget(contacts_save_btn, 1, 0, 1, 1);

    contacts_gb->setLayout(system_gb_layout);
    connect_gb->setLayout(connect_gb_layout);


    grid_layout->addWidget(connect_gb, 0, 0, 1, 1);
    grid_layout->addWidget(contacts_gb, 1, 0, 1, 1);
    grid_layout->addWidget(new Graphics::VSpase(5), 2, 0, 1, 1);
    grid_layout->addWidget(close_btn, 3, 0, 1, 1);
    grid_layout->addWidget(status_message, 4, 0, 1, 1);

    addAnimation("open", {
            350,
            15,
            8,
            Struct::AnimationOrientation::Horizontal
    });
    addAnimation("close", {
            0,
            15,
            8,
            Struct::AnimationOrientation::Horizontal
    });
    auto effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(0);
    effect->setOffset(0);
    setGraphicsEffect(effect);

    setLayout(grid_layout);
    setFixedWidth(0);

    auto system_schema = Component::EntitySchemaContainer::get(Entity::SystemEntity{});
    auto user_schema = Component::EntitySchemaContainer::get(Entity::UserEntity{});

    if (const auto system = system_schema.get_pointer<Entity::SystemEntity>(1))
    {
        connect_address_input->setText(QString::fromStdString(system->host));
        connect_port_input->setText(QString::number(system->port));
        is_group_contacts_chb->setChecked(system->is_group_contacts);
        is_show_counter_chb->setChecked(system->is_show_list_counter);
    }

    connect(connect_save_btn, &QPushButton::clicked, this, &SettingsView::slotSaveConnect);
    connect(contacts_save_btn, &QPushButton::clicked, this, &SettingsView::slotSaveContacts);
    connect(timer, &QTimer::timeout, this, &SettingsView::slotClearStatusMessage);
    connect(close_btn, &QPushButton::clicked, [this](){
        animateClose();
    });
}

void View::SettingsView::slotSaveConnect(bool)
{
    Entity::SystemEntity system_entity {
        -1,
        connect_address_input->text().toStdString(),
        connect_port_input->text().toInt()
    };

    auto system_schema = Component::EntitySchemaContainer::get(Entity::SystemEntity{});
    auto user_schema = Component::EntitySchemaContainer::get(Entity::UserEntity{});

    if (!system_schema.count<Entity::SystemEntity>()) {
        Component::EntitySchema::push(system_entity);
    } else {
        system_entity.id = 1;
        Component::EntitySchema::update(system_entity);
    }
    updateStatusMessage("изменения сохранены");
}

void View::SettingsView::slotSaveContacts(bool) {
    auto system_schema = Component::EntitySchemaContainer::get(Entity::SystemEntity{});
    auto system_entity = system_schema.get_pointer<Entity::SystemEntity>(1);
    if (system_entity) {
        system_entity->is_group_contacts = is_group_contacts_chb->isChecked();
        system_entity->is_show_list_counter = is_show_counter_chb->isChecked();
    }
    Component::EntitySchema::update(*system_entity);
    updateStatusMessage("изменения сохранены");
    QMessageBox reboot_question;
    reboot_question.setText("перезагрузить приложение?");
    reboot_question.setInformativeText("для применения измененений необходима перезагрузка");
    reboot_question.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    QPushButton *reboot_button = reboot_question.addButton("перезагрузка", QMessageBox::AcceptRole);
    QPushButton *cancel_button = reboot_question.addButton("отмена", QMessageBox::RejectRole);
    reboot_question.exec();

    if (reboot_question.clickedButton() == reboot_button) {
        emit signalRestartAppRequest();
    } else if (reboot_question.clickedButton() == cancel_button) {
        close();
    }
}

void View::SettingsView::updateStatusMessage(const QString &message) {
    status_message->setText(message);
    timer->start(TIMER_TIMEOUT);
}

void View::SettingsView::slotClearStatusMessage() {
    status_message->clear();
    timer->stop();
}

void View::SettingsView::animateOpen() {
    selectAnimation("open");
    animate();
}

void View::SettingsView::animateClose() {
    selectAnimation("close");
    animate();
}
