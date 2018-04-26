// Copyright 2018 Gladyshev Alexey

#ifndef MODULES_STACK_INCLUDE_STACK_CPP_
#define MODULES_STACK_INCLUDE_STACK_CPP_

#include "include\stack.h"

#include <string>

//Конструктор-инициализатор
template <class ValType>
TStack<ValType>::TStack(int _size)
{
    sp = 0;
    if (_size > 0)    size = _size;
    else              size = 1;

    Arr = new ValType[size];
    
    if (Arr == NULL)
        throw std::string("Out of memory");
}

//Деструктор
template <class ValType>
TStack<ValType>::~TStack(void)
{
    delete[]Arr;
    Arr = NULL;
}

//Конструктор копирования
template <class ValType>
TStack<ValType>::TStack(const TStack<ValType> &S)
{
    size = S.size;
    sp = S.sp;
    
    Arr = new ValType[size];
    if (Arr == NULL)
        throw std::string("Out of memory");
    else
        for (int i = 0; i < S.sp; i++) //Копирование элементов стэка
            Arr[i] = S.Arr[i];
}

//Положить значение в стэк
template <class ValType>
void TStack<ValType>::Push(ValType var)
{
    Arr[sp++] = var;
}

//Извлечь значение из стэка
template <class ValType>
ValType TStack<ValType>::Pop(void)
{
    return Arr[--sp];
}

//Узнать значение, находящееся на вершине стэка (без извлечения)
template <class ValType>
ValType TStack<ValType>::Top(void)
{
    return Arr[sp - 1];
}

//Контроль пустоты
template <class ValType>
int TStack<ValType>::IsEmpty(void)
{
    return (sp == 0);
}

//Контроль переполнения
template <class ValType>
int TStack<ValType>::IsFull(void)
{
    return (sp == size);
}

//Сравнение
template <class ValType>
int TStack<ValType>::operator == (const TStack& S)
{
    int res = 0, counter = 0;

    if ((size == S.size) && (sp == S.sp))
    {
        for (counter; (counter < sp) && (Arr[counter] == S.Arr[counter]); counter++);
        
        if (counter == sp)
            res = 1;
    }
    
    return res;
}

//Присваивание
template <class ValType>
TStack<ValType>& TStack<ValType>::operator = (const TStack &S)
{
    if (this != &S)
    {
        if (size != S.size)
        {
            delete[]Arr;
            Arr = new ValType[S.size];
        }
        size = S.size;
        sp = S.sp;
        
        if (Arr == NULL)
            std::string("Out of memory");
        else
        {
            //Копирование элементов стэка
            for (int i = 0; i < S.sp; i++)
                Arr[i] = S.Arr[i];
        }
    }
    
    return *this;
}

#endif  // MODULES_STACK_INCLUDE_STACK_CPP_
