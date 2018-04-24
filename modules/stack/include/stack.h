// Copyright 2018 Gladyshev Alexey

#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

template <class ValType>
class TStack {
private:
    ValType* Arr;							//Массив для хранения данных
    int size;								//Размер стэка
    int sp;									//Указатель на вершину стэка
public:
    TStack(int _size = 1);					//Конструктор-инициализатор
    TStack(const TStack& S);				//Конструктор копирования
    ~TStack(void);							//Деструктор
    
    int GetSize() { return size; }
    int GetSP() { return sp; }
    
    int IsEmpty(void);						//Контроль пустоты
    int IsFull(void);						//Контроль переполнения
    void Push(ValType var);					//Положить значение в стэк
    ValType Pop(void);						//Извлечь значение из стэка
    
    TStack& operator = (const TStack& S);	//Присваивание
    int operator == (const TStack& S);		//Сравнение
};

/*template <class ValType>
TStack<ValType>::TStack(int _size)
{
	sp = 0;
	if (_size > 0)    size = _size;
	else              size = 1;

	Arr = new ValType[size];

	if (Arr == NULL)    throw(Arr);
}

//Деструктор
template <class ValType>
TStack<ValType>::~TStack(void)
{
	delete[]Arr;
	Arr = NULL;
}*/
#include "src\stack.cpp"
#endif
