# Nombre del ejecutable final
PROGRAMA := programa

# Compilador y flags
CC     := gcc
CFLAGS := -Wall

SRCS := main.c operaciones.c
OBJS := $(SRCS:.c=.o)
all: $(PROGRAMA)

$(PROGRAMA): $(OBJS)
	$(CC) $^ -o $(PROGRAMA)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean

# Regla para limpiar archivos generados
clean:
	rm -f $(PROGRAMA) $(OBJS)

