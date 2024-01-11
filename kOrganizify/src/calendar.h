#ifndef CALENDAR_H
#define CALENDAR_H

#include "event.h"
#include "saveload.h"
#include <QJsonArray>
#include <QJsonValue>
#include <QList>
#include <QString>

class Calendar : public SaveLoad {
  public:
    Calendar();
    Calendar(const Calendar &other);
    Calendar operator=(const Calendar &other);
    QList<Event> getEvents() const;
    QList<Event> getEventsForWeek(const QDate &startDate, const QDate &endDate) const;
    Event getEvent(const int index);
    BasicEvent getBasicEvent(const int index);
    QJsonValue toJson() const override;
    int sizeBasic();
    int size();
    bool hasEventAt(const QDateTime &dateTime) const;
    void loadData(const QString &username);
    void saveData(const QString &username);
    void clear();
    void print();
    void fromJson(const QJsonObject &jsonObject) override;
    void addEvent(const BasicEvent &basicEvent);
    void removeEvent(const BasicEvent &basicEvent);
    void updateEvent(const Event &oldEvent, const Event &newEvent);

  private:
    QList<BasicEvent> m_basicEvents;
    QList<Event> m_events;
};


#endif // CALENDAR_H
