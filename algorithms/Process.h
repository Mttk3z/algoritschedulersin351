#ifndef __PROCESS__
#define __PROCESS__
#include <stdio.h>
#include <stdlib.h>
#define ID_LEN 20 // Define a quantidade máximo de caracteres para o tamanho do nome do processo;
#define TRUE 1
#define FALSE 0

// Estruct do processo
typedef struct _process
{
    char id[ID_LEN];    // ID do processo;
    int arrive_time;    // Tempo no qual o processo chega no estado de pronto;
    int waiting_time;   // Tempo que o processo fica no estado de pronto, ou seja, que ele fica esperando outro processo executar
    int return_time;    // Tempo de saída, tempo no qual o processo saiu da CPU
    int turnaround_time;// Tempo de retorno, tempo desde que ele chegou em pronto até ele sair
    int response_time;  // Tempo de resposta do processo, o quanto ele esperou para entrar no processo pela primeira vez.
    int burst;          // Tempo que o processo quer de CPU;
    int priority;       // Prioridade que o processo possui;
    int completed;      // Armazena o processo está no estado de completado/finalizado ou não;
} Process;

typedef int Quantum;
// Função que inicializa as variáveis ainda não iniciadas de cada processo
void process_init(Process p[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        p[i].waiting_time = 0;
        p[i].return_time = 0;
        p[i].response_time = 0;
        p[i].completed = FALSE;
    }
}

#endif
