#include <iostream>
#include "Task.h"
#include "RoundRobin.h"
#include "RoundRobinPriority.h"
#include "readTasks.h"

void showWelcome() {
    std::cout << "==================================================\n";
    std::cout << "|Simulador de Algoritmos de Escalonamento de CPU |\n";
    std::cout << "==================================================\n\n";
}

void showMenu() {
    std::cout << "Algoritmos disponíveis:\n";
    std::cout << "1. First Come First Served (FCFS)\n";
    std::cout << "2. Shortest Job First (SJF)\n";
    std::cout << "3. Prioridade (sem preempção)\n";
    std::cout << "4. Round Robin\n";
    std::cout << "5. Round Robin (com prioridade)\n";
    std::cout << "Digite sua escolha (1-5): ";
}

int main() {
    showWelcome();
    showMenu();

    // Verifica se a opção digitada é válida
    int choice;
    do {
        std::cin >> choice;

        if (choice < 1 || choice > 5) {
            std::cout << "\nOpção inválida!\n\nDigite sua escolha (1-5): ";
        }

    } while (choice < 1 || choice > 5);

    std::string filename;
    std::cout << "\nDigite o nome do arquivo contendo os processos (nome.txt): ";
    std::cin >> filename;

    auto tasks = readTasks(filename);

    // *Terminar esse switch com todos os algoritmos quando estiverem implementados*
    // O switch chama o algoritmo correspondente ao número digitado
    switch (choice) {
        // 1. First Come First Served (FCFS)
        case 1:
            std::cout << "Executando FCFS...\n";
            // FCFS fcfs(tasks);
            // fcfs.schedule();
            break;

        // 2. Shortest Job First (SJF)
        case 2:
            std::cout << "Executando SJF...\n";
            // SJF sjf(tasks);
            // sjf.schedule();
            break;

        // 3. Prioridade (sem preempção)
        case 3:
            std::cout << "Executando Prioridade...\n";
            // Priority priority(tasks);
            // priority.schedule();
            break;

        // 4. Round Robin
        case 4:
            std::cout << "Executando Round Robin...\n";
            {
                RoundRobin rr(tasks);
                rr.schedule();
            }
            break;

        // 5. Round Robin (com prioridade)
        case 5:
            std::cout << "Executando Round Robin com Prioridade...\n";
            {
                RoundRobinPriority rrp(tasks);
                rrp.schedule();
            }
            break;
    }

    return 0;
}