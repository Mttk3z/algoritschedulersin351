

all:
	gcc ./"codigo fonte"/CpuSchedulingSimulatorMain.c -I /CpuSchedulingAlgorithms.h -o CpuSchedulingSimulatorMain
	echo "Compilacao do arquivo executada com sucesso"
	echo " "
	echo "Digite 'make run' para executar o codigo ou 'make clean' para apagar ele"

run:
	./CpuSchedulingSimulatorMain

clean:
	rm ./CpuSchedulingSimulatorMain