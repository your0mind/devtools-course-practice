// Copyright 2018 Bogatova Margarita

#ifndef  MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
#define  MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_

#include <stdexcept>
#include <iostream>

//    - The priority queue is implemented using a single linked list
//    - Items in the list are in descending order of priority: 0 - minimum priority

template <typename T>
class PriorityQueue {
public:
	PriorityQueue();
	PriorityQueue(T v, int priority = 0);
	PriorityQueue(const PriorityQueue<T> & pq);
	~PriorityQueue();

	PriorityQueue<T>& operator=(const PriorityQueue<T> & pq);

	T extract_max() const;
	void delete_max();
	void push(const T& v, int priority = 0);
	void swap(const PriorityQueue<T>& pq);

	bool empty()  const;
	std::size_t size() const;
	int get_max_priority() const;
	int get_min_priority() const;

	bool operator == (const PriorityQueue<T>& pq) const;
	bool operator != (const PriorityQueue<T>& pq) const;

private:
	void delete_queue();

	struct Node {
		T value;
		int priority;
		Node* next;

		Node(T val, int p = 0, Node* n = nullptr) {
			value = val;
			priority = p;
			next = n;
		}
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
PriorityQueue<T>::PriorityQueue() {
	elements.head = elements.tail = elements.current = nullptr;
	elements_count = 0;
}

template<typename T>
PriorityQueue<T>::PriorityQueue(T v, int priority) {
	elements.head = elements.tail = elements.current = new Node(v, priority);
	elements_count = 1;
}

template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& pq) {
	if (pq.empty()) {
		elements.head = elements.tail = elements.current = nullptr;
		elements_count = 0;
	}
	else {
		elements.head = new Node(pq.elements.head->value, pq.elements.head->priority);
		elements_count = pq.element_count;

		elements.current = elements.head;
		Node* other_current = pq.elements.head->next;

		while (other_current != nullptr) {
			elements.current->next = new Node(other_current->value, other_current->priority);
			other_current = other_current->next;
			elements.current = elements.current->next;
		}
		elements.tail = elements.current;
		elements.current = elements.head;
	}
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
	delete_queue();
}

template<typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& pq) {
	if (this != &pq) {
		delete_queue();
		if (pq.empty()) {
			elements.head = elements.tail = elements.current = nullptr;
			elements_count = 0;
		}
		else {
			elements.head = new Node(pq.elements.head->value, pq.elements.head->priority);
			elements_count = pq.element_count;

			elements.current = elements.head;
			Node* other_current = pq.elements.head->next;

			while (other_current != nullptr) {
				elements.current->next = new Node(other_current->value, other_current->priority);
				other_current = other_current->next;
				elements.current = elements.current->next;
			}
			elements.tail = elements.current;
			elements.current = elements.head;
		}
	}
	return *this;
}

template<typename T>
T PriorityQueue<T>::extract_max() const {
	return elements.head->value;
}

template<typename T>
void PriorityQueue<T>::delete_max() {
	if (!empty()) {
		Node* tmp_head = elements.head;
		elements.head = elements.head->next;
		delete tmp_next;
		element_count--;
	}
	else
		throw std::runtime_error("Queue is empty");
}

template<typename T>
void PriorityQueue<T>::push(const T & v, int priority){
	if (empty()) 
		elements.head = elements.tail = elements.current = new (v, priority);
	else {
		if (priority <= elements.tail->priority) {

			elements.tail->next = new Node(v, priority);
			elements.tail = elements.tail->next;
		}
		if (priority > elements.head->priority) {
			Node* tmp_head = elements.head;
			elements.head = new Node(v, priority, tmp_head);
		}
		else {
			elements.current = elements.head;

			while (elements.current != nullptr) {
				if (priority > elements.current->next->priority)
					break;
				elements.current = elements.current->next;
			}

			Node* tmp_next = elements.current->next;
			elements.current->next = new (v, priority, tmp_next);
		}
	}
	element_count++;
}

template<typename T>
void PriorityQueue<T>::swap(PriorityQueue<T>& pq) {
	using std::swap;
	swap(element_count, pq.element_count);
	swap(elements.head, pq.elements.head);
	swap(elements.tail, pq.elements.tail);
	swap(elements.current, pq.elements.current);
}

template<typename T>
bool PriorityQueue<T>::empty() const {
	return elements.head == nullptr;
}

template<typename T>
std::size_t PriorityQueue<T>::size() const {
	return element_count;
}

template<typename T>
int PriorityQueue<T>::get_max_priority() const {
	return elements.head->priority;
}

template<typename T>
int PriorityQueue<T>::get_min_priority() const {
	return elements.tail->priority;
}

template<typename T>
bool PriorityQueue<T>::operator==(const PriorityQueue<T>& pq) const {
	if (element_count != pq.element_count) 
		return false;

	Node* current = elements.head;
	Node* other_current = pq.elements.head;

	while (current != nullptr) {
		if (current->priority != other_current->priority ||
			current->value != other_current->value) return false;

		current = current->next;
		other_current = other_current->next;
	}

	return true;
}

template<typename T>
bool PriorityQueue<T>::operator!=(const PriorityQueue<T>& pq) const {
	if (element_count != pq.element_count) return true;

	Node* current = elements.head;
	Node* other_current = pq.elements.head;

	while (current != nullptr) {
		if (current->priority != other_current->priority ||
			current->value != other_current->value) return true;

		current = current->next;
		other_current = other_current->next;
	}

	return false;
}

template<typename T>
void PriorityQueue<T>::delete_queue() {
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

#endif // MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_