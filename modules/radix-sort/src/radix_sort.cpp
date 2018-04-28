// Copyright 2018 Batanina Liubov
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#include <cstddef>
#include <stdexcept>
#include "include/radix_sort.hpp"

inline char getSignByte(int number, int position) {
    return *(reinterpret_cast<char*>(&number) + position);
}

inline unsigned char getByte(int number, int position) {
    return *(reinterpret_cast<unsigned char*>(&number) + position);
}

void radixSort(Iterator first, Iterator last) {
    if (first > last) {
      throw std::logic_error
               ("The first iterator must be less than the last iterator");
    }
    const int n = std::distance(first, last);
    std::vector<int> copy_in_arr(first, last);
    const int counts_bucket = 256;
    std::queue<int> buckets[counts_bucket];
    int size_bucket;
    const int num_bytes = 4;
    for (int i = 0; i < num_bytes - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            buckets[getByte(copy_in_arr[j], i)].push(copy_in_arr[j]);
        }
        int k = 0;
        for (auto& bucket : buckets) {
            size_bucket = bucket.size();
            for (int j = 0; j < size_bucket; ++j) {
                copy_in_arr[k++] = bucket.front();
                bucket.pop();
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        buckets[getSignByte(copy_in_arr[j], 3) + 128].push(copy_in_arr[j]);
    }
    int k = 0;
    for (auto& bucket : buckets) {
        size_bucket = bucket.size();
        for (int j = 0; j < size_bucket; ++j) {
            copy_in_arr[k++] = bucket.front();
            bucket.pop();
        }
    }
    copy(copy_in_arr.begin(), copy_in_arr.end(), first);
}
