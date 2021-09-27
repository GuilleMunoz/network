#ifndef TARJAN
#define TARJAN


#include <Graph.hpp>

class Tarjan
{
private:
    const int N; // Number of nodes of the graphs
    const Graph G;

    // Stores the discovery time of each node
    vector<int> disc_time;

    // The node with the earliest discovery time that can be reached 
    // from the current vertex
    vector<int> low;


    stack<int> stack;
    vector<int> is_in_stack; // is_in_stack[i] = true if i in stack

    int n_components;
    int time;

    void find_SCC(int u);
public:
    // vector that describes the SCCs. Two nodes u, v are in the same SCC if components[u] = components[v]
    vector<int> components;

    Tarjan(const Graph &G);
    void run();
};

#endif