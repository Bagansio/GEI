all: alarms ejemplo_waitpid ejemplo_waitpid2 signalPerdido signals eventos

ejemplo_waitpid:ejemplo_waitpid.c
	gcc -o ejemplo_waitpid ejemplo_waitpid.c

ejemplo_waitpid2:ejemplo_waitpid2.c
	gcc -o ejemplo_waitpid2 ejemplo_waitpid2.c

alarms:alarm1 alarm2 alarm3 alarm4

alarm1:ejemplo_alarm1.c
	gcc -o alarm1 ejemplo_alarm1.c 
alarm2:ejemplo_alarm2.c
	gcc -o alarm2 ejemplo_alarm2.c 
alarm3:ejemplo_alarm3.c
	gcc -o alarm3 ejemplo_alarm3.c 
alarm4:ejemplo_alarm4.c
	gcc -o alarm4 ejemplo_alarm4.c 
signalPerdido:signalPerdido.c
	gcc -o signalPerdido signalPerdido.c 

signals: signal1 signal2

signal1: ejemplo_signal.c
	gcc -o signal ejemplo_signal.c

signal2: ejemplo_signal2.c
	gcc -o signal2 ejemplo_signal2.c

eventos: eventos1 eventos2

eventos1: eventos.c
	gcc -o eventos eventos.c

eventos2: eventos2.c 
	gcc -o eventos2 eventos2.c 

clean:
	rm -rf alarm1 alarm2 alarm3 alarm4 ejemplo_waitpid ejemplo_waitpid2 signalPerdido signal signal2 eventos eventos2

