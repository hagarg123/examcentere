SRCDIR = ../src
INCLUDEDIR = ../include
OBJDIR = ../obj
BINDIR = ../bin

INCLUDEFLAGS = -I${INCLUDEDIR}
CFLAGS = -c -g -Wall -lpthread ${INCLUDEFLAGS}

all:
	gcc ${CFLAGS} ${SRCDIR}/project.c -o ${OBJDIR}/project.o
	gcc ${CFLAGS} ${SRCDIR}/read_customer.c -o ${OBJDIR}/read_customer.o
	gcc ${CFLAGS} ${SRCDIR}/read_flight.c -o ${OBJDIR}/read_flight.o
	gcc ${CFLAGS} ${SRCDIR}/ticket_alloc.c -o ${OBJDIR}/ticket_alloc.o
	gcc ${OBJDIR}/project.o ${OBJDIR}/read_customer.o ${OBJDIR}/read_flight.o ${OBJDIR}/ticket_alloc.o -o ${BINDIR}/Rounak 
      
