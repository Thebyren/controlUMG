CC = g++
CPPFLAGS = -Wall 
LDFLAGS = -lpthread -lncurses -lsqlite3

SRCS = $(wildcard implements/*.cpp)
OBJS = $(patsubst implements/%.cpp,objects/%.o,$(SRCS))

# Detectar el sistema operativo y configurar el nombre del ejecutable en consecuencia.
ifeq ($(OS),Windows_NT)
    EXECUTABLE = main.exe
    RM = del /Q /F
else
    EXECUTABLE = main
    RM = rm -rf
endif

all: $(EXECUTABLE)

objects/%.o: implements/%.cpp | objects
	$(CC) $(CPPFLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJS) main.cpp
	$(CC) $(CPPFLAGS)  $^ -o $@ $(LDFLAGS)

objects:
	mkdir -p objects

.PHONY: clean
clean:
	$(RM) $(EXECUTABLE) objects