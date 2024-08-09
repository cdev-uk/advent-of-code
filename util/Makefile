CFLAGS=-Wall -Wextra -Werror
CC=clang
LDLIBS=
UTIL_HEADERS=*.h
UNITY_SOURCE=../Unity/src/unity.c
UNITY_HEADERS=../Unity/src/*.h

build/strings: strings.c $(UTIL_HEADERS) $(UNITY_SOURCE) $(UNITY_HEADERS)
	$(CC) $(CFLAGS) -o build/strings strings.c $(UNITY_SOURCE) $(LDLIBS)

clean:
	rm -f build/*

.PHONY: clean
