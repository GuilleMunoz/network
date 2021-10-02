#ifndef BORUVKA
#define BORUVKA

#include "Graph.hpp"

class Boruvka
{
private:
    const Graph G;
    const int N;

public:
    vector<int> prev;

    Boruvka(const Graph &G):
        G(G),
        N(G.get_n_nodes()),
        prev(G.get_n_nodes())
    {}

    void run();
};

#endif