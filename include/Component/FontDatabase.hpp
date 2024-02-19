//
// Created by strannyi_tip on 16.10.23.
//

#ifndef WORK_CALENDAR_FONTDATABASE_HPP
#define WORK_CALENDAR_FONTDATABASE_HPP

#include <qstring.h>

namespace Component
{
    class FontDatabase
    {
    private:
        FontDatabase()=default;
        ~FontDatabase()=default;
        FontDatabase(const FontDatabase&)=default;
        FontDatabase&operator=(const FontDatabase&)=default;
    public:
        static QString get(const QString &filename);
    };
}

#endif //WORK_CALENDAR_FONTDATABASE_HPP
