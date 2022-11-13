CC:=clang
RM:=rm -rf
MKDIR:=mkdir -p

EXE:=test_cases.o
TESTS:=tests
SRC:=src
BIN:=bin

C_FLAGS:=-std=c99 -O2 -Wall -Walloca -Wextra -Wpedantic -Wformat=2                        \
		 -Wno-unused-parameter -Wshadow -Wwrite-strings -Wstrict-prototypes               \
		 -Wold-style-definition -Wredundant-decls -Wnested-externs -Wmissing-include-dirs \
		 -fsanitize=address
EXE_FLAGS:=ASAN_OPTIONS=detect_leaks=1 \
		   LSAN_OPTIONS=suppressions=lsan.supp

all: build
	@$(EXE_FLAGS) ./$(BIN)/$(EXE)

build: clean $(BIN)
	@$(CC) $(SRC)/string_builder.c $(TESTS)/sb_*_test_cases.c $(TESTS)/Unity/unity.c \
		   -I$(SRC)                                                                  \
		   $(C_FLAGS)                                                                \
		   -o $(BIN)/$(EXE)

$(BIN):
	@$(MKDIR) $(BIN)

clean:
	@$(RM) $(BIN)
