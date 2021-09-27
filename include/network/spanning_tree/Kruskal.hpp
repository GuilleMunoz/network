#ifndef KRUSKAL
#define KRUSKAL

#include <Graph.hpp>

class Kruskal
{
private:
    vector<int> rank;
    vector<int> root;
    const Graph G;
    const int N;
public:
    // vector where the ith element is the parent of i in the spanning tree
    // for the root node, prev[root] = root
    vector<int> prev;

    Kruskal(const Graph &G);

    int find(const int u);
    inline void merge(int u, int v, int root_u, int root_v);

    void run();
};

ostream & operator<<(ostream &out, const Kruskal &kruskal);

#endif