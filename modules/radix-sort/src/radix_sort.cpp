#include "radix_sort.hpp"

using std::vector<int>::iterator Iterator;

void lsd_radix_sort_bits(Iterator first, Iterator last)
{
    for (int lsb = 0; lsb < 32; ++lsb)
        std::stable_partition(first, last, radix_compare(lsb));
}

void lsd_radix_sort(Iterator first, Iterator last){
    const int n = std::distance(first, last);
    const int counts_bucket = 19;
    std::queue<int> buckets[counts_bucket];
    int bucket_index;
    int max = fabs(*std::max_element(first, last, [](int v1, int v2){
        return fabs(v1) < fabs(v2);
    }));
    int size_bucket;
    for(int power = 1; max != 0; power *= 10, max /= 10 ){
        for(auto it = first; it != last; ++it){
            bucket_index = (*it / power) % 10 + 9;
            buckets[bucket_index].push(*it);
        }
        Iterator it = first;
        for(auto& bucket : buckets){
            size_bucket = bucket.size();
            for(int i = 0 ; i < size_bucket; ++i){
                *it = bucket.front();
                bucket.pop();
                it++;
            }
        }
    }
}

void lsd_compact_radix_sort(Iterator first, Iterator last)
{
    const int n = std::distance(first, last);
    const int counts_bucket = 19;
    int max = fabs(*std::max_element(first, last, [](int v1, int v2){
        return fabs(v1) < fabs(v2);
    }));
    vector<int> bucket_index(n);
    int current_position = 0;
    int val_it;
    vector<int> sizes (counts_bucket);
    vector<int> shifts(counts_bucket);
    vector<int> radix_array(n);
    vector<int> copy_input_arr(n);
    copy(first, last, copy_input_arr.begin());

    for(int power = 1; max != 0; power *= 10, max /= 10 ){
        for(int i = 0 ; i < n; ++i){
            bucket_index[i] = (copy_input_arr[i] / power) % 10 + 9;
            sizes[bucket_index[i]]++;
        }
        current_position = 0;
        for(int i = 0 ; i < counts_bucket; ++i){
            shifts[i] = current_position;
            current_position += sizes[i];
        }
        for(int i = 0 ; i < n; ++i){
            radix_array[shifts[bucket_index[i]]++] = copy_input_arr[i];
        }
        copy(radix_array.begin(), radix_array.end(), copy_input_arr.begin());
        fill(shifts.begin(), shifts.end(), 0);
        fill(sizes.begin(),  sizes.end(),  0);
        fill(bucket_index.begin(), bucket_index.end(), 0);
    }
    copy(radix_array.begin(), radix_array.end(), first);
}

void bytes_radix_sort(Iterator first, Iterator last)
{
    const int n = std::distance(first, last);
    vector<int> copy_input_arr(n);
    copy(first, last, copy_input_arr.begin());
    const int counts_bucket = 256;
    std::queue<int> buckets[counts_bucket];
    unsigned int bucket_index;
    int size_bucket;
    for(int i = 0 ; i < 3; ++i ){
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

void compact_bytes_radix_sort(Iterator first, Iterator last)
{
    const int counts_bucket = 256;
    const int n = std::distance(first, last);
    vector<int> sizes (counts_bucket);
    vector<int> shifts(counts_bucket);
    vector<int> radix_array(n);
    vector<int> copy_input_arr(n);
    vector<int> bucket_index(n);
    copy(first, last, copy_input_arr.begin());
    int current_position = 0;
    int size_bucket;
    char index;
    for(int i = 0 ; i < 3; ++i ){
        for(int j = 0; j < n; ++j){
            bucket_index[j] = get_val_byte(copy_input_arr[j], i);
            sizes[bucket_index[j]]++;
        }
        current_position = 0;
        for(int i = 0 ; i < counts_bucket; ++i){
            shifts[i] = current_position;
            current_position += sizes[i];
        }
        for(int i = 0 ; i < n; ++i){
            radix_array[shifts[bucket_index[i]]++] = copy_input_arr[i];
        }
        copy(radix_array.begin(), radix_array.end(), copy_input_arr.begin());
        fill(shifts.begin(), shifts.end(), 0);
        fill(sizes.begin(),  sizes.end(),  0);
        fill(bucket_index.begin(), bucket_index.end(), 0);
    }
    for(int j = 0; j < n; ++j){
        bucket_index[j] = get_val_signbyte(copy_input_arr[j], 3) + 128;
        sizes[bucket_index[j]]++;
    }
    current_position = 0;
    for(int i = 0 ; i < counts_bucket; ++i){
        shifts[i] = current_position;
        current_position += sizes[i];
    }
    for(int i = 0 ; i < n; ++i){
        radix_array[shifts[bucket_index[i]]++] = copy_input_arr[i];
    }
    copy(radix_array.begin(), radix_array.end(), first);
}
