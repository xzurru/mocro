# mocro Language

mocro is an open-source programming language inspired by Lua but designed to be better, faster, and more efficient. This repository contains a minimal interpreter for mocro, written in C.

## Features

- Lua-inspired syntax and semantics
- Lightweight and efficient interpreter
- Minimal arithmetic expression evaluator (as a starting point)
- **Advanced Syntax:** Optional type annotations, pattern matching, lambda (anonymous) functions, and enhanced loop constructs.
- **Performance:** Built-in JIT compiler support (stub for LLVM integration) and an optimized garbage collector.
- **Extensive Standard Library:** Modules for networking, filesystem, JSON/XML processing, multithreading, and a Foreign Function Interface (FFI) for native library integration.
- **Concurrency:** Support for coroutines and native threads with synchronization primitives.
- **Developer Tools:** VS Code extension for syntax highlighting, autocompletion, and debugging support.
- **Interoperability:** Language bindings for C and Python, and a plugin system for easy extensibility.

## Repository Structure


## Getting Started

### Prerequisites

- A C compiler (such as GCC)
- Make (optional, for building via the provided Makefile)

### Building

Clone the repository and compile the interpreter:

```bash
git clone https://github.com/xzurru/mocro.git
cd mocro
make
