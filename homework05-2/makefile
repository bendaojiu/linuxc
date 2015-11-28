.SUFFIXES:.c .o

CC=gcc
SRCS1=a.c
SRCS2=b.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)
EXEC1=a
EXEC2=b

all:$(OBJS1) $(OBJS2)
	$(CC) -o $(EXEC1) $(OBJS1)
	$(CC) -o $(EXEC2) $(OBJS2)
	@echo '----------OK-----------'
	
.c.o:
	$(CC) -Wall -g -o $@ -c $<
	
clean:
	rm -f $(OBJS1)
	rm -f $(OBJS2)
	rm -f core*