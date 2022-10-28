SRCS = main.c qdbmp.c
OBJS = main.o qdbmp.o

main: $(OBJS)
	gcc -o main $(OBJS)

main.o: main.c
	gcc -c main.c

qdbmp.o: qdbmp.c
	gcc -c qdbmp.c

clean:; /bin/rm main *.o

depend:; makedepend $(SRCS)