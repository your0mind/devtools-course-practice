// Copyright 2018 Pozdeeva Varvara

#include "include/binary_search.h"
#include <algorithm>

using namespace std;

BinarySearch::BinarySearch(int mas[], int size)
{
	if (mas != nullptr)
	{
		masiv = new int[size];
		for (int i = 0; i < size; i++)
			masiv[i] = mas[i];
		center = size / 2;
		this->size = size;
	}
}

BinarySearch::~BinarySearch()
{
	if(masiv!= nullptr)
		delete[] masiv;
}

int BinarySearch::Search(int num)
{
	sort (masiv, masiv + size);

	int resalt = -1;
	int right = size;
	int left = 0;

	while ((left <= right))
	{
		center = (left + right) / 2;
		if (masiv[center] == num)
		{
			resalt = center;
			break;
		}
		if (masiv[center] > num)
			right = center - 1;
		else
			left = center + 1;
	}
	return resalt;
}