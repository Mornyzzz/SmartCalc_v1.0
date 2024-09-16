TARGET = SmartCalc

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
OS = $(shell uname)
CONTROLLER = calc
MODULES = $(wildcard data_structures/*.c  functions/*.c)
OBJECTS = $(patsubst %.c, %.o, $(MODULES))

ifeq ($(OS), Linux)
	LDLIBS = -lcheck_pic -pthread -lrt -lm -lsubunit
else
	LDLIBS = -lcheck -lm
endif

all: clean install


s21_smartcalc:
	@$(CC) $(CFLAGS) -c $(MODULES) smartcalc.h

s21_smartcalc.a: s21_smartcalc
	@ar rcs s21_smartcalc.a *.o
	@rm *.o *.h.gch

test: s21_smartcalc.a
	@echo "┏=========================================┓"
	@echo "┃                 Tests                   ┃"
	@echo "┗=========================================┛"
	@$(CC) tests/controller_tests.c tests/controller_tests.h s21_smartcalc.a $(COMPILING_FLAGS) $(LDLIBS) -o ./tests/test
	./tests/test


install:
	@echo "Start installation"
	@mkdir -p ../build
	@cd gui && qmake && make && make clean && rm -rf Makefile && mv SmartCalcpls ../../build/$(TARGET).app
	@echo "┏=========================================┓"
	@echo "┃    The installation was successful.     ┃"
	@echo "┃     The project is located in the       ┃"
	@echo "┃              build folder.              ┃"
	@echo "┗=========================================┛"

uninstall:
	@rm -rf ~/Desktop/SmartCalc.app ../build
	@echo "Uninstall completed successfully"

dvi:
	@open ../README_RUS.md

dist: install
	@mkdir -p ../dist
	@cp -R ../build/$(TARGET).app ../dist
	@cp ../README_RUS.md ../dist && cp ../README.md ../dist
	@cd ../dist && tar cvzf $(TARGET)_v1.0.tgz *
	@cd ../dist && rm -rf $(TARGET).app README.md README_RUS.md
	@echo "The build was successfully archived"

clean:
	@echo "Deleting unnecessary files..."
	@rm -rf *.o *.h.gch *.a *.dSYM **/*.dSYM *.log **/*.log report matrix_tests.info test_report.txt tests/test *.gcno *.info


gcov_report: s21_smartcalc.a
	@echo "┏=========================================┓"
	@echo "┃               HTML Report               ┃"
	@echo "┗=========================================┛"
	@$(CC) -c $(CFLAGS) --coverage functions/calc.c $(MODULES)
	@$(CC) -c $(CFLAGS) tests/controller_tests.c
	@$(CC) $(CFLAGS) *.o -o ./tests/test $(LDLIBS) -lgcov
	@./tests/test > test_report.txt || true
	@lcov -o calc_tests.info -c -d .
	@genhtml -o report calc_tests.info
	@rm *.o *.gcda *.gcno
	@rm -rf *.o *.h.gch *.a *.dSYM **/*.dSYM *.log **/*.log matrix_tests.info test_report.txt tests/test
	@$(OPEN) ./report/index.html

style_check:
	@echo "┏=========================================┓"
	@echo "┃  Checking your code for Google Style    ┃"
	@echo "┗=========================================┛"
	@cp ../materials/linters/.clang-format .
	@clang-format -n *.h **/*.c **/*.h **/*.h **/*.cpp
	@rm ./.clang-format

style_fix:
	@echo "┏=========================================┓"
	@echo "┃  Formatting your code for Google Style  ┃"
	@echo "┗=========================================┛"
	@cp ../materials/linters/.clang-format .
	@clang-format -i *.h **/*.c **/*.h **/*.h **/*.cpp
	@rm ./.clang-format

valgrind_check: test
	@CK_FORK=no valgrind --leak-check=full \
	--show-leak-kinds=all --track-origins=yes -s tests/test
	@echo "┏=========================================┓"
	@echo "┃        Valgrind check is over           ┃"
	@echo "┃       logs have been generated          ┃"
	@echo "┗=========================================┛"

fonts:
	open view/fonts/.

fclean: clean
	@rm -rf ../build ../dist ~/Desktop/$(TARGET).app controller_tests_vg.log module_tests_tests_vg.log

.PHONY: all install uninstall dvi dist test gcov_report valgrind_check style_check format_style fonts clean fclean
