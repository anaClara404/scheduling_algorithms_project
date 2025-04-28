#ifndef FCFS_H
#define FCFS_H

#include "Algorithm.h"
#include "Task.h"
#include <list>

class FCFS : public Algorithm {
private:
    std::list<Task> taskList; // Lista de processos a serem escalonados

public:
    FCFS(const std::list<Task>& taskList);
    void schedule() override;
    Task pickNextTask() override;
};

#endif