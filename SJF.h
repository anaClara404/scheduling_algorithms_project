#ifndef SJF_H
#define SJF_H

#include "Algorithm.h"
#include "Task.h"
#include <list>

class SJF : public Algorithm {
private:
    std::list<Task> taskList; 

public:
    SJF(const std::list<Task>& taskList);
    void schedule() override;

    // Escolhe a próxima tarefa (a de menor burst)
    Task pickNextTask() override;
};

#endif
