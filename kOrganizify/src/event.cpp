#include "event.h"

QString Event::getTitle() const {
    return title;
}

void Event::setTitle(const QString &title) {
    this->title = title;
}

QDateTime Event::getStartTime() const {
    return startTime;
}

void Event::setStartTime(const QDateTime &startTime) {
    this->startTime = startTime;
}

QDateTime Event::getEndTime() const {
    return endTime;
}

void Event::setEndTime(const QDateTime &endTime) {
    this->endTime = endTime;
}

QString Event::getDescription() const {
    return description;
}

void Event::setDescription(const QString &description) {
    this->description = description;
}

QString Event::getLocation() const {
    return location;
}

void Event::setLocation(const QString &location) {
    this->location = location;
}
