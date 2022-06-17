#ifndef __SHORTEST__JOB__FIRST__
#define __SHORTEST__JOB__FIRST__


#include "./Process.h"
#include "./SortingFunction.h"
#include "./PrintTable.h"
#include <string.h>


void sjf_calculate_time(Process *p, int len)
{
	int i, j;

	int curr_time = 0;

	int min = 0;



	p[0].completed = TRUE;
	p[0].return_time = p[0].burst;
	p[0].turnaround_time = p[0].burst - p[0].arrive_time;
	p[0].waiting_time = 0;
	
	curr_time = p[0].burst;



	for(i = 1; i < len; i++)
	{

		for (j = 1; j < len; j++)
		{

			if (p[j].completed == TRUE)
				continue;

			else
			{
				min = j;

				break;

			}
		}


		for (j = 1; j < len; j++)
		{

			if ((p[j].completed == FALSE)
					&& (p[j].arrive_time <= curr_time)
						&& (p[j].burst < p[min].burst))
			{
				min = j;

			}
		}

		p[min].waiting_time = curr_time - p[min].arrive_time;

		p[min].completed = TRUE;


		curr_time += p[min].burst;


		p[min].return_time = curr_time;

		p[min].turnaround_time = p[min].return_time - p[min].arrive_time;

	}
}



void sjf_print_gantt_chart(Process *p, int len)
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

		if (p[i].turnaround_time > 9)
			printf("\b");

		printf("%d", p[i].return_time);
	}

	printf("\n");
}


void SJF(Process *process, int process_count){
	int i;
	int total_waiting_time = 0;
	int total_turnaround_time = 0;
	int total_response_time = 0;

	// Poteiro auxiliar para ordenar os processos por menor burst
    Process *aux_burst;
    // Alocação de memória do ponteiro acima;
    aux_burst = (Process *)malloc(sizeof(Process) * process_count);

    int k;                          // Variável utilizada no primeiro laço de repetição da ordenação.
    int l;                          // Variável utilizada no segundo laço de repetição da ordenação.
    int tempo_execucao = 0;         // Variável utilizada para calcular o tempo de execução.
    int cont_procss_concl = 0;      // Variável que armazena a quantidade de processos concluídos
    int cpu_vez = 0;                // Variável que armazena de qual processo é a vez na CPU
    int cpu_ja_consumida = FALSE;   // Variável de controle para saber se a CPU já foi consumida na rodada
    Process aux1;                   // Variável auxiliar do tipo processo usado na ordenação

    // Iniciando ou resetando os campos dos processos que não foram iniciados ou que receberam valores de outros algoritmos executados
    process_init(process, process_count);

    /* Faço meu tempo de execução receber o tempo no qual o primeiro processo chega,
    dessa forma garanto que caso o primeiro processo chegue em um tempo diferente de 0, 
    o calculo de tempo de CPU do SJF já começe no momento que esse processo chega*/
    tempo_execucao = process[0].arrive_time;

    // Colocando a lista de processos no ponteiro auxiliar
    for(i = 0; i < process_count; i++){
        strcpy(aux_burst[i].id, process[i].id);
        aux_burst[i].arrive_time = process[i].arrive_time;
        aux_burst[i].burst = process[i].burst;
        aux_burst[i].priority = process[i].priority;
        aux_burst[i].waiting_time = process[i].waiting_time;
        aux_burst[i].return_time = process[i].return_time;
        aux_burst[i].response_time = process[i].response_time;
        aux_burst[i].completed = process[i].completed;
    }


    // Ordenando os processo por menor tempo de execução
    for(k = 0; k < process_count; k++){
        for(l = 0; l <= k; l++)
        {
            if(aux_burst[k].burst < aux_burst[l].burst){
                // Guardando todas as informações do processo na auxiliar
                strcpy(aux1.id, aux_burst[k].id);
                aux1.arrive_time = aux_burst[k].arrive_time;
                aux1.burst = aux_burst[k].burst;
                aux1.priority = aux_burst[k].priority;
                aux1.waiting_time = aux_burst[k].waiting_time;
                aux1.return_time = aux_burst[k].return_time;
                aux1.response_time = aux_burst[k].response_time;
                aux1.completed = aux_burst[k].completed;

                // Trocando o processo que possui mais tempo de burst pelo que tem menos
                strcpy(aux_burst[k].id, aux_burst[l].id);
                aux_burst[k].arrive_time = aux_burst[l].arrive_time;
                aux_burst[k].burst = aux_burst[l].burst;
                aux_burst[k].priority = aux_burst[l].priority;
                aux_burst[k].waiting_time = aux_burst[l].waiting_time;
                aux_burst[k].return_time = aux_burst[l].return_time;
                aux_burst[k].response_time = aux_burst[l].response_time;
                aux_burst[k].completed = aux_burst[l].completed;

                // Colocando o processo que foi guardado em aux na posição seguinte ao processo que tem menos tempo de burst que dele
                strcpy(aux_burst[l].id, aux1.id);
                aux_burst[l].arrive_time = aux1.arrive_time;
                aux_burst[l].burst = aux1.burst;
                aux_burst[l].priority = aux1.priority;
                aux_burst[l].waiting_time = aux1.waiting_time;
                aux_burst[l].return_time = aux1.return_time;
                aux_burst[l].response_time = aux1.response_time;
                aux_burst[l].completed = aux1.completed;
                
            }
        }
        
    }

    // Execução do calculo do SJF
    while (cont_procss_concl < process_count){     // Enquanto tiver processo para computar na CPU, o laço se repetirá
        cpu_ja_consumida = FALSE;
        for (cpu_vez = 0; cpu_vez < process_count; cpu_vez++){
            if(tempo_execucao >= aux_burst[cpu_vez].arrive_time // Verifico se o tempo de chegada dos processos que estão na minha ordenação por burst é menor ou igual ao tempo de execução
                && aux_burst[cpu_vez].completed == FALSE        // Verifico se o processo já foi concluido  
                && cpu_ja_consumida == FALSE){                  // Verifico se a cpu já foi consumida nesse laço de repetição
                
                // Como entrou nessa estrutura de decisão, significa que o processo entrou no contexto de execução. Então consigo definir seu tempo de resposta
                aux_burst[cpu_vez].response_time = (tempo_execucao - aux_burst[cpu_vez].arrive_time);

                // Devo somar o tempo de burst do processo ao tempo de execução, para encontrar o momento que o processo saiu da execução
                tempo_execucao += aux_burst[cpu_vez].burst;
                
                // O tempo de saída do processo será o tempo decorrido até ele sair, portanto será o somatório acima
                aux_burst[cpu_vez].return_time = tempo_execucao;

                // Com o tempo de saída definido, consigo definir o tempo de retorno
                aux_burst[cpu_vez].turnaround_time = (aux_burst[cpu_vez].return_time - aux_burst[cpu_vez].arrive_time);

                // Com o tempo de retorno definido, posso definir o tempo de espera
                aux_burst[cpu_vez].waiting_time = (aux_burst[cpu_vez].turnaround_time - aux_burst[cpu_vez].burst);
                
                // Defino a conclusão do processo como TRUE
                aux_burst[cpu_vez].completed = TRUE;

                // Defino a CPU como já consumida nesse laço
                cpu_ja_consumida = TRUE;

                // Somo esse processo concluído na minha variável de controle de processos finalizados
                cont_procss_concl++;
            }
        }  
    }

    // Ordenando a lista por tempo de saída
    quick_sort_by_return_time(aux_burst, process_count);

    // Armazenando minha auxiliar já ordenada e calculada na lista de processos
    for(i = 0; i < process_count; i++){
        strcpy(process[i].id, aux_burst[i].id);
        process[i].turnaround_time = aux_burst[i].turnaround_time;
        process[i].arrive_time = aux_burst[i].arrive_time;
        process[i].burst = aux_burst[i].burst;
        process[i].priority = aux_burst[i].priority;
        process[i].waiting_time = aux_burst[i].waiting_time;
        process[i].return_time = aux_burst[i].return_time;
        process[i].response_time = aux_burst[i].response_time;
        process[i].completed = aux_burst[i].completed;
    }
    
	// Libero a alocação de memória do ponteiro auxiliar
    free(aux_burst);

	// Calcula as variáveis declaradas no começo dessa função
    for (i = 0; i < process_count; i++)
    {
        total_waiting_time += process[i].waiting_time;
        total_turnaround_time += process[i].turnaround_time;
        total_response_time += process[i].response_time;
    }

	printf("\tAlgoritmo implementado pelo aluno: Shortest Job First (SJF) \n\n");

	sjf_print_gantt_chart(process, process_count);
	
    printf("\n\tAverage Waiting Time     : %-2.2lf\n", (double)total_waiting_time / (double)process_count);
    printf("\tAverage Turnaround Time  : %-2.2lf\n", (double)total_turnaround_time / (double)process_count);
    printf("\tAverage Response Time    : %-2.2lf\n\n", (double)total_response_time / (double)process_count);

    print_table(process, process_count);

}

#endif
