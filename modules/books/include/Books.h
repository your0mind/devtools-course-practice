// Copyright 2018 Bolshakov Konstantin

#ifndef BOOKS_CLASS_INCLUDE_H_
#define BOOKS_CLASS_INCLUDE_H_

#include <iostream>

class Books
{
 public:
  Books(int n, int* arr);
  ~Books();
  double calculatePayForCurrentCollection(int*arr, int collection);
  int curentCollectionSize(int*arr);
  double calculateAllPayment(int*arr);
  double withoutSales(int*arr);
 private:
  int* arr;
  int n;
  double pay;
};

#endif // !BOOKS_CLASS_INCLUDE_H_
