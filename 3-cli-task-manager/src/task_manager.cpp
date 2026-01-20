#include <iostream>
#include <algorithm>
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

bool TaskManager::removeTask(int id)
{
    auto it = std::find_if(m_tasks.begin(), m_tasks.end(), [id](const Task &task)
                           { return task.getId() == id; });

    if (it == m_tasks.end())
        return false;

    m_tasks.erase(it);
    return true;
}

bool TaskManager::updateStatus(int id, Status newStatus)
{
    auto it = std::find_if(m_tasks.begin(), m_tasks.end(), [id](const Task &task)
                           { return task.getId() == id; });

    if (it == m_tasks.end())
        return false;

    it.base()->setStatus(newStatus);
    return true;
}

bool TaskManager::updatePriority(int id, Priority newPriority)
{
    auto it = std::find_if(m_tasks.begin(), m_tasks.end(), [id](const Task &task)
                           { return task.getId() == id; });

    if (it == m_tasks.end())
        return false;

    it.base()->setPriority(newPriority);
    return true;
}