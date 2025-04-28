#include "RoundRobin.h"
#include <iostream>

RoundRobin::RoundRobin(const std::list<Task>& taskList) : taskList(taskList) {}

const int RoundRobin::QUANTUM = 10;

void RoundRobin::schedule() {
    int currentTime = 0;
    int finalTurnaroundTime = 0;
    int finalWaitingTime = 0;
    int finalResponseTime = 0;
    int taskAmount = taskList.size();
    
    // O algoritmo irá executar enquanto a lista conter processos não finalizados
    while (taskList.empty() == false) {
        Task currentTask = pickNextTask();
        taskList.pop_front();

        // Verifica a flag do processo ter sido iniciado, para começar a contagem de tempo de execução
        if (currentTask.started == false) {
            currentTask.startTime = currentTime;
            currentTask.started = true;

        }

        int elapsedTime = std::min(currentTask.remainingBurst, QUANTUM);

        std::cout << "Processo [" << currentTask.name << "] executando por " << elapsedTime << " unidades de tempo.\n";

        currentTime += elapsedTime;
        currentTask.remainingBurst -= elapsedTime;

        if (currentTask.remainingBurst > 0) {
            // Se o processo não terminou por completo, volta ao final da lista
            taskList.push_back(currentTask);
        } else {
            // Se o processo terminou, calcula o tempo que terminou
            currentTask.endTime = currentTime;

            // Calcula os tempos de turnaround, espera e resposta do processo finalizado
            int taskTurnaroundTime = currentTask.endTime - currentTask.arrivalTime;
            int taskWaitingTime = taskTurnaroundTime - currentTask.burst;
            int taskResponseTime = currentTask.startTime - currentTask.arrivalTime;
            
            finalTurnaroundTime += taskTurnaroundTime;
            finalWaitingTime += taskWaitingTime;
            finalResponseTime += taskResponseTime;

            // Exibe os tempos calculados na execução do processo
            std::cout << "Processo [" << currentTask.name << "] finalizou sua execução.\n"
                      << "Tempo de turnaround: " << taskTurnaroundTime << "\n"
                      << "Tempo de espera: " << taskWaitingTime << "\n"
                      << "Tempo de resposta: " << taskResponseTime << "\n\n";
        }
    }

    std::cout << "===== Todos os processos foram finalizados. =====\n";
    std::cout << "-> Tempo médio de turnaround: " << (float)finalTurnaroundTime / taskAmount << "\n";
    std::cout << "-> Tempo médio de espera: " << (float)finalWaitingTime / taskAmount << "\n";
    std::cout << "-> Tempo médio de resposta: " << (float)finalResponseTime / taskAmount << "\n";
}

// Como não estamos levando prioridade em consideração, 
// o próximo processo será sempre o primeiro elemento da lista (FIFO)
Task RoundRobin::pickNextTask() {
    return taskList.front();
}