Nome: Mattheus Carvalho
Matrícula: 5965

Comentários sobre o projeto:
1- Não foram implementados os algoritmos Round-Robin (RR), Loteria e Shortest Remaining Time Next (SRTN).
2- Os algoritmos First Come First Served (FCFS) e Shortest Job First (SJF) foram implementados.
3- Em testes realizados pelo aluno, os algoritmos implementados entregaram os resultados esperados.
4- Foram realizados testes com as seguintes entradas:
    a-  6
        P0 3 5 2
        P1 0 4 3
        P2 1 1 2
        P3 5 3 4
        P4 3 7 3
        P5 8 2 1
        2

    b-  11
        P0 3 5 2
        P1 0 4 3
        P2 1 1 2
        P3 5 3 4
        P4 3 7 3
        P5 8 2 1
        P6 0 2 3
        P7 5 7 2
        P8 2 2 2
        P9 3 5 1
        P10 4 4 2
        2 

    c-  4
        P0 4 3 2
        P1 0 8 3
        P2 5 4 2
        P3 9 2 4
        2
        
    d-  4
        P0 0 3 2
        P1 0 8 3
        P2 9 2 2
        P3 5 4 4
        2
5- Não foram encontrados bugs ou problemas.
6- Link para o repositório de versionamento: https://github.com/Mttk3z/algoritschedulersin351
7- Informações referentes ao desenvolvimento:
    - O código foi desenvolvido na linguagem C, usando a IDE "Visual Studio Code" na versão 1.68
    - O ambiente usado foi o "Linux MInt 20.3 "Una" Cinnamon Edition", uma distribuição do Linux Ubuntu

8- Como utilizar:
    1º Passo:
    - Para executar o programa, primeiramente você deve inserir um arquivo do tipo texto na pasta "5965",
      caso coloque esse arquivo em outra pasta, o código não encontrará esse arquivo de entrada e encerrará
      sua execução sem realizar o objetivo proposto.
        - Também deve se atentar ao "formato das informações dentro desse arquivo de texto, elas devem
          seguir o seguinte padrão:
            6
            P0 3 5 2
            P1 0 4 3
            P2 1 1 2
            P3 5 3 4
            P4 3 7 3
            P5 8 2 1
            2
        - Descrição do formato acima:
            - 6         -> Quantidade de processo contidos no arquivo de entrada
              P0 3 5 2  -> Nome do processo, seu tempo de chegada, o tempo que deseja executar e sua prioridade
              P1 0 4 3
              P2 1 1 2
              P3 5 3 4
              P4 3 7 3
              P5 8 2 1
              2         -> Quantum que a CPU desponibilizará
    2º Passo:
    - Adicionando o arquivo no local correto, você deverá abrir o terminal do linux, navegar até a pasta "5965" e
      digitar o comando para que o Makefile compile o código.
        - O camando é: make all
    3º Passo:
    - Após sua compilação será gerado um arquivo na pasta "5965" que você poderá executar através de um comando 
      do Makefile.
        - O camando é: make run
    4º Passo:
    - Dessa forma o código deverá executar e o resultado aparecer em sua tela.
    5º Passo (Opcional):
    - Após o quarto passo, caso deseje você pode, através de um comando do Makefile, excluir o arquivo compilado
      gerado.
        - O comando é: make clean

