#include "Priority.h"
#include <iostream>

Priority::Priority(const std::list<Task>& tasks) : taskList(tasks) {}

void Priority::schedule() {
    int currentTime = 0;
    int finalTurnaroundTime = 0;
    int finalWaitingTime = 0;
    int finalResponseTime = 0;
    int taskAmount = taskList.size();

    while (!taskList.empty()) {
        Task currentTask = pickNextTask();

        // Define tempo de início
        if (!currentTask.started) {
            currentTask.startTime = currentTime;
            currentTask.started = true;
        }

        // Simula execução
        currentTask.endTime = currentTask.startTime + currentTask.burst;
        currentTime = currentTask.endTime;

        // Calcula métricas
        int taskTurnaroundTime = currentTask.endTime - currentTask.arrivalTime;
        int taskWaitingTime = taskTurnaroundTime - currentTask.burst;
        int taskResponseTime = currentTask.startTime - currentTask.arrivalTime;

        // Acumuladores
        finalTurnaroundTime += taskTurnaroundTime;
        finalWaitingTime += taskWaitingTime;
        finalResponseTime += taskResponseTime;

        // Exibe os tempos calculados na execução do processo
        std::cout << "Processo [" << currentTask.name << "] finalizou sua execução.\n"
                  << "Tempo de turnaround: " << taskTurnaroundTime << "\n"
                  << "Tempo de espera: " << taskWaitingTime << "\n"
                  << "Tempo de resposta: " << taskResponseTime << "\n\n";
    }

    // Exibição das médias
    std::cout << "===== Todos os processos foram finalizados. =====\n";
    std::cout << "-> Tempo médio de turnaround: " << (float)finalTurnaroundTime / taskAmount << "\n";
    std::cout << "-> Tempo médio de espera: " << (float)finalWaitingTime / taskAmount << "\n";
    std::cout << "-> Tempo médio de resposta: " << (float)finalResponseTime / taskAmount << "\n";
}

Task Priority::pickNextTask() {
    // Encontra o processo com maior prioridade (menor valor numérico)
    auto highestPriorityIt = taskList.begin();
    for (auto it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->priority < highestPriorityIt->priority) {
            highestPriorityIt = it;
        }
    }

    Task nextTask = *highestPriorityIt;
    taskList.erase(highestPriorityIt);
    return nextTask;
}
