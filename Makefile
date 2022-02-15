CC=gcc

CFLAGS= -I. -Wall -Wextra -Werror -g3 -fsanitize=address

LDFLAGS = -lm

DEPS = print_types.h functions.h

OBJ = printf.o print_types.o functions.o


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
printf: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) core