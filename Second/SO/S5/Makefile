all:mem1 mem2 mem1_v2 mem1_v3


mem1: mem1.c
	gcc -static -o mem1_static mem1.c 

mem1_v2: mem1_v2.c
	gcc -o mem1_v2 mem1_v2.c 

mem1_v3: mem1_v3.c
	gcc -o mem1_v3 mem1_v3.c 

mem2: mem2.c
	gcc -static -o mem2_static mem2.c

clean:
	rm -f *.o mem1__dynamic mem2__dynamic mem1_v2 mem1_v3

