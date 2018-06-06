# BF-Interpreter

This is just a little personal project. Esoteric languages like BF have little to no practical use. I chose to design this interpreter in C for optimization, since C is a compiled language. Obviously the advantage gained from this decision is largely negligible.

Simple C implementation of a Brainf*** interpreter. Uses a 265-cell wraparound tape, each cell 8-bits wide with automatic overflow and underflow wraparound. Takes a .b or other text file as input and processes it as a BF program. By BF standard, all characters besides ><+-.,[] are considered no-op. Input is taken through STDIN, and is generally buffered character by character until a newline is reached. tests/rot13.b is a good example of this behavior.
