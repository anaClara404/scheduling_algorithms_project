#ifndef PRIORITY_H
#define PRIORITY_H

#include "Algorithm.h"
#include "Task.h"
#include <list>

class Priority : public Algorithm {
private:
    std::list<Task> taskList; 

public:
    Priority(const std::list<Task>& taskList);
    void schedule() override;
    Task pickNextTask() override;
};

#endif
