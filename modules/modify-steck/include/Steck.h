#pragma once

template <typename T>
class Steck;

template <typename T>
class Node {
friend Steck<T>; // ������ Steck ������������� � Node

private:
	T val; // �������� � ������ �����
	Node<T> *next; // ��������� �� ��������� ������� �����

public:
	Node(T _val = 0, Node<T> *_next = 0);
};

// �-�
template <typename T>
Node<T>::Node(T _val, Node<T> *_next) {
	val = _val;
	next = _next;
}

template <typename T>
class Steck {
private:
	Node<T> * currentTop; // ��������� �� ������� �����
	int sizeOfStack; // ������ �����
public:
	Steck();
	~Steck();

	// ������
	bool IsEmpty(); // ������ �� ����
	int Size();
	void Push(T val); // ������� ������� � ����
	void Pop(); // �������� �������� ������ 1 ����� � ������� ��
	T LookTop(); // ���������� �� 1 ������� �����
};

template <typename T>
Steck<T>::Steck() {
	sizeOfStack = 0;
	currentTop = 0;
}

template <typename T>
Steck<T>::~Steck() {
	while (Size())
		Pop();
}

template <typename T>
bool Steck<T>::IsEmpty() {
	if (sizeOfStack == 0)
		return 1;
	else
		return 0;
}

template <typename T>
int Steck<T>::Size() {
	return sizeOfStack;
}

template <typename T>
void Steck<T>::Push(T val) {
	Node<T> *new_node = new Node<T>(val, currentTop);
	sizeOfStack++;
	currentTop = new_node;
}

template <typename T>
void Steck<T>::Pop() {
	Node<T> *node = currentTop;
	currentTop = currentTop->next;
	delete node;
}

template <typename T>
T Steck<T>::LookTop() {
	return currentTop->val;
}

