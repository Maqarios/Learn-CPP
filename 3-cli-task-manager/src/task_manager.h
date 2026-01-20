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
};