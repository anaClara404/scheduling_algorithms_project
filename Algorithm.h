#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Task.h"
#include <list>

// Classe abstrata Algorithm vai definir os métodos padrão que todos os
// scheduling algorithms vão implementar
class Algorithm {
public:
    // shchedule() é a implementação do algoritmo em si
    virtual void schedule() = 0;
    
    // pickNextTask() seleciona o próximo processo a ser escalonado
    virtual Task pickNextTask() = 0;
    
    virtual ~Algorithm() {}
};

#endif