.SUFFIXES: .c .o

CC=gcc

SRCS=server.c\
  pub.c\
  work.c\
  mymysql.c

OBJS=$(SRCS:.c=.o)
EXEC=myhttpd

all:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS) -L/usr/lib64/mysql -lmysqlclient -lpthread
	@echo '^_^^_^^_^^_^OK^_^^_^^_^^_^'

.c.o:
	$(CC) -Wall -g -o $@ -c $< -I/usr/include/mysql

clean:
	rm -f $(OBJS)
	rm -f core*
