#ifndef READTASKS_H
#define READTASKS_H

#include <list>
#include <string>
#include "Task.h"

std::list<Task> readTasks(const std::string& filename);

#endif