#include "calendar.h"

void Calendar::loadData(const QString &username) {
    SaveLoad::loadData(username);

    QJsonArray jsonArray = m_jsonObject["events"].toArray();
    for (const QJsonValue &jsonValue : jsonArray) {
        Event event;
        event.setTitle(jsonValue["title"].toString());
        event.setStartTime(QDateTime::fromString(jsonValue["startTime"].toString(), Qt::ISODate));
        event.setEndTime(QDateTime::fromString(jsonValue["endTime"].toString(), Qt::ISODate));
        event.setDescription(jsonValue["description"].toString());
        event.setLocation(jsonValue["location"].toString());

        qDebug() << event.getTitle() << event.getStartTime() << event.getEndTime() << event.getDescription() << event.getLocation();

        addEvent(event);
    }
}

void Calendar::saveData(const QString &username) {
    QJsonArray jsonArray;
    for (const Event &event : m_events) {
        QJsonObject jsonObject;
        jsonObject["title"] = event.getTitle();
        jsonObject["startTime"] = event.getStartTime().toString();
        jsonObject["endTime"] = event.getEndTime().toString();
        jsonObject["description"] = event.getDescription();
        jsonObject["location"] = event.getLocation();

        jsonArray.append(jsonObject);
    }

    m_jsonObject["events"] = jsonArray;
    SaveLoad::saveData(username);
}

void Calendar::addEvent(const Event &event){
    int index = 0;
    for (const Event &e : m_events) {
        if (event.getStartTime() < e.getStartTime() ||
            (event.getStartTime() == e.getStartTime() && (event.getEndTime() < e.getEndTime()) ||
            (event.getEndTime() == e.getEndTime() && event.getTitle() < e.getTitle()))) {
            break;
        }
        index++;

    }

    m_events.insert(index, event);

    // qDebug() << m_events[index].getTitle() << m_events[index].getStartTime() << m_events[index].getEndTime() <<
    //     m_events[index].getDescription() << m_events[index].getLocation();
}

void Calendar::removeEvent(const Event &event){
    m_events.removeOne(event);
}

void Calendar::updateEvent(const Event &event){
    int index = m_events.indexOf(event);
    if (index != -1){
        m_events[index] = event;
    }
}

QList<Event> Calendar::getEvents() const {
    return m_events;
}
