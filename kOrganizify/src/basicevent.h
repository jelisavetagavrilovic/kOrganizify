#ifndef BASICEVENT_H
#define BASICEVENT_H

#include <QString>

class BasicEvent
{
public:
    BasicEvent();
    virtual ~BasicEvent() = default;

    QString getTitle() const;
    void setTitle(const QString &title);

    int getDuration() const;
    void setDuration(const int duration);
    void deleteString();

    bool operator==(const BasicEvent &other) const;

private:
    QString m_title;
    int m_duration;
};

#endif // BASICEVENT_H
