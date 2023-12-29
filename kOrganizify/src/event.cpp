#include "event.h"

Event::Event() : priority(CustomEventPriority::NoPriority){

}

QString Event::getTitle() const {
    return m_title;
}

void Event::setTitle(const QString &title) {
    this->m_title = title;
}

QDateTime Event::getStartTime() const {
    return m_startTime;
}

void Event::setStartTime(const QDateTime &startTime) {
    this->m_startTime = startTime;
}

QDateTime Event::getEndTime() const {
    return m_endTime;
}

void Event::setEndTime(const QDateTime &endTime) {
    this->m_endTime = endTime;
}

QString Event::getDescription() const {
    return m_description;
}

void Event::setDescription(const QString &description) {
    this->m_description = description;
}

QString Event::getLocation() const {
    return m_location;
}

void Event::setLocation(const QString &location) {
    this->m_location = location;
}

CustomEventPriority Event::getPriority() const {
    return priority;
}

void Event::setPriority(CustomEventPriority priority){
    this->priority = priority;
}

bool Event::operator==(const Event &other) const {
    return (
        m_title == other.m_title &&
        m_startTime == other.m_startTime &&
        m_endTime == other.m_endTime &&
        m_description == other.m_description &&
        m_location == other.m_location
        );
}


// Implementacija metode za čišćenje resursa
void Event::clear() {
    // Oslobodite dinamički alocirane stringove
    deleteString(m_title);
    deleteString(m_description);
    deleteString(m_location);

    // Dodajte slične naredbe za oslobađanje drugih resursa ako postoje
}

void Event::deleteString(QString &str) {
    // Provera da li je pokazivač nullptr pre dealokacije
    if (!str.isNull())
    {
        delete[] str.utf16();  // Oslobađanje dinamički alocirane memorije za UTF-16 reprezentaciju stringa
        str.clear();           // Postavljanje stringa na prazan
    }
}

QString customEventPriorityToString(CustomEventPriority priority) {
    switch (priority) {
    case CustomEventPriority::NoPriority:
        return "No Priority";
    case CustomEventPriority::Low:
        return "Low";
    case CustomEventPriority::Medium:
        return "Medium";
    case CustomEventPriority::High:
        return "High";
    default:
        return "Unknown Priority";
    }
}

CustomEventPriority customEventPriorityFromString(const QString &priorityString) {
    if (priorityString == "No Priority") {
        return CustomEventPriority::NoPriority;
    } else if (priorityString == "Low") {
        return CustomEventPriority::Low;
    } else if (priorityString == "Medium") {
        return CustomEventPriority::Medium;
    } else if (priorityString == "High") {
        return CustomEventPriority::High;
    } else {
        return CustomEventPriority::NoPriority;
    }
}




