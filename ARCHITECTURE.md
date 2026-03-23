# Architecture

FracType is a header-only template library with a thin demo driver and test suite.

## Component Overview

```
fraction.h          ← core logic (all template functions)
    ↑
fraction.cpp        ← demo: instantiates templates with int/long long/bigint
unit_tests.cpp      ← doctest suite: independently includes fraction.h
    ↑
include/
  bigint.h          ← arbitrary-precision arithmetic (external, bundled)
  doctest.h         ← test framework (external, bundled)
```

## Data Model

Fractions are `std::pair<T, T>` where `T` is any numeric type satisfying:
- `operator%` (for GCD)
- `operator==`, `operator<` (for comparisons)
- `T(0)` construction (for zero checks)

`int`, `long long`, and `bigint` all satisfy these constraints.

## Key Functions (`fraction.h`)

| Function | Description |
|---|---|
| `gcd(a, b)` | Euclidean algorithm; always returns positive |
| `validate(f)` | Throws `invalid_argument` if denominator is zero |
| `reduce(f)` | Divides numerator and denominator by their GCD in-place |
| `sum(f1, f2)` | Cross-multiply, add, reduce |
| `product(f1, f2)` | Multiply numerators and denominators, reduce |

## Overflow Behavior

| Type | Max value | Overflow behavior |
|---|---|---|
| `int` | ~2.1 × 10⁹ | Silent wraparound |
| `long long` | ~9.2 × 10¹⁸ | Silent wraparound |
| `bigint` | Unlimited | Correct result (slower) |
