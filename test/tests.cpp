// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"


TEST(CheckPrime, ZeroAndOneNotPrime) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
}

TEST(CheckPrime, TwoAndThreeArePrime) {
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
}

TEST(CheckPrime, EvenNumbersNotPrime) {
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(6));
    EXPECT_FALSE(checkPrime(100));
}

TEST(CheckPrime, KnownPrimes) {
    EXPECT_TRUE(checkPrime(5));
    EXPECT_TRUE(checkPrime(7));
    EXPECT_TRUE(checkPrime(11));
    EXPECT_TRUE(checkPrime(13));
    EXPECT_TRUE(checkPrime(97));
}

TEST(CheckPrime, KnownComposites) {
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(15));
    EXPECT_FALSE(checkPrime(49));
    EXPECT_FALSE(checkPrime(1000));
}

TEST(CheckPrime, LargePrime) {
    EXPECT_TRUE(checkPrime(999983));
    EXPECT_FALSE(checkPrime(999984));
}


TEST(NPrime, ZeroReturnsZero) {
    EXPECT_EQ(nPrime(0), 0ULL);
}

TEST(NPrime, FirstTenPrimes) {
    EXPECT_EQ(nPrime(1),  2ULL);
    EXPECT_EQ(nPrime(2),  3ULL);
    EXPECT_EQ(nPrime(3),  5ULL);
    EXPECT_EQ(nPrime(4),  7ULL);
    EXPECT_EQ(nPrime(5),  11ULL);
    EXPECT_EQ(nPrime(6),  13ULL);
    EXPECT_EQ(nPrime(7),  17ULL);
    EXPECT_EQ(nPrime(8),  19ULL);
    EXPECT_EQ(nPrime(9),  23ULL);
    EXPECT_EQ(nPrime(10), 29ULL);
}

TEST(NPrime, HundredthPrime) {
    EXPECT_EQ(nPrime(100), 541ULL);
}


TEST(NextPrime, AfterZeroAndOne) {
    EXPECT_EQ(nextPrime(0), 2ULL);
    EXPECT_EQ(nextPrime(1), 2ULL);
}

TEST(NextPrime, AfterEvenNumbers) {
    EXPECT_EQ(nextPrime(4),  5ULL);
    EXPECT_EQ(nextPrime(6),  7ULL);
    EXPECT_EQ(nextPrime(10), 11ULL);
    EXPECT_EQ(nextPrime(14), 17ULL);
}

TEST(NextPrime, AfterPrimeSkipsItself) {
    EXPECT_EQ(nextPrime(2),  3ULL);
    EXPECT_EQ(nextPrime(3),  5ULL);
    EXPECT_EQ(nextPrime(5),  7ULL);
    EXPECT_EQ(nextPrime(11), 13ULL);
}

TEST(NextPrime, LargeValue) {
    EXPECT_EQ(nextPrime(100), 101ULL);
    EXPECT_EQ(nextPrime(200), 211ULL);
}


TEST(SumPrime, BoundBelowTwo) {
    EXPECT_EQ(sumPrime(0), 0ULL);
    EXPECT_EQ(sumPrime(1), 0ULL);
    EXPECT_EQ(sumPrime(2), 0ULL);
}

TEST(SumPrime, SmallBounds) {
    EXPECT_EQ(sumPrime(3),  2ULL);   
    EXPECT_EQ(sumPrime(6),  10ULL);  
    EXPECT_EQ(sumPrime(10), 17ULL);  
}

TEST(SumPrime, BoundNotIncluded) {
    EXPECT_EQ(sumPrime(11), 17ULL);  
    EXPECT_EQ(sumPrime(12), 28ULL);  
}

TEST(SumPrime, SumUpToTwenty) {
    EXPECT_EQ(sumPrime(20), 77ULL);
}

TEST(SumPrime, SumUpToHundred) {
    EXPECT_EQ(sumPrime(100), 1060ULL);
}