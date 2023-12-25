#ifndef CALENDAR_H
#define CALENDAR_H

#include "event.h"
#include "saveload.h"
#include <QList>
#include <QString>
#include <QJsonArray>
#include <QJsonValue>

class Calendar : public SaveLoad
{
public:
    Calendar();
    Calendar(const Calendar &other);

    void loadData(const QString &username);
    void saveData(const QString &username);
    QJsonValue toJson() const override;
    void fromJson(const QJsonObject &jsonObject) override;

    void addEvent(const Event &event);
    void removeEvent(const Event &event);
    void updateEvent(const Event &event);
    QList<Event> getEvents() const;
    Event getEvent(const int index);


    void addBasicEvent(const BasicEvent &basicEvent);

    int size();

    void print();

    void clear();

private:
    QList<Event> m_events;
    int m_sizeFixedEvents;
};

#endif // CALENDAR_H
