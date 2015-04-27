CC= gcc
CFLAGS= -Wall -ggdb -g3

PROG_EXPLORE = explore


SRCS_EXPLORE= main_explore.c graph.c explore.c
OBJS_EXPLORE= $(SRCS_EXPLORE:.c=.o)


all: $(PROG_EXPLORE)

$(PROG_EXPLORE): $(OBJS_EXPLORE)
	$(CC) -o $(PROG_EXPLORE) $(OBJS_EXPLORE)


clean:
	rm -f $(PROG_EXPLORE)  $(OBJS_EXPLORE)
