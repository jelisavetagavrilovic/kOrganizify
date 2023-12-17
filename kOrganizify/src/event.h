#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QDateTime>
#include <QObject>

class Event
{
public:
//    Event(QObject* parent=nullptr);
//    Event(const QString &title, const QDateTime &startTime, const QDateTime &endTime, const QString &description, const QString &location, QObject* parent);
//    ~Event();

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

    bool operator==(const Event &other) const;

    void clear();
    void deleteString(QString &string);


private:
    QString m_title;
    QDateTime m_startTime;
    QDateTime m_endTime;
    QString m_description;
    QString m_location;

};

#endif // EVENT_H
