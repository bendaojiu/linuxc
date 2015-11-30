.SUFFIXES:.c .o
.SUFFIXES:.cpp .o

CC=gcc

SRCS1=upper.c
OBJS1=$(SRCS1:.c=.o)
EXEC1=libupper.so

SRCS2=test_c.c
OBJS2=$(SRCS2:.c=.o)
EXEC2=test_c

SRCS3=test_cpp.cpp
OBJS3=$(SRCS3:.cpp=.o)
EXEC3=test_cpp

all:$(OBJS1)	$(OBJS2)	$(OBJS3)
	$(CC) -shared -o $(EXEC1) $(OBJS1)
	$(CC) -L. -lupper -o $(EXEC2) $(OBJS2)
	g++ -L. -lupper -o $(EXEC3) $(OBJS3)
	@echo '---------OK-----------'
	
.c.o:
	$(CC) -Wall -g -fPIC -o $(OBJS1) -c $(SRCS1)
	$(CC) -Wall -g -o $(OBJS2) -c $(SRCS2)
	
.cpp.o:
	g++ -Wall -g -o $(OBJS3) -c $(SRCS3)
	
clean:
	rm -f $(OBJS1)
	rm -f $(OBJS2)
	rm -f $(OBJS3)
	rm -f core*