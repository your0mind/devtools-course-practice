// Copyright 2018 Pozdeeva Varvara

#ifndef MODULES_BINARY_SEARCH
#define MODULES_BINARY_SEARCH

#include <iostream>

class BinarySearch {
private:
	int* masiv;
	int size;
	int center;
public:
	BinarySearch(int mas[], int );
	~BinarySearch();
	int Search(int);
};

#endif