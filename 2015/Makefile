CFLAGS=-Wall -Wextra -Werror
CC=clang
LDLIBS=
UTIL_HEADERS=../util/*.h
UNITY_SOURCE=../Unity/src/unity.c
UNITY_HEADERS=../Unity/src/*.h

build/01a: src/01/01a.c src/01/01.h $(UTIL_HEADERS)
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

build/01b: src/01/01b.c src/01/01.h $(UTIL_HEADERS)
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

build/01t: src/01/01t.c src/01/01.h $(UTIL_HEADERS) $(UNITY_SOURCE) $(UNITY_HEADERS)
	$(CC) $(CFLAGS) -o $@ $< $(UNITY_SOURCE) $(LDLIBS)

build/02a: src/02/02a.c src/02/02.h $(UTIL_HEADERS)
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

build/02b: src/02/02b.c src/02/02.h $(UTIL_HEADERS)
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

build/02t: src/02/02t.c src/02/02.h $(UTIL_HEADERS) $(UNITY_SOURCE) $(UNITY_HEADERS)
	$(CC) $(CFLAGS) -o $@ $< $(UNITY_SOURCE) $(LDLIBS)

clean:
	rm -f build/*

.PHONY: clean
