all: mstat calcula

calcula: calcula.c
	gcc -o calcula calcula.c

mstat: mstat_v1 mstat_v2

	gcc -o mstat mstat.c

mstat_v1: mstat_v1.c
	gcc -o mstat_v1 mstat_v1.c

mstat_v2: mstat_v2.c
	gcc -o mstat_v2 mstat_v2.c


clean:
	rm -rf mstat_v1 mstat_v2 mstat