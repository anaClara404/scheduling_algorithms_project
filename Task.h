#ifndef TASK_H
#define TASK_H

#include <string>

// Classe para armazenar as informações básicas sobre cada processo
// e suas informações de execução, como tempo de chegada, início e fim
class Task {
public:
    int tid;
    std::string name;
    int priority;
    int burst;
    int remainingBurst;

    int arrivalTime;
    int startTime;
    int endTime;
    
    bool started; // Flag que define se o processo já iniciou sua execução alguma vez

    Task(const std::string& n, int p, int b);
};

#endif