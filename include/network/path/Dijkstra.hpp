#ifndef DIJKSTRA
#define DIJKSTRA

#include <Graph.hpp>
#include <queue>


#define tup tuple<double, int>

class Dijkstra
{
private:
    const Graph G;
    const int N;
    vector<double> dist;
public:
    vector<int> prev;

    Dijkstra(const Graph &G);

    void run(const int source);

    inline double distance_to(int u);
    inline double distance_to(int u) const;
};

#endif