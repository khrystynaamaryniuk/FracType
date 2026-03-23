#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"
#include "fraction.h"
#include "./include/bigint.h"
#include <utility>
#include <sstream>
using namespace std;

TEST_CASE("validate throws on zero denominator") {
    pair<int, int> frac = {1, 0};
    CHECK_THROWS_AS(validate(frac), invalid_argument);

    pair<bigint, bigint> bigfrac = {1,0};
    CHECK_THROWS_AS(validate(bigfrac), invalid_argument);
}

TEST_CASE("gcd function correctness") {
    CHECK(gcd(48, 18) == 6);
    CHECK(gcd<long long>(10000000000LL, 2500000000LL) == 2500000000LL);
    CHECK(gcd<bigint>(100, 25) == 25);
}

TEST_CASE("reduce simplifies fractions correctly") {
    pair<int, int> frac = {8, 12};
    reduce(frac);
    CHECK(frac.first == 2);
    CHECK(frac.second == 3);

    pair<bigint, bigint> bigfrac = {100, 250};
    reduce(bigfrac);
    CHECK(bigfrac.first == 2);
    CHECK(bigfrac.second == 5);
}

TEST_CASE("sum computes correct reduced result") {
    pair<int, int> f1 = {1, 2};
    pair<int, int> f2 = {1, 3};
    pair<int, int> result = sum(f1, f2);
    CHECK(result.first == 5);
    CHECK(result.second == 6);

    pair<bigint, bigint> bf1 = {1, 4};
    pair<bigint, bigint> bf2 = {1, 4};
    pair<bigint, bigint> bigresult = sum(bf1, bf2);
    CHECK(bigresult.first == 1);
    CHECK(bigresult.second == 2);
}

TEST_CASE("product computes correct reduced result") {
    pair<int, int> f1 = {2, 3};
    pair<int, int> f2 = {3, 4};
    pair<bigint, bigint> result = product(f1, f2);
    CHECK(result.first == 1);   // 6/12 = 1/2
    CHECK(result.second == 2);

    pair<bigint, bigint> bf1 = {5, 6};
    pair<bigint, bigint> bf2 = {2, 3};
    pair<bigint, bigint> bigresult = product(bf1, bf2); // 10/18 = 5/9
    CHECK(bigresult.first == 5);
    CHECK(bigresult.second == 9);
}

TEST_CASE("fraction handles negatives correctly") {
    pair<int, int> f1 = {-1, 2};
    pair<int, int> f2 = {1, 2};
    auto result = sum(f1, f2);
    CHECK(result.first == 0);
    CHECK(result.second == 1);

    pair<bigint, bigint> bf1 = {-1, 4};
    pair<bigint, bigint> bf2 = {2, 8};
    auto bigresult = sum(bf1, bf2);
    CHECK(bigresult.first == 0);
    CHECK(bigresult.second == 1);
}

TEST_CASE("zero numerator is reduced properly") {
    pair<int, int> f = {0, 5};
    reduce(f);
    CHECK(f.first == 0);
    CHECK(f.second == 1);

    pair<bigint, bigint> bf = {0, 123456789};
    reduce(bf);
    CHECK(bf.first == 0);
    CHECK(bf.second == 1);
}
