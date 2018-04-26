// Copyright 2018 Gladyshev Alexey

#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

template <class ValType>
class TStack {
private:
    ValType* Arr;                           //Массив для хранения данных
    int size;                               //Размер стэка
    int sp;                                 //Указатель на вершину стэка
public:
    TStack(int _size = 1);                  //Конструктор-инициализатор
    TStack(const TStack& S);                //Конструктор копирования
    ~TStack(void);                          //Деструктор
    
    //Функции доступа
    int GetSize() { return size; }
    int GetSP() { return sp; }
    
    void Push(ValType var);                 //Положить значение в стэк
    ValType Pop(void);                      //Извлечь значение из стэка
    ValType Top(void);                      //Узнать значение, находящееся на вершине стэка
    int IsEmpty(void);                      //Контроль пустоты
    int IsFull(void);                       //Контроль переполнения
    
    int operator == (const TStack& S);      //Сравнение
    TStack& operator = (const TStack& S);   //Присваивание
};

//Нужно, чтобы можно было вынести реализацию методов шаблонного класса в отдельный файл
#include "src\stack.cpp"

#endif  // MODULES_STACK_INCLUDE_STACK_H_
