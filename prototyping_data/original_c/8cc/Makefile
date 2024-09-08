CFLAGS=-Wall -Wno-strict-aliasing -std=gnu11 -g -I. -O0 -fPIE -fprofile-arcs -ftest-coverage
LDFLAGS=-lgcov
OBJS=cpp.o debug.o dict.o gen.o lex.o vector.o parse.o buffer.o map.o \
     error.o path.o file.o set.o encoding.o
TESTS := $(patsubst %.c,%.bin,$(filter-out test/testmain.c,$(wildcard test/*.c)))
ECC=./8cc -c
override CFLAGS += -DBUILD_DIR='"$(shell pwd)"'

8cc: 8cc.h main.o $(OBJS)
	cc -pie -o $@ main.o $(OBJS) $(LDFLAGS)

$(OBJS) utiltest.o main.o: 8cc.h keyword.inc

utiltest: 8cc.h utiltest.o $(OBJS)
	cc -pie -o $@ utiltest.o $(OBJS) $(LDFLAGS)

test/%.o: test/%.c $(ECC)
	$(ECC) -o $@ $<

test/%.bin: test/%.o test/testmain.o
	cc -pie -o $@ $< test/testmain.o $(LDFLAGS)

self: 8cc cleanobj
	$(MAKE) CC="$(ECC)" CFLAGS="$(CFLAGS)" 8cc

test: 8cc $(TESTS)
	$(MAKE) CC="$(CC)" CFLAGS="$(CFLAGS)" utiltest
	./utiltest
	./test/ast.sh
	./test/negative.py
	$(MAKE) runtests

runtests:
	@for test in $(TESTS); do  \
	    ./$$test || exit;      \
	done

coverage: test
	gcov *.c
	@echo "Coverage data generated in .gcov files"
	@total_lines=0; total_executed=0; \
	for file in *.c.gcov; do \
		lines=$$(grep -c "^    [1-9]" $$file); \
		executed=$$(grep -c "^    [1-9].*:.*" $$file); \
		total_lines=$$((total_lines + lines)); \
		total_executed=$$((total_executed + executed)); \
	done; \
	echo "Total coverage: $$((100 * total_executed / total_lines))% of $$total_lines lines"

stage1:
	$(MAKE) cleanobj
	[ -f 8cc ] || $(MAKE) 8cc
	mv 8cc stage1

stage2: stage1
	$(MAKE) cleanobj
	$(MAKE) CC=./stage1 ECC="./stage1 -c" CFLAGS="$(CFLAGS)" 8cc
	mv 8cc stage2

stage3: stage2
	$(MAKE) cleanobj
	$(MAKE) CC=./stage2 ECC="./stage2 -c" CFLAGS="$(CFLAGS)" 8cc
	mv 8cc stage3

testtest:
	$(MAKE) clean
	$(MAKE) $(TESTS)
	$(MAKE) runtests

fulltest: testtest
	$(MAKE) stage1
	$(MAKE) CC=./stage1 ECC="./stage1 -c" CFLAGS="$(CFLAGS)" test
	$(MAKE) stage2
	$(MAKE) CC=./stage2 ECC="./stage2 -c" CFLAGS="$(CFLAGS)" test
	$(MAKE) stage3
	cmp stage2 stage3

clean: cleanobj cleancov
	rm -f 8cc stage?

cleanobj:
	rm -f *.o *.s test/*.o test/*.bin utiltest

cleancov:
	rm -f *.gcda *.gcno *.gcov coverage.info
	rm -rf out

count_c_files:
	@echo "Number of project C files: $$(ls *.c | wc -l)"

all: 8cc

.PHONY: clean cleanobj cleancov test runtests fulltest self all coverage count_c_filescm