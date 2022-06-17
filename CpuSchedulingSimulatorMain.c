#include "CpuSchedulingAlgorithms.h"
#include <stdlib.h>
#include <string.h>

int main() {
    // Declaração da variável que armazenará o contador de processos
    int process_count = 0; 

    int i = 0;

    // Declaração da variável que armazenará o tempo que o processo pode ficar computando na CPU
    Quantum quantum;  

    // Declaração do ponteiro que armazenará os processos
    Process *process;   

    // Arquivo com os dados do processo
    FILE *fp = fopen("process.txt", "r"); 

    // Caso o arquivo falhe na hora de abrir
    if (fp == NULL) {
        printf("FILE OPEN ERROR! - Verificar Arquivo do Entrada\n");
        return 0;
    }

    // Definindo a quantidade de processos existentes no arquivo 
    fscanf(fp, " %d", &process_count);

    // Alocamento de memória
    process = (Process *) malloc(sizeof(Process) * process_count);

    // Coletando informações, presentes no arquivo de texto, dos processos
    while (i < process_count) {
        fscanf(fp, "%s %d %d %d",
               process[i].id, &process[i].arrive_time, &process[i].burst, &process[i].priority);
                /*
                .id-> ID do processo
                .arrive_time-> Tempo que o processo chega no estado de pronto
                .burst-> Tempo gasto de CPU
                .priority-> Prioridade do processo 
                */
        i++;

    }
    // Lê no arquivo e armazena em quantum o tempo que o processo ficará executando
    fscanf(fp, " %d", &quantum);

    // Ornenando, por tempo de chegada na CPU, os processos consumidos do arquivo
    int primeiro_laco;   // Variável utilizada no primeiro laço de repetição da ordenação.
    int segundo_laco;    // Variável utilizada no segundo laço de repetição da ordenação.
    Process aux;       // Variável auxiliar do tipo processo usado na ordenação

    // Setando valores padrões da variável auxiliar
    aux.arrive_time = -1;
    aux.burst = 0;
    aux.priority = -1;

    // Ordenando os processo por chegada
    for(primeiro_laco = 0; primeiro_laco < process_count; primeiro_laco++){
        for(segundo_laco = 0; segundo_laco < process_count; segundo_laco++)
        {
            if(process[primeiro_laco].arrive_time < process[segundo_laco].arrive_time){
                // Guardando todas as informações do processo na auxiliar
                strcpy(aux.id, process[primeiro_laco].id);
                aux.arrive_time = process[primeiro_laco].arrive_time;
                aux.burst = process[primeiro_laco].burst;
                aux.priority = process[primeiro_laco].priority;

                
                // Colocando o processo que chegou depois na CPU pelo que chegou antes
                strcpy(process[primeiro_laco].id, process[segundo_laco].id);
                process[primeiro_laco].arrive_time = process[segundo_laco].arrive_time;
                process[primeiro_laco].burst = process[segundo_laco].burst;
                process[primeiro_laco].priority = process[segundo_laco].priority;

                // Colocando o processo que foi guardado em aux na posição seguinte ao processo que chegou antes dele
                strcpy(process[segundo_laco].id, aux.id);
                process[segundo_laco].arrive_time = aux.arrive_time;
                process[segundo_laco].burst = aux.burst;
                process[segundo_laco].priority = aux.priority;
                
            }
        }
        
    }
    

    //Chamada da Função que simula a execução do FCFS
    puts("┏                                                                                                                             ┓\n\n");
    FCFS(process, process_count);
    puts("┗                                                                                                                             ┛\n\n");


    //Chamada da Função que simula a execução do SJF
    puts("┏                                                                                                                             ┓\n\n");
    SJF(process, process_count);
    puts("┗                                                                                                                             ┛\n\n");


/*   
    //Chamada da Função que Simula a execução do Round-Robin
    puts("┏                                                                                                                             ┓\n\n");
    RR(process, process_count, quantum);
    puts("┗                                                                                                                             ┛\n\n");

    puts("┏                                                                                                                             ┓\n\n");
    Lotery(process, process_count);
    puts("┗                                                                                                                             ┛\n\n");
 
    puts("┏                                                                                                                             ┓\n\n");
    SRT(process, process_count);
    puts("┗                                                                                                                             ┛\n\n");
*/
    puts("┏                                                                                                                             ┓\n\n");
    PPS(process, process_count);
    puts("┗                                                                                                                             ┛\n\n");

    fclose(fp);


    free(process);


    system("pause");


    return 0;

}
