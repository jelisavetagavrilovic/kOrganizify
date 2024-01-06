#include "basicevent.h"

BasicEvent::BasicEvent() {}

QString BasicEvent::getTitle() const { return m_title; }
void BasicEvent::setTitle(const QString &title) { m_title = title; }

int BasicEvent::getDuration() const { return m_duration; }
void BasicEvent::setDuration(const int duration) { m_duration = duration; }

void BasicEvent::deleteString() { m_title.clear(); }

bool BasicEvent::isValidate() const {
  return (m_title != "" && m_duration > 0);
}

bool BasicEvent::operator==(const BasicEvent &other) const {
  return (m_title == other.m_title && m_duration == other.m_duration);
}
