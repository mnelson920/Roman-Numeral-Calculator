cc = gcc
CFLAGS = -c -Wall
LIBS = -lcheck -lm -lpthread -lrt -lsubunit
COV_LIBS = -lgcov -coverage
SRC_DIR = src
TEST_DIR = test
SRC_FILES = $(addprefix $(SRC_DIR)/, *.c)
TEST_FILES = $(addprefix $(TST_DIR)/, *.c)
GCOV = gcovr 
GCONV_FLAGS = -r . --html --html-details 

all: test

main.o: $(addprefix $(SRC_DIR)/, main.c) $(addprefix $(SRC_DIR)/, roman_numeral.h)
	$(cc) $(CFLAGS) $(addprefix $(SRC_DIR)/, main.c)

roman_numeral.o: $(addprefix $(SRC_DIR)/, roman_numeral.c) $(addprefix $(SRC_DIR)/, roman_numeral.h)
	$(cc) $(CFLAGS) $(addprefix $(SRC_DIR)/, roman_numeral.c)

RomanNumeralCalc: main.o roman_numeral.o
	$(cc) -o RomanNumeralCalc main.o roman_numeral.o

roman_numeral_test.o: $(addprefix $(TEST_DIR)/, roman_numeral_test.c) $(addprefix $(SRC_DIR)/, roman_numeral.h)
	$(cc) $(CFLAGS) $(addprefix $(TEST_DIR)/, roman_numeral_test.c)

RomanNumeralCalc-test: roman_numeral_test.o roman_numeral.o
	$(cc) -o RomanNumeralCalc-test roman_numeral.o roman_numeral_test.o $(LIBS) $(COV_LIBS)

test: RomanNumeralCalc-test
	./RomanNumeralCalc-test

.PHONY: clean all

clean:
	-rm *.o RomanNumeralCalc-test