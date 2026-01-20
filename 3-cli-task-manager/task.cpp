#include "task.h"

Task::Task(int id, std::string title, std::string description, Status status, Priority priority)
{
    m_id = id;
    m_title = title;
    m_description = description;
    m_status = status;
    m_priority = priority;
}

int Task::getId() const { return m_id; }
std::string Task::getTitle() const { return m_title; }
std::string Task::getDescription() const { return m_description; }
Status Task::getStatus() const { return m_status; }
Priority Task::getPriority() const { return m_priority; }

void Task::setId(int id) { m_id = id; }
void Task::setTitle(std::string title) { m_title = title; }
void Task::setDescription(std::string description) { m_description = description; }
void Task::setStatus(Status status) { m_status = status; }
void Task::setPriority(Priority priority) { m_priority = priority; }

std::string Task::toString() const
{
    std::string output = std::to_string(m_id) + "," + m_title + "," + m_description + ",";

    switch (m_status)
    {
    case Status::TODO:
        output += "todo,";
        break;
    case Status::IN_PROGRESS:
        output += "in_progress,";
        break;
    case Status::DONE:
        output += "done,";
        break;
    default:
        throw "unexpected type for status";
    }

    switch (m_priority)
    {
    case Priority::LOW:
        output += "low";
        break;
    case Priority::MEDIUM:
        output += "medium";
        break;
    case Priority::HIGH:
        output += "high";
        break;
    default:
        throw "unexpected type for priority";
    }

    return output;
}

std::ostream &operator<<(std::ostream &stream, const Task &task)
{
    stream << task.toString();
    return stream;
}

bool Task::operator==(const Task &other) const
{
    return m_id == other.getId();
}