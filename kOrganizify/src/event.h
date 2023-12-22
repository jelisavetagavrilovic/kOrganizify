#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QDateTime>

enum class CustomEventPriority {
    NoPriority,
    Low,
    Medium,
    High
};

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

private:
    QString title;
    QDateTime startTime;
    QDateTime endTime;
    QString description;
    QString location;

    CustomEventPriority priority;
};

#endif // EVENT_H
