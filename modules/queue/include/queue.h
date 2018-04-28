// Copyright 2018 Roman Kudalin

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_H_

#include <cstddef>
#include <algorithm>
#include <utility>
#include <stdexcept>

template <typename Ty>
class Queue
{
public:
    Queue();
    explicit Queue(std::size_t size);
    Queue(const Queue<Ty>& rhs);
    Queue(Queue<Ty>&& rhs);
    ~Queue();

    Ty& front();
    const Ty& front() const;
    Ty& back();
    const Ty& back() const;
    bool empty() const;
    std::size_t size() const;
    void push(const Ty& data);
    void push(Ty&& data);
    void pop();
    void swap(Queue<Ty>& second);

    Queue<Ty>& operator=(Queue<Ty> rhs);
    bool operator==(const Queue<Ty>& rhs) const;
    bool operator!=(const Queue<Ty>& rhs) const;

private:
    Ty* mem;
    std::size_t dataCount;
    std::size_t capacity;
    int head;
    int tail;
    int nextIndex(int oldIndex);
    void resize();
};


//----------IMPLEMENTATION----------

template <typename Ty>
Queue<Ty>::Queue() : mem(nullptr), dataCount(0), capacity(0),
head(0), tail(-1) {}

template <typename Ty>
Queue<Ty>::Queue(std::size_t size) : dataCount(0), capacity(size),
head(0), tail(-1)
{
    capacity ? mem = new Ty[capacity]() : mem = nullptr;
}

template <typename Ty>
Queue<Ty>::Queue(const Queue<Ty>& rhs) : dataCount(rhs.dataCount),
capacity(rhs.capacity), head(rhs.head), tail(rhs.tail)
{
    capacity ? mem = new Ty[capacity]() : mem = nullptr;
    std::copy(rhs.mem, rhs.mem + rhs.dataCount, mem);
}

template <typename Ty>
Queue<Ty>::Queue(Queue<Ty>&& rhs) : Queue() { swap(rhs); }

template <typename Ty>
Queue<Ty>::~Queue()
{
    if (mem != nullptr)
        delete[] mem;
}

#endif // MODULES_QUEUE_INCLUDE_QUEUE_H_
