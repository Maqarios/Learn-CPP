#include <iostream>
#include "task_manager.h"

void TaskManager::addTask(const std::string &title, const std::string &desc, Priority p)
{
    Task t = Task(m_nextId++, title, desc, Status::TODO, p);
    m_tasks.push_back(t);
}

void TaskManager::displayAll() const
{
    for (Task task : m_tasks)
        std::cout << task << "\n";
}

Task *TaskManager::findTaskById(int id)
{
    for (Task &task : m_tasks)
        if (task.getId() == id)
            return &task;
    return nullptr;
}