#include "RoundRobin.h"
#include <iostream>

RoundRobin::RoundRobin(const std::list<Task>& taskList) : taskList(taskList) {}

const int RoundRobin::QUANTUM = 10;

void RoundRobin::schedule() {
    int currentTime = 0; // Tempo atual do escalonador
    int finalTurnaroundTime = 0; // Tempo total de turnaround dos processos
    int finalWaitingTime = 0; // Tempo total de espera dos processos
    int finalResponseTime = 0; // Tempo total de resposta dos processos
    int taskAmount = taskList.size(); // Total de processos a serem escalonados
    
    // O algoritmo irá executar enquanto a lista conter processos não finalizados
    while (taskList.empty() == false) {
        Task currentTask = pickNextTask();
        taskList.pop_front();

        // Verifica a flag do processo ter sido iniciado, para começar a contagem de tempo de execução
        if (currentTask.started == false) {
            currentTask.startTime = currentTime;
            currentTask.started = true;

        }

        // Define o tempo de execução como sendo o menor entre o tempo restante do processo e o quantum
        int elapsedTime = std::min(currentTask.remainingBurst, QUANTUM);

        std::cout << "Processo [" << currentTask.name << "] executando por " << elapsedTime << " unidades de tempo.\n";

        currentTime += elapsedTime;
        currentTask.remainingBurst -= elapsedTime;

        /* Se ainda houver tempo restante no processo, ele volta para o final da lista
        e continua sua execução. Se não, calculam-se os tempos de turnaround, espera
        e resposta do processo e printa para o usuário, além de acumular os tempos para
        o cálculo das médias no final do escalonamento */
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
            
            // Acumula os tempos para o cálculo das médias
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