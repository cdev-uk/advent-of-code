# Advent of Code

Advent of Code solutions in C.

I am solving these problems for fun and to demonstrate C solutions.

These are not necessarily the most efficient, elegant or robust solutions. For
example, I have not always freed memory allocated on the heap, partly because
these solutions run for a very short period of time - seconds in most cases -
and the kernel will reclaim any memory allocated to a process when the process
terminates.

As the input is 'known' there is minimal error checking, real programs would
have significantly more validation and unit tests.

For C solutions, C99 is assumed as a minimum and solutions are compiled with:

```
clang -Wall -Wextra -Werror
```

`-Wall` enables the majority (but not all, despite the name) of warnings.

`-Wextra` enables some extra warnings that are useful.

`-Werror` turns all warnings into errors, so they can't be ignored.

I have not used `-Weverything` as it is extremely difficult to write code that
meets every warning available in LLVM, especially when third party libraries
are used.

There are helper scripts to automatically build and run a day + part solution
with the relevant arguments:

```
./run YEAR DAY PART
```

e.g.

```
./run 2015 01 a
```

and also for tests:

```
./test YEAR DAY
```

e.g.

```
./test 2015 01
```

## Tests

Tests use the Unity framework, which is included as a submodule. Each day has
its own test source code.

## Header files

Each day has its own header file which contains all the functions for both
parts. The header file is included by both solution files and the test file.
