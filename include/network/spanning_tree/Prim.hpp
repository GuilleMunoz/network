#ifndef PRIM
#define PRIM


#include "Graph.hpp"

class Prim
{
private:
    const Graph G;
    const int N;

    // A vector of tuples where for the ith element the first element of the tuple is the minimum 
    // distance to the tree and the second the previous element. 
    vector<tuple<double, int> > weights;

    void update(const int u);
public:
    // vector where the ith element is the parent of i in the spanning tree
    // for the root node, prev[root] = root
    vector<int> prev;
    Prim(const Graph &G);
    void run(int u=0);

};

#endif