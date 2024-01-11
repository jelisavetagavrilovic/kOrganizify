#ifndef EVENT_H
#define EVENT_H

#include <QDateTime>
#include <QHash>
#include <QObject>
#include <QString>

#include "basicevent.h"

enum class CustomEventPriority { NoPriority, Low, Medium, High };

QString customEventPriorityToString(CustomEventPriority priority);
CustomEventPriority customEventPriorityFromString(const QString &priorityString);


class Event : public BasicEvent {

  public:
    Event();
    Event(const BasicEvent &basicEvent);

    void clear();
    void deleteString(QString &str);

    QString getTitle() const;
    void setTitle(const QString &title);

    int getDuration() const;
    void setDuration(const int duration);
    void setDuration();

    QDateTime getStartTime() const;
    void setStartTime(const QDateTime &startTime);

    QDateTime getEndTime() const;
    void setEndTime(const QDateTime &endTime);

    QString getDescription() const;
    void setDescription(const QString &description);

    QString getLocation() const;
    void setLocation(const QString &location);

    CustomEventPriority getPriority() const;
    void setPriority(CustomEventPriority priority);

    bool overlapsWith(const Event &other) const;

    bool operator==(const Event &other) const;

  private:
    QString m_title;
    QDateTime m_startTime;
    QDateTime m_endTime;
    QString m_description;
    QString m_location;
    CustomEventPriority m_priority;


    friend uint qHash(const Event &event) { return qHash(event.getTitle()) ^ qHash(event.getStartTime()) ^ qHash(event.getEndTime()); }
};

#endif // EVENT_H
