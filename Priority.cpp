#include "Priority.h"
#include <iostream>

Priority::Priority(const std::list<Task>& taskList) : taskList(taskList) {}

// Executa o escalonamento baseado em prioridade (menor valor = maior prioridade)
void Priority::schedule() {
    while (!taskList.empty()) {
        Task currentTask = pickNextTask();
        std::cout << "Executando tarefa: " << currentTask.name
                  << " com prioridade " << currentTask.priority
                  << " por " << currentTask.burst << " unidades de tempo." << std::endl;
    }
}

// Seleciona a tarefa com maior prioridade (menor número)
Task Priority::pickNextTask() {
    if (taskList.empty()) {
        throw std::runtime_error("Não há tarefas para escalonar.");
    }

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