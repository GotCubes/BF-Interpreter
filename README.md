# BF-Interpreter

Simple C implementation of a Brainf*** interpreter. Uses a 265-cell wraparound tape, each cell 8-bits wide with automatic overflow and underflow wraparound. Takes a .b or other text file as input and processes it as a BF program. By BF standard, all characters besides ><+-.,[] are considered no-op.

Simple test programs have been provided in the tests/ directory.
