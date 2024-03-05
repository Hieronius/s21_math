CC=gcc -std=c11 -D_GNU_SOURCE
TST_LIBS=-lcheck -lsubunit -lm -lpthread
GCOV_LIBS=--coverage
BUILD_PATH=./
SOURCES=sourceFiles/s21_*.c
TEST_F=testFiles/test_*.c
H1=sourceFiles/s21_math.h
H2=testFiles/s21_math.h
LIBO=*.o
LIBA=s21_math.a
EXE=test_*
OS:=$(shell uname -s)

ifeq ($(OS),Linux)
		CC+=-D LINUX_OS
	else
		ifeq ($(OS),Darwin)
			CC+=-D MAC_OS
		else
		CC+=-D LINUX_OS
		endif
endif

all: s21_math.a test gcov_report

clean:
	rm -rf *.a && rm -rf *.o
	rm -rf *.info && rm -rf *.gcda && rm -rf *.gcno &&  rm -rf *.gcov
	rm -rf report/ && rm -rf test_*

test: s21_math.a
	$(CC) testFiles/test_pow.c -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)test_pow
	$(CC) testFiles/test_exp.c -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)test_exp
	$(CC) testFiles/test_fabs.c -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)test_fabs
	$(CC) testFiles/test_fmod.c -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)test_fmod
	$(CC) testFiles/test_log.c -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)test_log
	$(CC) testFiles/test_factorial.c -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)test_factorial

start_test:
	$(BUILD_PATH)test_pow
	$(BUILD_PATH)test_exp
	$(BUILD_PATH)test_fabs
	$(BUILD_PATH)test_fmod
	$(BUILD_PATH)test_log
	$(BUILD_PATH)test_factorial

rebuild: clean all

s21_math.a: clean
	$(CC) -c $(SOURCES)
	ar rcs $(LIBA) $(LIBO)
	ranlib $(LIBA)

gcov_report: s21_math.a
	$(CC) $(GCOV_LIBS) testFiles/test_pow.c $(SOURCES) $(LIBA) -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)test_pow
	$(CC) $(GCOV_LIBS) testFiles/test_exp.c $(SOURCES) $(LIBA) -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)test_exp
	$(CC) $(GCOV_LIBS) testFiles/test_fabs.c $(SOURCES) $(LIBA) -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)test_fabs
	$(CC) $(GCOV_LIBS) testFiles/test_fmod.c $(SOURCES) $(LIBA) -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)test_fmod
	$(CC) $(GCOV_LIBS) testFiles/test_log.c $(SOURCES) $(LIBA) -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)test_log
	$(CC) $(GCOV_LIBS) testFiles/test_factorial.c $(SOURCES) $(LIBA) -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)test_factorial
	$(BUILD_PATH)test_pow
	$(BUILD_PATH)test_exp
	$(BUILD_PATH)test_fabs
	$(BUILD_PATH)test_fmod
	$(BUILD_PATH)test_log
	$(BUILD_PATH)test_factorial
	lcov -t "test" -c -d $(BUILD_PATH) --output-file $(BUILD_PATH)coverage.info
	genhtml $(BUILD_PATH)coverage.info --output-directory $(BUILD_PATH)report/

check:
	@echo
	@echo ===CPPCHECK===
	@echo
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES) $(H1)
	cppcheck --enable=all --suppress=missingIncludeSystem $(TEST_F) $(H2)
	@echo
	@echo ===STYLE TEST===
	@echo
	clang-format -style=Google -n $(SOURCES) $(H1)
	clang-format -style=Google -n $(TEST_F) $(H2)
	@echo
	@echo ===VALGRIND TEST===
	@echo
	valgrind --tool=memcheck --leak-check=yes $(BUILD_PATH)test_pow
	valgrind --tool=memcheck --leak-check=yes $(BUILD_PATH)test_exp
	valgrind --tool=memcheck --leak-check=yes $(BUILD_PATH)test_fabs
	valgrind --tool=memcheck --leak-check=yes $(BUILD_PATH)test_fmod
	valgrind --tool=memcheck --leak-check=yes $(BUILD_PATH)test_log
	valgrind --tool=memcheck --leak-check=yes $(BUILD_PATH)test_factorial

