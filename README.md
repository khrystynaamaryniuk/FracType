# FracType

A generic C++ fraction library that performs arithmetic on fractions across numeric types — `int`, `long long`, and arbitrary-precision `bigint` — demonstrating how type choice affects overflow behavior.

## Features
- Template-based fraction arithmetic (sum, product, reduce) compatible with any numeric type
- Arbitrary-precision support via bundled `bigint` to prevent overflow
- Input validation with exceptions on zero denominators
- Benchmarks comparing `int`, `long long`, and `bigint` performance
- Full unit test suite (8 cases, 28 assertions) using doctest

## Tech Stack
| Component | Details |
|---|---|
| Language | C++17 |
| Big integers | `include/bigint.h` (bundled) |
| Testing | `include/doctest.h` v2.4.11 (bundled) |

## Getting Started
```bash
git clone <url> && cd FracType
g++ fraction.cpp -o fraction_main && ./fraction_main
g++ unit_tests.cpp -o tests && ./tests
```

## How It Works
- Fractions are represented as `std::pair<T, T>` (numerator, denominator)
- `gcd<T>()` computes the greatest common divisor to reduce fractions
- `sum()` and `product()` perform cross-multiplication then auto-reduce
- The same functions run on `int`, `long long`, or `bigint` without modification
- `demonstrateOverflow()` shows where fixed-width types silently wrap around

## Architecture
- **`fraction.h`** — all template logic: `gcd`, `validate`, `reduce`, `sum`, `product`, `operator<<`
- **`fraction.cpp`** — demo driver: tests three numeric domains and benchmarks each
- **`unit_tests.cpp`** — doctest suite covering validation, reduction, arithmetic, edge cases
- **`include/bigint.h`** — self-contained arbitrary-precision integer library
- **`include/doctest.h`** — single-header testing framework

## Dependencies
- `include/bigint.h` — bundled, no install needed
- `include/doctest.h` — bundled, no install needed
- C++17-compatible compiler (`g++` or `clang++`)
