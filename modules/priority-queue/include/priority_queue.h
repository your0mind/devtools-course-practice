// Copyright 2018 Bogatova Margarita

#ifndef  MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
#define  MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_

#include <stdexcept>
#include <iostream>

template <typename T>
class PriorityQueue {
public:
	PriorityQueue();
	PriorityQueue(T v, int priority = 0);
	PriorityQueue(const PriorityQueue<T> & pq);
	~PriorityQueue();

	PriorityQueue<T>& operator=(const PriorityQueue<T> & pq);

	T extract_max();
	void delete_max();
	void push(const T& v, int priority = 0);
	void swap(const PriorityQueue<T>& pq);

	bool empty()  const;
	std::size_t size() const;
	int get_max_priority() const;

	bool operator == (const PriorityQueue<T>& pq) const;
	bool operator != (const PriorityQueue<T>& pq) const;

private:
	struct Node {
		T value;
		int priority;
		Node* next;

		Node(T val, int p = 0, Node* n = nullptr) {
			value = val;
			priority = p;
			next = n;
		}
		~Node() { delete next; }
	};
	struct List
	{
		Node* head;
		Node* current;
		Node* tail;
	};
	struct List elements;
	std::size_t element_count
};

#endif // MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_