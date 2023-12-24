#ifndef BASICEVENT_H
#define BASICEVENT_H

class BasicEvent
{
public:
    BasicEvent();

    QString getTitle() const;
    void setTitle(const QString &title);

    double getDuration() const;
    void setDuration(const double duration);

private:
    QString m_title;
    double m_duration;
};

#endif // BASICEVENT_H
