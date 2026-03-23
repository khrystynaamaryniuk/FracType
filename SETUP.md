# Setup & Build Guide

## Requirements
- `g++` or `clang++` with C++17 support
- No external packages — all dependencies are bundled in `include/`

## Build Commands
```bash
# Build and run the demo
g++ -std=c++17 fraction.cpp -o fraction_main
./fraction_main

# Build and run the test suite
g++ -std=c++17 unit_tests.cpp -o tests
./tests
```

## Project Structure
```
FracType/
├── fraction.h          # Template library: gcd, validate, reduce, sum, product
├── fraction.cpp        # Demo driver: benchmarks across int / long long / bigint
├── unit_tests.cpp      # doctest suite (8 cases, 28 assertions)
└── include/
    ├── bigint.h        # Bundled arbitrary-precision integer library
    └── doctest.h       # Bundled single-header test framework (v2.4.11)
```

## Expected Output
```
# fraction_main
========== Testing with values < 32 bits ==========
...
--- Demonstrating Overflow ---
int overflow(32 bits): 2147483647 + 2147483647 = -2

# tests
8 test cases | 8 passed | 0 failed
28 assertions | 28 passed | 0 failed
Status: SUCCESS
```
