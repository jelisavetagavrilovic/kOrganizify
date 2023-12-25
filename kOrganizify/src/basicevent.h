#ifndef BASICEVENT_H
#define BASICEVENT_H

#include <QString>

class BasicEvent
{
public:
    BasicEvent();

    QString getTitle() const;
    void setTitle(const QString &title);

    int getDuration() const;
    void setDuration(const int duration);
    void deleteString(QString &string);

private:
    QString m_title;
    int m_duration;
};

#endif // BASICEVENT_H
