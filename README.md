# 🔲 Simulador de Algoritmos de Escalonamento de CPU

Projeto da disciplina de Sistemas Operacionais, implementado em C++ no Linux.  
Simula os principais algoritmos de escalonamento de CPU: FCFS, SJF, Prioridade, Round-robin sem prioridade e Round-robin com prioridade.

## ⚙️ Algoritmos Implementados
- FCFS
- SJF
- Prioridade (sem preempção)
- Round-robin
- Round-robin (com prioridade)

## 💬 Descrição
Assume-se que todas as tarefas chegam ao mesmo tempo, portanto, os algoritmos de escalonamento não precisam suportar preempção. Ou seja, processos com prioridade mais alta não precisam interromper processos com prioridade mais baixa que já estão em execução.

Além disso, as tarefas podem ser organizadas em uma lista não ordenada, sem a necessidade de uma ordem específica de chegada, prioridade ou duração. A seleção da próxima tarefa a ser executada será feita de acordo com a lógica de cada algoritmo de escalonamento.

Cada algoritmo utiliza uma lista de tarefas e calcula diversos tempos de execução, como tempo de turnaround, tempo de espera e tempo de resposta. O projeto permite que o usuário escolha um dos algoritmos e execute a simulação com dados fornecidos em um arquivo de entrada.

## 📂 Instruções de Compilação e Execução
### Dependências
- Linux
- Compilador g++
  
### Compilação
- Instalar o repositório localmente: ``git clone <https://github.com/anaClara404/scheduling_algorithms_project>``
- Entrar no diretório do repositório: ``cd <diretorio-do-repositorio>``
- Compilar no terminal GCC: ``g++ -o scheduler main.cpp FCFS.cpp SJF.cpp RoundRobin.cpp RoundRobinPriority.cpp Priority.cpp Task.cpp readTasks.cpp``
- Após a compilação, executar o programa no terminal: ``./scheduler``

### Arquivo de entrada
O programa espera um arquivo de entrada "[nome].txt" contendo os processos a serem escalonados. Em cada linha do arquivo, ele deve seguir o padrão:
``Nome do processo, Prioridade, Burst time da CPU (tempo de execução)``
- Exemplo de arquivo:
  #### T1, 4, 20
  #### T2, 2, 25
  #### T3, 3, 25
  #### T4, 3, 15
  #### T5, 10, 10

## 💾 Instruções de Uso
1. Ao rodar o programa, o menu será exibido no terminal
2. O usuário escolhe um dos algoritmos de escalonamento
3. O programa pede para o usuário digitar o nome do arquivo contendo os processos (nome.txt)
4. O programa exibirá os tempos de execução para cada tarefa:
   - Turnaround
   - Waiting Time
   - Response Time
5. Em seguida, exibirá as médias desses tempos para todos os processos executados

## Colaboradores
#### Ana Clara Ferreira Epaminondas - FCFS, SJF, Priority
#### Luis Henrique Fernandes de Carvalho - Round-robin, Priority with round-robin
