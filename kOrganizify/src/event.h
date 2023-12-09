#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QDateTime>

class Event
{
public:
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

private:
    QString title;
    QDateTime startTime;
    QDateTime endTime;
    QString description;
    QString location;
};

#endif // EVENT_H
