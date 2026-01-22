#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
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

std::vector<Task> TaskManager::filterByStatus(Status s) const
{
    std::vector<Task> output;
    std::copy_if(m_tasks.begin(), m_tasks.end(), std::back_inserter(output), [s](const Task &task)
                 { return task.getStatus() == s; });

    return output;
}

std::vector<Task> TaskManager::filterByPriority(Priority p) const
{
    std::vector<Task> output;
    std::copy_if(m_tasks.begin(), m_tasks.end(), std::back_inserter(output), [p](const Task &task)
                 { return task.getPriority() == p; });

    return output;
}

std::vector<Task> TaskManager::search(const std::string &keyword) const
{
    std::vector<Task> output;
    std::copy_if(m_tasks.begin(), m_tasks.end(), std::back_inserter(output), [keyword](const Task &task)
                 { return task.getTitle().find(keyword) != std::string::npos || task.getDescription().find(keyword) != std::string::npos; });

    return output;
}

void TaskManager::sortById()
{
    std::sort(m_tasks.begin(), m_tasks.end(),
              [](const Task &a, const Task &b)
              { return a.getId() < b.getId(); });
}

void TaskManager::sortByPriority()
{
    std::sort(m_tasks.begin(), m_tasks.end(),
              [](const Task &a, const Task &b)
              { return a.getPriority() > b.getPriority(); });
}

void TaskManager::saveToFile(const std::string &filename) const
{
    std::ofstream file(filename);
    if (!file.is_open())
        throw "file cannot be opened";

    for (long unsigned int i = 0; i < m_tasks.size(); i++)
    {
        file << m_tasks[i].toString(false) << "\n";
        if (!file)
            throw "file cannot be written to";
    }

    file.close();
}

void TaskManager::parseLineToTask(const std::string line)
{
    std::stringstream ss(line);
    std::string temp;

    std::string title;
    std::string desc;
    Status stat;
    Priority prio;

    int i = 0;
    for (char c; ss >> c;)
    {
        temp += c;

        if (ss.peek() == ',' || ss.peek() == ';' || ss.peek() == -1)
        {
            ss.ignore();
            switch (i++)
            {
            case 0:
                title = temp;
                break;
            case 1:
                desc = temp;
                break;
            case 2:
                if (temp == "TODO")
                    stat = Status::TODO;
                else if (temp == "IN_PROGRESS")
                    stat = Status::IN_PROGRESS;
                else if (temp == "DONE")
                    stat = Status::DONE;
                break;
            case 3:
                if (temp == "LOW")
                    prio = Priority::LOW;
                else if (temp == "MEDIUM")
                    prio = Priority::MEDIUM;
                else if (temp == "HIGH")
                    prio = Priority::HIGH;
                break;
            default:
                break;
            }

            temp.clear();
        }
    }

    addTask(title, desc, prio);
    m_tasks.back().setStatus(stat);
}

void TaskManager::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open())
        throw "file cannot be opened";

    while (std::getline(file, line))
    {
        parseLineToTask(line);
    }

    file.close();
}