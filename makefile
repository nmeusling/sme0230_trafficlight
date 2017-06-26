SRC_DIR = src

CC = gcc
CFLAGS = -Wall -std=c99

trafficlight: main.o input.o board.o manager.o ai.o
	$(CC) -o trafficlight $(SRC_DIR)/*.o $(CFLAGS)

main.o: $(SRC_DIR)/main.c $(SRC_DIR)/main.h
	$(CC) -c $(SRC_DIR)/main.c $(CFLAGS) -o $(SRC_DIR)/main.o

input.o: $(SRC_DIR)/input.c $(SRC_DIR)/input.h
	$(CC) -c $(SRC_DIR)/input.c $(CFLAGS) -o $(SRC_DIR)/input.o

board.o: $(SRC_DIR)/board.c $(SRC_DIR)/board.h
	$(CC) -c $(SRC_DIR)/board.c $(CFLAGS) -o $(SRC_DIR)/board.o

manager.o: $(SRC_DIR)/manager.c $(SRC_DIR)/manager.h
	$(CC) -c $(SRC_DIR)/manager.c $(CFLAGS) -o $(SRC_DIR)/manager.o

ai.o: $(SRC_DIR)/ai.c $(SRC_DIR)/ai.h
	$(CC) -c $(SRC_DIR)/ai.c $(CFLAGS) -o $(SRC_DIR)/ai.o

clean:
	rm trafficlight $(SRC_DIR)/*.o
