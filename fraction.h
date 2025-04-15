#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
#include <utility>
#include <stdexcept>


using namespace std;


template<typename T>
T gcd(T a, T b) {
    while (b != T(0)) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Validate (denominator is not 0)
template<typename T>
void validate(pair<T, T>& fraction) {
    T denom = fraction.second; 
    if (denom == T(0)) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
}

// Reduce
template<typename T>
void reduce(pair<T, T>& fraction) {
    validate(fraction);
    T divisor = gcd(fraction.first, fraction.second);
    fraction.first = fraction.first / divisor;
    fraction.second = fraction.second / divisor;
}

// Product
template<typename T>
pair<T, T> product(pair<T, T> fraction1, pair<T, T> fraction2) {
    validate(fraction1);
    validate(fraction2);
    pair<T, T> result = {
        fraction1.first * fraction2.first,
        fraction1.second * fraction2.second
    };
    reduce(result);
    return result;
}

// Sum
template<typename T>
pair<T, T> sum(pair<T, T> fraction1, pair<T, T> fraction2) {
    validate(fraction1);
    validate(fraction2);
    T numerator = fraction1.first * fraction2.second + fraction2.first * fraction1.second;
    T denominator = fraction1.second * fraction2.second;
    pair<T, T> result = {numerator, denominator};
    reduce(result);
    return result;
}

// Stream overload
template<typename T>
ostream& operator<<(ostream& os, const pair<T, T>& fraction) {
    os << fraction.first << "/" << fraction.second;
    return os;
}

#endif

