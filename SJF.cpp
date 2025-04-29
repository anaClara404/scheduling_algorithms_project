#include "SJF.h"
#include <iostream>

SJF::SJF(const std::list<Task>& tasks) : taskList(tasks) {}

void SJF::schedule() {
    while (!taskList.empty()) {
        Task task = pickNextTask();

        std::cout << "Executando: " << task.name
                  << " [Burst: " << task.burst << "]" << std::endl;

        if (!task.started) {
            task.startTime = 0;
            task.started = true;
        }

        task.endTime = task.startTime + task.burst;

        std::cout << "Finalizado: " << task.name
                  << " [Tempo de fim: " << task.endTime << "]" << std::endl;
    }
}

Task SJF::pickNextTask() {
    // Encontra a tarefa com o menor burst
    auto shortestIt = taskList.begin();
    for (auto it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->burst < shortestIt->burst) {
            shortestIt = it;
        }
    }

    Task nextTask = *shortestIt;
    taskList.erase(shortestIt); 
    return nextTask;
}
