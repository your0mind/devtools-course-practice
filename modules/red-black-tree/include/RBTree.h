// Copyright 2018 Chernenko Valery
#ifndef MODULES_RED_BLACK_TREE_INCLUDE_RBTREE_H_
#define MODULES_RED_BLACK_TREE_INCLUDE_RBTREE_H_

typedef int T;
typedef enum { BLACK, RED } nColor;    //Возможные цвета узлов дерева
struct Node {
    Node* left;           //Указатель на "левого" потомка
    Node* right;          //Указатель на "правого" потомка
    Node* parent;         //Указатель на "предка"
    nColor color;      //Цвет узла
    T data;               //Хранящиеся в узле данные

    Node(Node* _l, Node* _r, Node* _p, nColor _c, T _d) {
        left = _l; right = _r, parent = _p, color = _c, data = _d;
    }
};

class RBTree {
 private:
    void deleteTree(Node* x);  /*Удаление дерева*/
 protected:
    Node* root;  /*Указатель на корень дерева*/
    void rotateLeft(Node* x);   /*"Левый поворот"*/
    void rotateRight(Node* x);  /*"Правый поворот"*/
    void insertFixup(Node* x);  /*Вставка узла с балансировкой*/
    void deleteFixup(Node* x);  /*Удаление узла с балансировкой*/
 public:
    static Node* NIL;
    RBTree();
    explicit RBTree(T data);
    RBTree(T datas[], int count);
    ~RBTree();
    Node* insertNode(T data);  /*Вставка узла по значению*/
    Node* findNode(T data);  /*Поиск узла по значению*/
    void deleteNode(T data);  /*Удаление узла по значению*/
};

#endif  // MODULES_RED_BLACK_TREE_INCLUDE_RBTREE_H_
