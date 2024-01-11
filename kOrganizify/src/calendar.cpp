#include "calendar.h"

Calendar::Calendar() = default;

Calendar::Calendar(const Calendar &other) {
    m_events = other.m_events;
}

void Calendar::loadData(const QString &username) {
    SaveLoad::loadData(username);
    fromJson(m_jsonObject);
}

auto Calendar::toJson() const -> QJsonValue {
    QJsonArray jsonArray;
    for (const Event &event : m_events) {
        QJsonObject jsonObject;
        jsonObject["title"]       = event.getTitle();
        jsonObject["startTime"]   = event.getStartTime().toString(Qt::ISODate);
        jsonObject["endTime"]     = event.getEndTime().toString(Qt::ISODate);
        jsonObject["description"] = event.getDescription();
        jsonObject["location"]    = event.getLocation();
        jsonObject["priority"]    = customEventPriorityToString(event.getPriority());


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
        event.setPriority(customEventPriorityFromString(jv["priority"].toString()));


        addEvent(event);
    }
}

void Calendar::saveData(const QString &username) {
    m_jsonObject = toJson().toObject();
    SaveLoad::saveData(username);
}

void Calendar::addEvent(const BasicEvent &basicEvent) {
    const auto *eventPtr = dynamic_cast<const Event *>(&basicEvent);

    if (eventPtr) {
        const Event &event = *eventPtr;

        int index = 0;
        for (const Event &e : m_events) {
            if (event.getStartTime() < e.getStartTime() || (event.getStartTime() == e.getStartTime() && (event.getEndTime() < e.getEndTime()) ||
                                                            (event.getEndTime() == e.getEndTime() && event.getTitle() < e.getTitle()))) {
                break;
            }
            index++;
        }
        m_events.insert(index, event);
    } else {
        const BasicEvent &nonEvent = basicEvent;

        if (nonEvent.isValidate())
            m_basicEvents.append(nonEvent);
    }
}

void Calendar::removeEvent(const BasicEvent &basicEvent) {
    const auto *eventPtr = dynamic_cast<const Event *>(&basicEvent);
    if (eventPtr) {
        const Event &event = *eventPtr;
        m_events.removeOne(event);
    } else {
        const BasicEvent &nonEvent = basicEvent;
        m_basicEvents.removeOne(nonEvent);
    }
}

void Calendar::updateEvent(const Event &oldEvent, const Event &newEvent) {
    for (auto &m_event : m_events) {
        if (m_event == oldEvent) {
            m_event = newEvent;
            return;
        }
    }
}

auto Calendar::getEvents() const -> QList<Event> {
    return m_events;
}

auto Calendar::getBasicEvent(const int index) -> BasicEvent {
    return m_basicEvents[index];
}

auto Calendar::getEvent(const int index) -> Event {
    return m_events[index];
}

auto Calendar::sizeBasic() -> int {
    return m_basicEvents.size();
}

auto Calendar::size() -> int {
    return m_events.size();
}

auto Calendar::getEventsForWeek(const QDate &startDate, const QDate &endDate) const -> QList<Event> {
    QList<Event> weekEvents;

    for (const Event &event : m_events) {
        if (event.getStartTime().date() >= startDate && event.getEndTime().date() <= endDate) {
            weekEvents.append(event);
        }
    }

    return weekEvents;
}

auto Calendar::hasEventAt(const QDateTime &dateTime) const -> bool {
    for (const Event &event : m_events) {
        if (event.getStartTime() == dateTime) {
            return true;
        }
    }
    return false;
}

void Calendar::clear() {
    for (Event &event : m_events) {
        event.clear();
    }
    m_events.clear();
}

auto Calendar::operator=(const Calendar &other) -> Calendar {
    m_basicEvents.clear();
    m_events.clear();

    m_events      = other.m_events;
    m_basicEvents = other.m_basicEvents;

    return *this;
}
