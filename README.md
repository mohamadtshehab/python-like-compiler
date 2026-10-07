# Python-like compiler

A small C++ lexer and parser for a subset of Python-like syntax. It reads a source file and writes an abstract syntax tree as a Graphviz DOT graph. It does not execute the input program.

## Requirements

- A C++17 compiler (`g++` or `clang++`) and `make`.
- Graphviz only if you want to render the DOT graph as an image. On Ubuntu, install it with `sudo apt-get install graphviz`.

The generated lexer and parser are included, so Flex and Bison are not needed to build the project.

## Build and run

From the repository root:

```bash
make
make run
```

`make` creates `build/compiler`. `make run` parses `examples/basic.py` and writes the graph to `build/output.gv`. To parse another file:

```bash
make run INPUT=path/to/input.py
```

You can also run the compiler directly, or pipe source code through standard input:

```bash
./build/compiler examples/basic.py > build/output.gv
printf 'x = 1\n' | ./build/compiler > build/output.gv
```

To render a PNG after installing Graphviz:

```bash
make image
```

The image is saved to `build/output.png`.

Run the parser regression tests with `make test` (requires Python 3).

## Project layout

| Path | Contents |
| --- | --- |
| `src/parser.y`, `src/lexer.l` | Bison grammar and Flex lexer source |
| `src/generated/` | Checked-in C++ parser and lexer used by the build |
| `src/python_ast_node.hpp`, `src/ast.cpp` | AST node types |
| `examples/basic.py` | Example input used by the quick-start commands |
| `examples/legacy/` | Existing example files and graph output preserved from the original layout |
| `build/` | Local binaries and generated output (ignored by Git) |

The parser covers a subset of Python-like constructs. A valid Python program is not necessarily supported by this grammar.
