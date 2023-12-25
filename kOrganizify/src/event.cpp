#include "event.h"

Event::Event() : priority(CustomEventPriority::NoPriority) {}

Event::Event(const BasicEvent &basicEvent) {
    setTitle(basicEvent.getTitle());
    setDuration(basicEvent.getDuration());
}

QString Event::getTitle() const {
    return BasicEvent::getTitle();
}

void Event::setTitle(const QString &title) {
    BasicEvent::setTitle(title);
}

double Event::getDuration() const {
    return BasicEvent::getDuration();
}

void Event::setDuration(const double duration) {
    BasicEvent::setDuration(duration);
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
        BasicEvent::getTitle() == BasicEvent::getTitle() &&
        m_startTime == other.m_startTime &&
        m_endTime == other.m_endTime &&
        m_description == other.m_description &&
        m_location == other.m_location
        );
}


// Implementacija metode za čišćenje resursa
void Event::clear() {
    // Oslobodite dinamički alocirane stringove
    BasicEvent::deleteString();
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




