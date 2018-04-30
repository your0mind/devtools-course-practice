#include "include/avl-tree.h"
#include <iostream>
#include <vector>
using namespace std;

AVL::AVL()
{
	root = NULL;
}

AVLNode* AVL::getRoot()
{
	return root;
}

unsigned char AVL::height(AVLNode* p)//получение высоты вершины
{
	if (p)
		return p->height;
	else
		return 0; //получим высоту следующим способом : если вершины нет, ответ 0 иначе высота поддерева этой вершины
}

int AVL::bFactor(AVLNode* p)//разность высот между сыновьями
{
	return height(p->right) - height(p->left);
}

void AVL::fixheight(AVLNode* p) // обновим высоту, если сбалансированность нарушена
{
	unsigned int hl = height(p->left); // высота левого сына
	unsigned int hr = height(p->right); // высота правого сына
	if (hl > hr)
		p->height = hl + 1;
	else//hr>=hl
		p->height = hr + 1; // высота вершины - это высота сына с макс высотой плюс 1
}

AVLNode* AVL::rightRotate(AVLNode* p) // правый поворот вокруг p
{
	AVLNode* q = p->left;//запоминаем левого сына р 
	p->left = q->right;//присваем левому сыну р узлы, которые мжду p и q
	q->right = p;//присваиваем правому сыну q поддерево р
	if (root == p)
		root = q;
	fixheight(p);//починим дерево
	fixheight(q);
	return q;
}

AVLNode* AVL::leftRotate(AVLNode* q) // левый поворот вокруг q
{
	AVLNode* p = q->right;//запоминаем правого сына q
	q->right = p->left;//присваем правому сыну q узлы, которые мжду q и p
	p->left = q;//присваиваем левому сыну p поддерево q
	if (root == q)
		root = p;
	fixheight(q);//починим дерево
	fixheight(p);
	return p;
}

AVLNode* AVL::balance(AVLNode* p) // балансировка узла p
{
	fixheight(p);
	if (bFactor(p) == 2)//если левый сын сильно больше правого сделаем правый поворот
	{
		if (bFactor(p->right) < 0)
			p->right = rightRotate(p->right);
		return leftRotate(p);
	}
	if (bFactor(p) == -2)// если правый сын сибно больше левого сделаем левый поворот
	{
		if (bFactor(p->left) > 0)
			p->left = leftRotate(p->left);
		return rightRotate(p);
	}
	return p; // балансировка не нужна
}


AVLNode* AVL::insert(AVLNode* r, int w)
{
	if (root == NULL)//если дерево пустое, то просто создаем новый узел 
	{
		root = new AVLNode(w);
		return root;
	}
	if (r == NULL)
	{
		r = new AVLNode(w);
		return r;
	}
	else //r!=NULL
		if (w < r->key)//если значение вставляемого меньше центрально, идем влево
		{
			r->left = insert(r->left, w);
			r = balance(r);
		}
		else
			if (w > r->key)//если значение вставляемого больше центрально, идем вправо
			{
				r->right = insert(r->right, w);
				r = balance(r);
			}
			else r->key++;//если значение вставлемого == центральному, то увеличиваем количество повторений слова

			return r;
}

//void AVL::Show(AVLNode *node)//вывод в порядке возрастания
//{
//	if (node == NULL)
//	{
//		return;
//	}
//	Show(node->left);
//	cout << node->key << " ";
//	Show(node->right);
//}

//void AVL::toVector(AVLNode *node,vector<int> vec)//вывод в порядке возрастания
//{
//	if (node == NULL)
//	{
//		return;
//	}
//	toVector(node->left,vec);
//	vec.push_back(node->key);
//	//cout << node->key << " ";
//	toVector(node->right,vec);
//}


AVLNode* AVL::findMin(AVLNode* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left ? findMin(p->left) : p;
}

AVLNode* AVL::removeMin(AVLNode* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == 0)
		return p->right;
	p->left = removeMin(p->left);
	return balance(p);
}

AVLNode* AVL::remove(AVLNode* p, int k) // удаление ключа k из дерева p
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else //  k == p->key 
	{
		AVLNode* q = p->left;
		AVLNode* r = p->right;
		delete p;
		if (!r) return q;
		AVLNode* min = findMin(r);
		min->right = removeMin(r);
		min->left = q;
		return balance(min);
	}

	return balance(p);
}

AVLNode* AVL::search(AVLNode* r, int key) //like BST
{
	if (r == NULL) return NULL;

	if (key == r->key)
	{
		return r;
	}
	if (key < r->key)
	{
		return search(r->left, key);
	}
	return search(r->right, key);
}