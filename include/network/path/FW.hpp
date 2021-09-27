#ifndef FLOYD_WARSHALL
#define FLOYD_WARSHALL

#include <Graph.hpp>

class Floyd_Warshall
{
private:
    vector<double> dist;
    vector<double> next;
    const Graph G;
    int N;
public:
    Floyd_Warshall(const Graph &G);

    void run();

    vector<int> path(const int u, const int v);
};

#endif