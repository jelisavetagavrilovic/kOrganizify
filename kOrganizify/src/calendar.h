#ifndef CALENDAR_H
#define CALENDAR_H

#include "event.h"
#include "saveload.h"
#include <QList>
#include <QString>
#include <QJsonArray>

class Calendar : public SaveLoad
{
public:
    void loadData(const QString &username);
    void saveData(const QString &username);

    void addEvent(const Event &event);
    void removeEvent(const Event &event);
    void updateEvent(const Event &event);
    QList<Event> getEvents() const;

    void clear();

private:
    QList<Event> m_events;
};

#endif // CALENDAR_H
