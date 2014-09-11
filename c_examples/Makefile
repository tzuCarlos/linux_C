SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

CFLAGS += -lm
all: $(PROGS)

%: %.c

	$(CC) -o $@ $< $(CFLAGS)

clean:

	@rm -f $(PROGS) 
