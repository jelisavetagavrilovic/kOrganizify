#include "calendar.h"

Calendar::Calendar()
{}

Calendar::Calendar(const Calendar &other){
    m_events = other.m_events;
}

void Calendar::loadData(const QString &username) {
    SaveLoad::loadData(username);
    fromJson(m_jsonObject);
}

QJsonValue Calendar::toJson() const {
    QJsonArray jsonArray;
    for (const Event &event : m_events) {
        QJsonObject jsonObject;
        jsonObject["title"] = event.getTitle();
        jsonObject["startTime"] = event.getStartTime().toString(Qt::ISODate);
        jsonObject["endTime"] = event.getEndTime().toString(Qt::ISODate);
        jsonObject["description"] = event.getDescription();
        jsonObject["location"] = event.getLocation();

        jsonArray.append(jsonObject);
    }

    return QJsonValue(jsonArray);
}

void Calendar::fromJson(const QJsonObject &jsonObject) {
    m_jsonObject = jsonObject;

    QJsonArray jsonArray = m_jsonObject["events"].toArray();
    for (const QJsonValue &jv : jsonArray) {
        Event event;
        event.setTitle(jv["title"].toString());
        event.setStartTime(QDateTime::fromString(jv["startTime"].toString(), Qt::ISODate));
        event.setEndTime(QDateTime::fromString(jv["endTime"].toString(), Qt::ISODate));
        event.setDescription(jv["description"].toString());
        event.setLocation(jv["location"].toString());

        addEvent(event);
    }
}

void Calendar::saveData(const QString &username) {
    m_jsonObject = toJson().toObject();
    SaveLoad::saveData(username);
}

void Calendar::addEvent(const BasicEvent &basicEvent) {
    // Provera tipa korišćenjem dynamic_cast
    const Event *eventPtr = dynamic_cast<const Event*>(&basicEvent);

    if (eventPtr) {
        const Event &event = *eventPtr;
        qDebug() << event.getTitle() << event.getStartTime() << event.getEndTime() <<
            event.getDescription() << event.getLocation();

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
    } else {
        const BasicEvent &nonEvent = basicEvent;

        qDebug() << nonEvent.getTitle() << nonEvent.getDuration();

        if (nonEvent.isValidate())
            m_basicEvents.append(nonEvent);
    }
}

void Calendar::removeEvent(const BasicEvent &basicEvent) {
    const Event *eventPtr = dynamic_cast<const Event*>(&basicEvent);
    if (eventPtr) {
        const Event &event = *eventPtr;
        qDebug() << event.getTitle() << event.getStartTime() << event.getEndTime() <<
            event.getDescription() << event.getLocation();
        m_events.removeOne(event);
        clear();
    } else {
        const BasicEvent &nonEvent = basicEvent;
        m_basicEvents.removeOne(nonEvent);

    }
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

BasicEvent Calendar::getBasicEvent(const int index) {
    return m_basicEvents[index];
}

Event Calendar::getEvent(const int index) {
    return m_events[index];
}

int Calendar::sizeBasic() {
    return m_basicEvents.size();
}

int Calendar::size() {
    return m_events.size();
}

void Calendar::print() {
    // for (int index = 0; index < m_events.size(); index++)
    //     qDebug() << m_events[index].getTitle() << m_events[index].getStartTime() << m_events[index].getEndTime() <<
    //         m_events[index].getDescription() << m_events[index].getLocation();

}

QList<Event> Calendar::getEventsForWeek(const QDate& startDate, const QDate& endDate) const {
    QList<Event> weekEvents;

    for (const Event& event: m_events){
        if (event.getStartTime().date() >= startDate && event.getEndTime().date() <= endDate){
            weekEvents.append(event);
        }
    }

    return weekEvents;
}


bool Calendar::hasEventAt(const QDateTime& dateTime) const {
    for (const Event& event : m_events) {
        if (event.getStartTime() == dateTime) {
            return true;
        }
    }
    return false;
}


void Calendar::clear() {
    for (Event &event : m_events) {
        event.clear(); // Poziva clear metodu za svaki događaj
    }
    m_events.clear(); // Očisti listu događaja
}

