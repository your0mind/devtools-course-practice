#include "include/Graph.h"
#include <set>


Graph::Graph() 
{
    n = 0;
    graph_matrix = nullptr;
}


Graph::Graph(int count_vertex, double** matrix)
{
    if (count_vertex < 0)
        throw "Negative_count";
    n = count_vertex;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] < 0)
                throw "Negative weight";
    }
    graph_matrix = new double*[n];
    for (int i = 0; i < n; ++i) {
        graph_matrix[i] = new double[n];
        for (int j = 0; j < n; ++j)
            graph_matrix[i][j] = matrix[i][j];
    }
}

Graph::~Graph()
{
    for (int i = 0; i < n; ++i)
        delete graph_matrix[i];
    delete[] graph_matrix;
}

int Graph::GetCount()
{
    return n;
}

double Graph::GetWeight(int first, int last)
{
    if (first < 1 || first>n || last<1 || last>n)
        throw "Несуществующая вершина";
    return graph_matrix[first-1][last-1];
}

void Graph::AddVertex()
{
    double** tmp = new double*[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        tmp[i] = new double[n + 1];
        for (int j = 0; j < n + 1; ++j)
            tmp[i][j] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            tmp[i][j] = graph_matrix[i][j];
        delete graph_matrix[i];
    }
    delete[] graph_matrix;
    n++;
    graph_matrix = tmp;
}

void Graph::AddEdge(int first, int last, double weight)
{
    if (first < 1 || first>n || last<1 || last>n)
        throw "Несуществующая вершина";
    graph_matrix[first - 1][last - 1] = weight;
}

void Graph::DeleteEdge(int first, int last)
{
    if (first < 1 || first>n || last<1 || last>n)
        throw "Несуществующая вершина";
    graph_matrix[first - 1][last - 1] = 0;
}

void Graph::DeleteVertex(int vertex)
{
    if (vertex < 1 || vertex>n)
        throw "Несуществующая вершина";
    double** tmp = new double*[n - 1];
    for (int i = 0; i < n - 1; ++i)
        tmp[i] = new double[n - 1];
    for (int i = 0; i < vertex - 1; ++i) {
        for (int j = 0; j < vertex - 1; ++j)
            tmp[i][j] = graph_matrix[i][j];
        for (int j = vertex; j < n; ++j)
            tmp[i][j-1] = graph_matrix[i][j];
    }
    for (int i = vertex; i < n; ++i) {
        for (int j = 0; j < vertex - 1; ++j)
            tmp[i - 1][j] = graph_matrix[i][j];
        for (int j = vertex; j < n; ++j)
            tmp[i - 1][j - 1] = graph_matrix[i][j];
        delete graph_matrix[i];
    }
    n--;
    delete[] graph_matrix;
    graph_matrix = tmp;
}

double Graph::FindDistance(int start, int finish)
{
    if (start < 1 || start>n || finish<1 || finish>n)
        throw "Несуществующая вершина";
    static double* distance = new double[n];
    for (int i = 0; i < n; ++i)
        distance[i] = -1;
    auto set_function = [](int a, int b) {
        return distance[a] < distance[b] || distance[a] == distance[b] && a < b;
    };
    std::set<int, decltype(set_function)> distance_queue(set_function);
    distance[start-1] = 0;
    distance_queue.insert(start-1);
    while (!distance_queue.empty()) {
        int next_vertex = *distance_queue.begin();
        distance_queue.erase(distance_queue.begin());
        for (int i = 0; i < n; ++i) {
            if (graph_matrix[next_vertex][i])
                continue;
            if (distance[i] > distance[next_vertex] + graph_matrix[next_vertex][i] || distance[i]==-1) {
                distance_queue.erase(i);
                distance[i] = distance[next_vertex] + graph_matrix[next_vertex][i];
                distance_queue.insert(i);
            }
        }
    }
	double ans = distance[finish-1];
	delete[] distance;
    return distance[finish-1];
}
