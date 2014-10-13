OBJS = aware.o interact.o comm.o dssw.o
cc = gcc
dssw:$(OBJS)
	cc -o dssw $(OBJS) -lpthread

dssw.o: dssw.c aware.h interact.h comm.h
	cc -c dssw.c -lpthread
aware.o: aware.c aware.h
	cc -c aware.c
interact.o: interact.c interact.h aware.h
	cc -c interact.c -lpthread
comm.o: comm.c comm.h
	cc -c comm.c

clean:
	rm $(OBJS)