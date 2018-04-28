#include <iterator>
#include <algorithm>
#include <queue>
#include <cstddef>
#include "radix_sort.hpp"

inline char get_val_signbyte(int number, int position)
{
    return *((char*)&number + position);
}

inline unsigned char get_val_byte(int number, int position)
{
    return *((unsigned char*)&number + position);
}

void radixSort(Iterator first, Iterator last)
{
    const int n = std::distance(first, last);
    vector<int> copy_input_arr(first, last);
    const int counts_bucket = 256;
    std::queue<int> buckets[counts_bucket];
    std::size_t bucket_index;
    std::size_t size_bucket;
    const std::size_t num_bytes = 4;
    for(int i = 0; i < num_bytes - 1; ++i ){
        for(int j = 0; j < n; ++j){
            buckets[get_val_byte(copy_input_arr[j], i)].push(copy_input_arr[j]);
        }
        int k = 0;
        for(auto& bucket : buckets){
            size_bucket = bucket.size();
            for(int j = 0 ; j < size_bucket; ++j){
                copy_input_arr[k++] = bucket.front();
                bucket.pop();
            }
        }
    }
    for(int j = 0; j < n; ++j){
        buckets[get_val_signbyte(copy_input_arr[j], 3) + 128].push(copy_input_arr[j]);
    }
    int k = 0;
    for(auto& bucket : buckets){
        size_bucket = bucket.size();
        for(int j = 0 ; j < size_bucket; ++j){
            copy_input_arr[k++] = bucket.front();
            bucket.pop();
        }
    }
    copy(copy_input_arr.begin(), copy_input_arr.end(), first);
}
