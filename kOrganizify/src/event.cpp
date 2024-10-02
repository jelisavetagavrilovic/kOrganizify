#include "event.h"

Event::Event() : m_priority(CustomEventPriority::NoPriority) {}

auto Event::getTitle() const -> QString { return BasicEvent::getTitle(); }

void Event::setTitle(const QString &title) { BasicEvent::setTitle(title); }

auto Event::getDuration() const -> int { return BasicEvent::getDuration(); }

void Event::setDuration(const int duration) {
  BasicEvent::setDuration(duration);
}

void Event::setDuration() {
  QTime startTime = m_startTime.time();
  QTime endTime = m_endTime.time();

  int duration =
      startTime.msecsTo(endTime) / (1000 * 60); // 1000 milisekundi = 1 sekunda
  BasicEvent::setDuration(duration);
}

auto Event::getStartTime() const -> QDateTime { return m_startTime; }

void Event::setStartTime(const QDateTime &startTime) {
  m_startTime = startTime;
}

auto Event::getEndTime() const -> QDateTime { return m_endTime; }

void Event::setEndTime(const QDateTime &endTime) { m_endTime = endTime; }

auto Event::getDescription() const -> QString { return m_description; }

void Event::setDescription(const QString &description) {
  m_description = description;
}

auto Event::getLocation() const -> QString { return m_location; }

void Event::setLocation(const QString &location) { m_location = location; }

auto Event::getPriority() const -> CustomEventPriority { return m_priority; }

void Event::setPriority(CustomEventPriority priority) { m_priority = priority; }

auto Event::operator==(const Event &other) const -> bool {
  return (BasicEvent::getTitle() == BasicEvent::getTitle() &&
          m_startTime == other.m_startTime && m_endTime == other.m_endTime &&
          m_description == other.m_description &&
          m_location == other.m_location);
}

auto customEventPriorityToString(CustomEventPriority priority) -> QString {
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

auto Event::overlapsWith(const Event &other) const -> bool {
  return m_endTime > other.m_startTime && m_startTime < other.m_endTime;
}

void Event::clear() {
  BasicEvent::deleteString();
  deleteString(m_description);
  deleteString(m_location);
}

void Event::deleteString(QString &str) {
  if (!str.isNull()) {
    delete[] str.utf16();
    str.clear();
  }
}

auto customEventPriorityFromString(const QString &priorityString)
    -> CustomEventPriority {
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
