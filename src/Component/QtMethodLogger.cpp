//
// Created by strannyi_tip on 03.11.23.
//

#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDateTime>
#include "Component/QtMethodLogger.hpp"

void Component::QtMethodLogger::write(Component::AbstractLogger::Level level, const std::string &message) {
    const QDir log_dir("./");
    log_dir.mkdir(QString::fromStdString(AbstractLogger::LOG_PATH));
    const auto log_file = log_dir.path() + "/" + QString::fromStdString(LOG_PATH) + "/" + QString::fromStdString(LOG_FILE);
    if (QFile file(log_file); !file.open(QIODevice::Append)) {
        qDebug() << "Файл " + log_file + " недоступен для записи.";
    } else {
        const QDateTime date = QDateTime::currentDateTime();
        const auto string_date = date.toString("dd.MM.yyyy hh:mm:ss");
        const auto string_level = AbstractLogger::levelToString(level);
        const auto final_message = AbstractLogger::buildMessage(string_level, message, string_date.toStdString());

        file.write(QString::fromStdString(final_message + "\n").toUtf8());
        file.close();
    }
}
