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

template<typename T>
PriorityQueue<T>::PriorityQueue()
{
	elements.head = elements.tail = elements.current = nullptr;
	elements_count = 0;
}

template<typename T>
PriorityQueue<T>::PriorityQueue(T v, int priority)
{
	elements.head = elements.tail = elements.current = new Node(v, priority);
	elements_count = 1;
}

template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& pq)
{
	if (pq.elements.head == nullptr)
	{
		elements.head = elements.tail = elements.current = nullptr;
		elements_count = 0;
	}
	else {
		elements.head = new Node(pq.elements.head->value, pq.elements.head->priority);
		elements_count = pq.element_count;

		elements.current = elements.first;
		Node* tmp_current = pq.elements.head->next;

		while (tmp_current != nullptr)
		{
			elements.current->next = new Node(tmp_current->value, tmp_current->priority);
			tmp_current = tmp_current->next;
			elements.current = elements.current->next;
		}
		elements.current = elements.head;
	}
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	if (!empty()) {
		elements.current = elements.head;
		while (elements.current != nullptr)
		{
			Node* tmp_current = elements.current;
			elements.current = elements.current->next;
			if (tmp_current != nullptr) delete tmp_current;
		}
		elements.head = elements.tail = elements.current = nullptr;
	}
}

template<typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& pq)
{
	if (this != &pq) {
		if (pq.elements.head == nullptr)
		{
			elements.head = elements.tail = elements.current = nullptr;
			elements_count = 0;
		}
		else {
			elements.head = new Node(pq.elements.head->value, pq.elements.head->priority);
			elements_count = pq.element_count;

			elements.current = elements.first;
			Node* tmp_current = pq.elements.head->next;

			while (tmp_current != nullptr)
			{
				elements.current->next = new Node(tmp_current->value, tmp_current->priority);
				tmp_current = tmp_current->next;
				elements.current = elements.current->next;
			}
			elements.current = elements.head;
		}
	}
	return *this;
}

template<typename T>
T PriorityQueue<T>::extract_max()
{
	return T();
}

template<typename T>
void PriorityQueue<T>::delete_max()
{
}

template<typename T>
void PriorityQueue<T>::push(const T & v, int priority)
{
}

template<typename T>
void PriorityQueue<T>::swap(const PriorityQueue<T>& pq)
{
}

template<typename T>
bool PriorityQueue<T>::empty() const
{
	return false;
}

template<typename T>
std::size_t PriorityQueue<T>::size() const
{
	return std::size_t();
}

template<typename T>
int PriorityQueue<T>::get_max_priority() const
{
	return 0;
}

template<typename T>
bool PriorityQueue<T>::operator==(const PriorityQueue<T>& pq) const
{
	return false;
}

template<typename T>
bool PriorityQueue<T>::operator!=(const PriorityQueue<T>& pq) const
{
	return false;
}

#endif // MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_