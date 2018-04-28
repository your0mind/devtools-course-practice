// Copyright 2018 Batanina Liubov

#include <gtest/gtest.h>
#include "include/radix_sort.hpp"
#include <vector>
#include <random>
#include <algorithm>

class RadixSortTest : public testing::Test {
protected:
    virtual void SetUp(){
        data.resize(10000);
        int seed = 1;
        mt19937 generator(seed);
        uniform_int_distribution<int> distribution(std::numeric_limits<int>::min(),
                                                   std::numeric_limits<int>::max());
        generate(data.begin(), data.end(), [&distribution, &generator](){
            return distribution(generator);
        });
    }
    vector<int> data;
};



TEST(RadixSortTest, lsd_radix_sort) {
    lsd_radix_sort(data.begin(), data.end());
    EXPECT_EQ(is_sorted(data.begin(), data.end()), true);
}

