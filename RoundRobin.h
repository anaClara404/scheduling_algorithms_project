#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include "Algorithm.h"
#include "Task.h"
#include <list>

class RoundRobin : public Algorithm {
private:
    static const int QUANTUM; // Tempo de execução de cada processo
    std::list<Task> taskList; // Lista de processos a serem escalonados

public:
    RoundRobin(const std::list<Task>& taskList);
    void schedule() override;
    Task pickNextTask() override;
};

#endif