// Copyright 2018 Gorelova Ksenia

#include "include/search_tree.h"

SearchTree::SearchTree(Node * pRoot)
{
    this->pRoot = pRoot;
}

Node * SearchTree::AddNode(const int & num, Node * nd)
{
    if (nd == nullptr)
    {
        nd = new Node;
        nd->key = num;
        nd->count = 1;
        nd->left = nd->right = nullptr;
        return 0;
    }
    else if (num > nd->key)
        return nd->right = AddNode(num, nd->right);
    else if (num < nd->key)
        return nd->left = AddNode(num, nd->left);
    else
        nd->count++;
}

int SearchTree::SearchNode(const int & num, Node * nd)
{
    if (!nd)
        return 0;
    else if (nd->key == num)
        return nd->count;
    else if (nd->key > num)
        return SearchNode(num, nd->left);
    else
        return SearchNode(num, nd->right);
}

void SearchTree::Add(const int & num)
{
    pRoot = AddNode(num, pRoot);
}

int SearchTree::Search(const int & num)
{
    return SearchNode(num, pRoot);
}

void SearchTree::DelTree(Node * nd)
{
    if (nd)
    {
        DelTree(nd->left);
        DelTree(nd->right);
        delete nd;
    }
}

Node * SearchTree::FindMin(Node * nd)
{
    if (nd == nullptr)
        return 0;
    else if (nd->left == nullptr)
        return nd;
    else
        return FindMin(nd->left);
}

Node * SearchTree::FindMax(Node * nd)
{
    if (nd == nullptr)
        return 0;
    else if (nd->right == nullptr)
        return nd;
    else
        return FindMax(nd->right);
}

Node * SearchTree::Find(Node * nd, const int & num)
{
    if (nd == nullptr)
        return nullptr;
    else if (num < nd->key)
        return Find(nd->left, num);
    else if (num > nd->key)
        return Find(nd->right, num);
    else
        return nd;
}

Node * SearchTree::DelNode(Node * nd, Node * cur)
{
    if (!cur)
        return cur;
    else if (nd == cur)
        return DelNode(nd);
    else
    {
        cur->left = DelNode(nd, cur->left);
        cur->right = DelNode(nd, cur->right);
    }
    return cur;
}

Node * SearchTree::DelNode(Node * nd)
{
    if (!nd)
        throw 0;
    if (!(nd->left || nd->right))
    {
        delete nd;
        return nd = nullptr;
    }
    else if (!nd->left)
    {
        Node * tmp = nd;
        nd = nd->right;
        delete tmp;
        return nd;
    }
    else if (!nd->right)
    {
        Node * tmp = nd;
        nd = nd->left;
        delete tmp;
        return nd;
    }
    else
    {
        Node * tmp = nd;
        Node * close = nd->left;
        while (close->right)
        {
            close = close->right;
        }
        nd->key = close->key;
        nd->count = close->count;
        nd = DelNode(close, nd);
        return nd;
     }
}

bool SearchTree::IsEmpty() const
{
    if (pRoot != 0)
        return 0;
    else 
        return 1;
}