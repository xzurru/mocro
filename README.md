# mocro Language

mocro is an open-source programming language inspired by Lua, enhanced to be better, faster, and more efficient. This advanced version incorporates:

- **Advanced Syntax & Features:**
  - Optional type annotations for variables and function parameters.
  - Pattern matching for expressive control flow.
  - Enhanced loops (e.g., foreach) for easier iteration over collections.
  - Lambda expressions and anonymous functions for functional programming.

- **Performance Optimization:**
  - Integration of a JIT compiler (via LLVM) to boost runtime performance.
  - Optimized memory management with an efficient garbage collector.

- **Standard Library Extensions:**
  - Modules for networking, filesystem, JSON/XML processing, and multithreading.
  - A Foreign Function Interface (FFI) for seamless integration with native C/C++ libraries.

- **Concurrency & Parallelism:**
  - Support for coroutines and lightweight threads for asynchronous programming.
  - Synchronization primitives (mutexes, semaphores) for safe parallel execution.

- **Tooling & Developer Experience:**
  - A VS Code extension for syntax highlighting, autocompletion, and debugging.
  - A package management and build tool to ease project scaling.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)
- Make (for building the project)
- LLVM (if you want to experiment with the JIT features)

### Building

Clone the repository and build the interpreter/compiler:

```bash
git clone https://github.com/xzurru/mocro.git
cd mocro
make
