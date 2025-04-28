#include "Task.h"
#include "readTasks.h"
#include <list>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

// Função para ler os processos do arquivo passado no formato especificado pela atividade
// e retornar uma lista de processos
std::list<Task> readTasks(const std::string& filename) {
    std::list<Task> tasks;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Erro na abertura do arquivo: " << filename << "\n";
        return {};
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        int priority, burst;

        if (std::getline(ss, name, ',') && ss >> priority) {
            char comma;
            ss >> comma;
            if (ss >> burst) {
                // Remover espaços extras no nome
                name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
                tasks.emplace_back(name, priority, burst);
            } else {
                std::cerr << "Erro de formatação na linha: " << line << std::endl;
            }
        } else {
            std::cerr << "Erro de formatação na linha: " << line << std::endl;
        }
    }

    return tasks;
}
