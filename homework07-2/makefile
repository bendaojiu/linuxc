.SUFFIXES:.c .o

CC=gcc
SRCS=mydaemon.c
OBJS=$(SRCS:.c=.o)
EXEC=mydaemon

all:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo '-------OK--------'
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<
	
clean:
	rm -f $(OBJS)
	rm -f core*