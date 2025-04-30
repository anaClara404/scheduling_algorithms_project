#ifndef ROUNDROBINPRIORITY_H
#define ROUNDROBINPRIORITY_H

#include "Algorithm.h"
#include "Task.h"
#include <list>

class RoundRobinPriority : public Algorithm {
private:
    static const int QUANTUM; // Tempo de execução de cada processo
    std::list<Task> taskList; // Lista de processos a serem escalonados

public:
    RoundRobinPriority(const std::list<Task>& taskList);
    void schedule() override;
    Task pickNextTask() override;
};

#endif