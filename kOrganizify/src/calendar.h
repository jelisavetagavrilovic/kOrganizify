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

    //void addEvent(const Event &event);
    void addEvent(const BasicEvent &basicEvent);
    // void removeEvent(const Event &event);
    void removeEvent(const BasicEvent &basicEvent);
    void updateEvent(const Event &event);

    QList<Event> getEvents() const;
    BasicEvent getBasicEvent(const int index);

    int sizeBasic();

    void print();

    void clear();

private:
    // QList<Event> m_events;
    int m_sizeFixedEvents;

    QList<BasicEvent> m_basicEvents;
    QList<Event> m_events;
};


#endif // CALENDAR_H
