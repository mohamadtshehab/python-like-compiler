CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic
CPPFLAGS += -Isrc -Isrc/generated

SOURCES := src/ast.cpp src/generated/parser.cpp src/generated/lexer.cpp
HEADERS := src/python_ast_node.hpp src/generated/parser.hpp
BIN := build/compiler
INPUT ?= examples/basic.py
GRAPH ?= build/output.gv
IMAGE ?= build/output.png

.PHONY: all run image test

all: $(BIN)

$(BIN): $(SOURCES) $(HEADERS) | build
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) -o $@

build:
	mkdir -p build

run: $(BIN)
	$(BIN) "$(INPUT)" > "$(GRAPH)"

image: run
	@command -v dot >/dev/null || { echo "Install Graphviz to use make image (on Ubuntu: sudo apt-get install graphviz)"; exit 1; }
	dot -Tpng "$(GRAPH)" -o "$(IMAGE)"

test: $(BIN)
	python3 -m unittest discover -s tests -v
