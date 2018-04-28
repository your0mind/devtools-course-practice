#include <iterator>
#include <algorithm>
#include <chrono>
#include <queue>
#include <array>


using Time = std::chrono::high_resolution_clock;
using ms   = std::chrono::milliseconds;
using fms  = std::chrono::duration<float, std::milli>;

inline char get_val_signbyte(int number, int position)
{
    return *((char*)&number + position);
}
inline unsigned char get_val_byte(int number, int position)
{
    return *((unsigned char*)&number + position);
}

class radix_compare
{
    const int bit;
public:
    radix_compare(int offset) : bit(offset) {}
    bool operator()(int value) const
    {
        if (bit == 31)
            return value < 0;
        else
            return !(value & (1 << bit));
    }
};
