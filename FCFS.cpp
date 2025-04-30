#include "FCFS.h"
#include <iostream>

FCFS::FCFS(const std::list<Task>& tasks) : taskList(tasks) {}

void FCFS::schedule() {
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

        // Simula execução até o fim
        currentTask.endTime = currentTask.startTime + currentTask.burst;
        currentTime = currentTask.endTime;

        // Calcula métricas do processo
        int taskTurnaroundTime = currentTask.endTime - currentTask.arrivalTime;
        int taskWaitingTime = taskTurnaroundTime - currentTask.burst;
        int taskResponseTime = currentTask.startTime - currentTask.arrivalTime;

        // Acumula para média
        finalTurnaroundTime += taskTurnaroundTime;
        finalWaitingTime += taskWaitingTime;
        finalResponseTime += taskResponseTime;

        // Exibe os tempos calculados na execução do processo
        std::cout << "Processo [" << currentTask.name << "] finalizou sua execução.\n"
                  << "Tempo de turnaround: " << taskTurnaroundTime << "\n"
                  << "Tempo de espera: " << taskWaitingTime << "\n"
                  << "Tempo de resposta: " << taskResponseTime << "\n\n";
    }

    // Exibe médias
    std::cout << "===== Todos os processos foram finalizados. =====\n";
    std::cout << "-> Tempo médio de turnaround: " << (float)finalTurnaroundTime / taskAmount << "\n";
    std::cout << "-> Tempo médio de espera: " << (float)finalWaitingTime / taskAmount << "\n";
    std::cout << "-> Tempo médio de resposta: " << (float)finalResponseTime / taskAmount << "\n";
}


Task FCFS::pickNextTask() {
    Task nextTask = taskList.front();
    taskList.pop_front();
    return nextTask;
}