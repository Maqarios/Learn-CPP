#pragma once

#include <string>

enum class Status
{
    TODO,
    IN_PROGRESS,
    DONE
};

enum class Priority
{
    LOW,
    MEDIUM,
    HIGH
};

class Task
{
private:
    std::string m_title;
    std::string m_description;
    Status m_status;
    Priority m_priority;
    int m_id;

public:
    Task(int id, std::string title, std::string description, Status status, Priority priority);
    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    Status getStatus() const;
    Priority getPriority() const;
    void setId(int id);
    void setTitle(std::string title);
    void setDescription(std::string description);
    void setStatus(Status status);
    void setPriority(Priority priority);
    std::string toString() const;
    friend std::ostream &operator<<(std::ostream &stream, const Task &task);
    bool operator==(const Task &other) const;
};