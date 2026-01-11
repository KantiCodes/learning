CC      = gcc
CFLAGS  = -Wall -Wextra -g

COMMON  = commons.o

PROGRAMS = \
	merge_sort/merge_sort_in_place \
	bubble_sort \
	testing \
	switch

all: $(PROGRAMS)

# Explicit rule for merge_sort_in_place
merge_sort/merge_sort_in_place: merge_sort/merge_sort_in_place.c commons.o
	$(CC) $(CFLAGS) $^ -o $@

# Generic rule for programs in root directory
bubble_sort: bubble_sort.c commons.o
	$(CC) $(CFLAGS) $^ -o $@

testing: testing.c commons.o
	$(CC) $(CFLAGS) $^ -o $@

switch: switch.c commons.o
	$(CC) $(CFLAGS) $^ -o $@

# Compile commons once
commons.o: commons.c commons.h
	$(CC) $(CFLAGS) -c commons.c

clean:
	rm -f $(PROGRAMS) *.o merge_sort/*.o

.PHONY: all clean