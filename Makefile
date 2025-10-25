# Top-level Makefile to build example programs

CC=gcc
CFLAGS=-Iinclude -O2 -Wall

SOURCES=$(shell find examples -name '*.c')
EXES=$(patsubst %.c,%,$(SOURCES))

all: examples

examples: $(EXES)
	@echo "Built examples: $(EXES)"

%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

clean:
	find . -type f -perm +111 -path './examples/*' -delete || true
	find examples -name '*.o' -delete || true
	@echo "cleaned"
