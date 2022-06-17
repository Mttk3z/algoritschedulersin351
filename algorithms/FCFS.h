#ifndef __FIRST__COME__FIRST__SERVED__
#define __FIRST__COME__FIRST__SERVED__


#include "./Process.h"
#include "./SortingFunction.h"
#include "./PrintTable.h"

// Função que calcula o tempo de execução dos processos no algoritmo PPS
void fcfs_calculate_time(Process *process, int process_count)   // Recebe como parametro o ponteiro de processos e a quantidade de processo
{
    int i;

    for(i = 0; i < process_count; i++){

        if(i == 0){
            // Definindo o tempo de saída (return_time) do primeiro processo
            process[i].return_time = (process[i].burst + process[i].arrive_time);

            // Definindo o tempo de resposta (response_time) do primeiro processo
            process[i].response_time = 0;
        }else{
            // Definindo o tempo de saída (return_time) dos demais processos
            process[i].return_time = (process[i-1].return_time + process[i].burst);

            // Definindo o tempo de resposta (response_time) dos demais processos
            process[i].response_time = (process[i-1].return_time - process[i].arrive_time);
        }

        // Definindo o tempo de retorno (turnaround_time) dos processos
        process[i].turnaround_time = (process[i].return_time - process[i].arrive_time);

        // Definindo o tempo de espera (waiting_time) dos processos
        process[i].waiting_time = (process[i].turnaround_time - process[i].burst);   

        // Definindo os processos como concluidos
        process[i].completed = TRUE;
    }
}    

// Função que printa a gantt chart
void fcfs_print_gantt_chart(Process *p, int len)
{
    int i, j;
    printf("\t ");
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst; j++)
            printf("--");

        printf(" ");
    }

    printf("\n\t|");


    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst - 1; j++)
            printf(" ");

        printf("%s", p[i].id);

        for (j = 0; j < p[i].burst - 1; j++)
            printf(" ");

        printf("|");
    }

    printf("\n\t ");

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst; j++)
            printf("--");

        printf(" ");
    }

    printf("\n\t");


    printf("0");

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst; j++)
            printf("  ");

        if (p[i].return_time > 9)
            printf("\b");

        printf("%d", p[i].return_time);

    }

    printf("\n");
}

void FCFS(Process *process, int process_count)
{
    int i;
    int total_waiting_time = 0;     // Variável que armazenar o tempo de espera total
    int total_turnaround_time = 0;  // Variável que armazena o tempo total de retorno
    int total_response_time = 0;    // Variável que armazena o tempo total de resposta

    // Iniciando ou resetando os campos dos processos que não foram iniciados ou que receberam valores de outros algoritmos executados
    process_init(process, process_count);

    // Chama a função que executa o FCFS
    fcfs_calculate_time(process, process_count);

    // Calcula as variáveis declaradas no começo dessa função
    for (i = 0; i < process_count; i++)
    {
        total_waiting_time += process[i].waiting_time;
        total_turnaround_time += process[i].turnaround_time;
        total_response_time += process[i].response_time;
    }

    printf("\tAlgoritmo implementado pelo aluno: First Come First Served (FCFS) \n\n");

    fcfs_print_gantt_chart(process, process_count);
    printf("\n\tAverage Waiting Time     : %-2.2lf\n", (double)total_waiting_time / (double)process_count);
    printf("\tAverage Turnaround Time  : %-2.2lf\n", (double)total_turnaround_time / (double)process_count);
    printf("\tAverage Response Time    : %-2.2lf\n\n", (double)total_response_time / (double)process_count);

    print_table(process, process_count);


        
}

#endif
