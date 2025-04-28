#include "Task.h"
#include <atomic>

// Variável atômica para garantir que cada tarefa tenha um ID único e prevenir race conditions
std::atomic<int> next_tid(0);

// Construtor da classe Task, define tid como o próximo valor atômico para garantir
// um valor único por incremento em cada processo criado
Task::Task(const std::string& n, int p, int b)
    : name(n), priority(p), burst(b), remainingBurst(b),
      arrivalTime(0), startTime(-1), endTime(0), started(false)
{
    tid = next_tid.fetch_add(1);
}