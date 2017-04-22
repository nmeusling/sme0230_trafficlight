SRC_DIR = src

CC = gcc
CFLAGS = -Wall -std=c99

trafficlight: main.o input.o board.o
	$(CC) -o trafficlight $(SRC_DIR)/*.o $(CFLAGS)

main.o: $(SRC_DIR)/main.c $(SRC_DIR)/main.h
	$(CC) -c $(SRC_DIR)/main.c $(CFLAGS) -o $(SRC_DIR)/main.o

input.o: $(SRC_DIR)/input.c $(SRC_DIR)/input.h
	$(CC) -c $(SRC_DIR)/input.c $(CFLAGS) -o $(SRC_DIR)/input.o

board.o: $(SRC_DIR)/board.c $(SRC_DIR)/board.h
	$(CC) -c $(SRC_DIR)/board.c $(CFLAGS) -o $(SRC_DIR)/board.o

clean:
	rm trafficlight $(SRC_DIR)/*.o
