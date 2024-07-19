# Makefile used by the checker
PB1 = servere
PB2 = colorare
PB3 = compresie
PB4 = criptat
PB5 = oferta

SOURCES1 = servere.cpp
SOURCES2 = colorare.cpp
SOURCES3 = compresie.cpp
SOURCES4 = criptat.cpp
SOURCES5 = oferta.cpp
.PHONY: build run-p1 run-p2 run-p3 run-p4 run-p5 clean
CFLAGS = -Wall -g
CC = g++

build: $(PB1) $(PB2) $(PB3) $(PB4) $(PB5)

$(PB1): $(SOURCES1)
	$(CC) $(CFLAGS) $(SOURCES1) -o $(PB1)

$(PB2): $(SOURCES2)
	$(CC) $(CFLAGS) $(SOURCES2) -o $(PB2)

$(PB3): $(SOURCES3)
	$(CC) $(CFLAGS) $(SOURCES3) -o $(PB3)

$(PB4): $(SOURCES4)
	$(CC) $(CFLAGS) $(SOURCES4) -o $(PB4)

$(PB5): $(SOURCES5)
	$(CC) $(CFLAGS) $(SOURCES5) -o $(PB5)

run-p1:
	./$(PB1)

run-p2:
	./$(PB2)

run-p3:
	./$(PB3)

run-p4:
	./$(PB4)

run-p5:
	./$(PB5)

clean:
	rm -f $(PB1) $(PB2) $(PB3) $(PB4) $(PB5)
