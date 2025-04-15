#include "fraction.h"
#include <iostream>
#include <chrono>
#include "./include/bigint.h"
using namespace std;

void demonstrateOverflow() {
    cout << "--- Demonstrating Overflow ---" << endl;

    int a = 2147483647;
    int b = 2147483647;
    int overflow = a + b;
    cout << "int overflow(32 bits): " << a << " + " << b << " = " << overflow << endl;

    long long c = 9223372036854775807;
    long long d = 9223372036854775807;
    long long overflowLong = c + d;
    cout << "long long overflow(64 bits): " << c << " + " << d << " = " << overflowLong << endl;

    cout << "-----------------------------" << endl;
}

template <typename T>
void test(T a, T b) {
    auto start = chrono::high_resolution_clock::now();
    T sum = a + b;
    T product = a * b;
    auto end = chrono::high_resolution_clock::now();
    cout << "--- Using basic operations ---" << endl;
    cout << "Sum: " << sum << ", Product: " << product << endl;
    cout << "Time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns\n\n";
}

template <typename T>
void testFraction(T n1, T d1, T n2, T d2) {
    pair<T, T> fraction1(n1, d1);
    pair<T, T> fraction2(n2, d2);

    auto start = chrono::high_resolution_clock::now();
    auto sumResult = sum(fraction1, fraction2);
    auto productResult = product(fraction1, fraction2);
    auto end = chrono::high_resolution_clock::now();

    cout << "--- Using fraction operations ---" << endl;
    cout << "Fraction sum: " << sumResult << ", product: " << productResult << endl;
    cout << "Time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns\n\n";
}

int main() {
    cout << "========== Testing with values < 32 bits ==========\n";
    test<int>(10, 15);
    test<long long>(10LL, 15LL);
    test<bigint>(bigint("10"), bigint("15"));

    testFraction<int>(3, 4, 5, 6);
    testFraction<long long>(3LL, 4LL, 5LL, 6LL);
    testFraction<bigint>(bigint("3"), bigint("4"), bigint("5"), bigint("6"));

    cout << "\n========== Testing with values between 32 and 64 bits ==========\n";
    test<long long>(2147483650LL, 2147483648LL);
    test<bigint>(bigint("2147483650"), bigint("2147483648"));

    testFraction<long long>(2147483650LL, 7LL, 2147483648LL, 5LL);
    testFraction<bigint>(bigint("2147483650"), bigint("7"),
                         bigint("2147483648"), bigint("5"));

    cout << "\n========== Testing with values > 64 bits ==========\n";
    test<bigint>(bigint("922337203685477580812345"), bigint("922337203685477580734567"));
    testFraction<bigint>(bigint("922337203685477580812345"), bigint("123456789"),
                         bigint("922337203685477580734567"), bigint("987654321"));

    demonstrateOverflow();

    return 0;
}

