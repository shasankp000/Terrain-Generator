SRC_DIR := C_recap
SRC := $(SRC_DIR)/basics.c
OUT := $(SRC_DIR)/basics.exe

.PHONY: all clean

all: $(OUT)

$(OUT): $(SRC)
	@gcc -O2 -Wall -Wextra "$<" -o "$@"

clean:
	@del /q "$(OUT)" 2>nul || true
