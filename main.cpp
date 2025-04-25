#include <iostream>
#include <vector>
#include "scheduler.h"

using namespace std;

int main() {
    int choice;
    vector<Process> processes;
    int n;

    cout << "Simulador de Algoritmos de Escalonamento de CPU" << endl;
    cout << "Digite o numero de processos: ";
    cin >> n;

    // coleta dados dos processos
    for (int i = 0; i < n; ++i) {
        Process p;
        p.id = i + 1;
        cout << "Processo P" << p.id << ":\n";
        cout << "  Tempo de chegada: ";
        cin >> p.arrivalTime;
        cout << "  Burst time: ";
        cin >> p.burstTime;
        p.remainingTime = p.burstTime;
        processes.push_back(p);
    }

    cout << "\nEscolha o algoritmo:\n1. FCFS\n> ";
    cin >> choice;

    switch (choice) {
        case 1:
            fcfs(processes);
            break;
        default:
            cout << "Opcao invalida." << endl;
    }

    return 0;
}

// scheduler.h
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

void fcfs(std::vector<Process>& processes);

#endif

// scheduler.cpp
#include "scheduler.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void fcfs(vector<Process>& processes) {
    // Ordena por tempo de chegada
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    float totalWaiting = 0, totalTurnaround = 0;

    cout << "\n[ Gantt Chart ]\n";

    for (auto& p : processes) {
        if (currentTime < p.arrivalTime)
            currentTime = p.arrivalTime;

        cout << "| P" << p.id << " ";

        p.waitingTime = currentTime - p.arrivalTime;
        p.completionTime = currentTime + p.burstTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;

        currentTime += p.burstTime;

        totalWaiting += p.waitingTime;
        totalTurnaround += p.turnaroundTime;
    }
    cout << "|" << endl;

    cout << "\nTabela de resultados:\n";
    cout << "ID\tChegada\tBurst\tEspera\tTurnaround\n";
    for (auto& p : processes) {
        cout << "P" << p.id << "\t" << p.arrivalTime << "\t"
             << p.burstTime << "\t" << p.waitingTime << "\t"
             << p.turnaroundTime << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nTempo medio de espera: " << totalWaiting / processes.size() << endl;
    cout << "Tempo medio de turnaround: " << totalTurnaround / processes.size() << endl;
}


