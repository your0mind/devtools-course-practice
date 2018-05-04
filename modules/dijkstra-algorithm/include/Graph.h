#pragma once
class Graph
{
protected:
    int n;
    double** graph_matrix;
public:
    Graph(); //котруктор по умолчанию
    Graph(int count_vertex, double** matrix); //конструктор с параметрами
    ~Graph(); //деструктор
    int GetCount(); //Получить число вершин
    double GetWeight(int first, int last); //Получить вес ребра
    void AddVertex(); //Добавить вершину
    void AddEdge(int first, int last, double weight); //добавить ребро
    void DeleteEdge(int first, int last); //Удалить ребро
    void DeleteVertex(int vertex); //Удалить вершину
    double FindDistance(int start, int finish); //Поиск расстояния от start до finish
};

