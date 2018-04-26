// Copyright 2018 Gladyshev Alexey

#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

template <class ValType>
class TStack {
 private:
    ValType* Arr;
    int size;
    int sp;
 public:
    explicit TStack(int _size = 1);
    TStack(const TStack& S);
    ~TStack(void);

    int GetSize() { return size; }
    int GetSP() { return sp; }

    void Push(ValType var);
    ValType Pop(void);
    ValType Top(void);

    int IsEmpty(void);
    int IsFull(void);

    int operator == (const TStack& S);
    TStack& operator = (const TStack& S);
};

#include "src/stack.cpp"

#endif  // MODULES_STACK_INCLUDE_STACK_H_
