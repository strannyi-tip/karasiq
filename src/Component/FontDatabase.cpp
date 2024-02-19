//
// Created by strannyi_tip on 16.10.23.
//
#include <QFontDatabase>
#include "Component/FontDatabase.hpp"

QString Component::FontDatabase::get(const QString &filename) {
    int id = QFontDatabase::addApplicationFont(filename);

    return id > -1 ? QFontDatabase::applicationFontFamilies(id).at(0) : "";
}

