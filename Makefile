CC      = g++ -w
CFLAGS  = -Wall
INCLUDE	= -I include/

BUILD_DIR = build/
SRC_DIR   = src/
EXEC_NAME = conv

C_FILES   = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES = $(addprefix $(BUILD_DIR), $(notdir $(C_FILES:.c=.o)))

all: test 

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

build:
	mkdir -p $(BUILD_DIR)

test: build $(EXEC_NAME) 

clean:
	rm $(BUILD_DIR)*.o $(EXEC_NAME)
