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

//#include "src/stack.cpp"

template <class ValType>
TStack<ValType>::TStack(int _size) {
    sp = 0;
    if (_size > 0)    size = _size;
    else              size = 1;

    Arr = new ValType[size];

    if (Arr == NULL)
        throw std::string("Out of memory");
}

template <class ValType>
TStack<ValType>::~TStack(void) {
    delete[]Arr;
    Arr = NULL;
}

template <class ValType>
TStack<ValType>::TStack(const TStack<ValType> &S) {
    size = S.size;
    sp = S.sp;

    Arr = new ValType[size];
    if (Arr == NULL) {
        throw std::string("Out of memory");
    }
    else {
        for (int i = 0; i < S.sp; i++)
            Arr[i] = S.Arr[i];
    }
}

template <class ValType>
void TStack<ValType>::Push(ValType var) {
    Arr[sp++] = var;
}

template <class ValType>
ValType TStack<ValType>::Pop(void) {
    return Arr[--sp];
}

template <class ValType>
ValType TStack<ValType>::Top(void) {
    return Arr[sp - 1];
}

template <class ValType>
int TStack<ValType>::IsEmpty(void) {
    return (sp == 0);
}

template <class ValType>
int TStack<ValType>::IsFull(void) {
    return (sp == size);
}

template <class ValType>
int TStack<ValType>::operator == (const TStack& S) {
    int res = 0, counter = 0;

    if ((size == S.size) && (sp == S.sp)) {
        for (; (counter < sp) && (Arr[counter] == S.Arr[counter]); counter++) {}

        if (counter == sp)
            res = 1;
    }

    return res;
}

template <class ValType>
TStack<ValType>& TStack<ValType>::operator = (const TStack &S) {
    if (this != &S) {
        if (size != S.size) {
            delete[]Arr;
            Arr = new ValType[S.size];
        }
        size = S.size;
        sp = S.sp;

        if (Arr == NULL) {
            std::string("Out of memory");
        }
        else {
            for (int i = 0; i < S.sp; i++)
                Arr[i] = S.Arr[i];
        }
    }

    return *this;
}

#endif  // MODULES_STACK_INCLUDE_STACK_H_
