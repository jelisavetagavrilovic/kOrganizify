#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QDateTime>
#include <QHash>
#include <QObject>

enum class CustomEventPriority {
    NoPriority,
    Low,
    Medium,
    High
};

QString customEventPriorityToString(CustomEventPriority priority);
CustomEventPriority customEventPriorityFromString(const QString &priorityString);

class Event
{
public:
    Event();

    QString getTitle() const;
    void setTitle(const QString &title);

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

    bool operator==(const Event &other) const;

    void clear();
    void deleteString(QString &string);


private:
    QString m_title;
    QDateTime m_startTime;
    QDateTime m_endTime;
    QString m_description;
    QString m_location;
    CustomEventPriority priority;


//overload and needs to be in .h
friend uint qHash(const Event &event) {
    return qHash(event.getTitle()) ^ qHash(event.getStartTime()) ^ qHash(event.getEndTime());
}

};

#endif // EVENT_H
