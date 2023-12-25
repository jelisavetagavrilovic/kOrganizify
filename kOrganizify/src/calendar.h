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
    QList<Event> getEventsForWeek(const QDate& startDate, const QDate& endDate) const;

    void clear();

private:
    QList<Event> m_events;
};

#endif // CALENDAR_H
