#include "FCFS.h"
#include <iostream>

FCFS::FCFS(const std::list<Task>& tasks) : taskList(tasks) {}

void FCFS::schedule() {
    while (!taskList.empty()) {
        Task task = pickNextTask();

        std::cout << "Executando: " << task.name
                  << " [Burst: " << task.burst << "]" << std::endl;

        if (!task.started) {
            task.startTime = 0;  
            task.started = true;
        }

        // Simula execução 
        task.endTime = task.startTime + task.burst;

        std::cout << "Finalizado: " << task.name
                  << " [Tempo de fim: " << task.endTime << "]" << std::endl;
    }
}

Task FCFS::pickNextTask() {
    Task nextTask = taskList.front();
    taskList.pop_front();
    return nextTask;
}