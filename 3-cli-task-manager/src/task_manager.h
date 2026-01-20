#pragma once

#include <vector>
#include "task.h"

class TaskManager
{
private:
    std::vector<Task> m_tasks;
    int m_nextId = 1;

public:
    void addTask(const std::string &title, const std::string &desc, Priority p);
    void displayAll() const;
    Task *findTaskById(int id);
    bool removeTask(int id);
    bool updateStatus(int id, Status newStatus);
    bool updatePriority(int id, Priority newPriority);
    std::vector<Task> filterByStatus(Status s) const;
    std::vector<Task> filterByPriority(Priority p) const;
    std::vector<Task> search(const std::string &keyword) const;
    void sortById();
    void sortByPriority();
};