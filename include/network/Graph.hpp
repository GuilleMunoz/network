#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <assert.h>
#include <limits>

#include <algorithm>

#include <vector>
#include <stack>
#include <tuple>

using namespace std;

const double MAX = numeric_limits<double>::max();


struct Edge
{
    int source;
    int dest;
    double weight;

    Edge(int source, int dest, double weight=MAX):
        source(source),
        dest(dest),
        weight(weight)
    {}

    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }

    bool operator>(const Edge& other) const
    {
        return weight > other.weight;
    }
};


class Graph
{
private:
    // Number of nodes
    int N;

    // Number of edges
    int E;

    bool is_directed; //true if the graph is directed

    // For each neighbor v of u, v in edges[u]
    // Space = O(N + E), where E is the number of edges
    vector<vector<int> > edges;

    // Similar to edges but stores the weights (must be in same order)
    // Space = O(n + E), where E is the number of edges
    vector<vector<double> > weights;

public:
    Graph(int n, bool is_directed=false): 
        N(n),
        is_directed(is_directed),
        E(0),
        edges(n, vector<int>()),
        weights(n, vector<double>())
    {};

    int get_n_nodes() {return N;};
    int get_n_nodes() const {return N;};

    const vector<int> &get_neighs(const int u) const {return edges[u];};
    const vector<double> &get_weights(const int u) const {return weights[u];};

    vector<Edge> get_edges() const;

    void add_edge(int u, int v, double w=1.0);
    void add_node();

    bool is_connected();
    bool is_acyclic();

    vector<int> minimum_spanning_tree();

    vector<int> strongly_connected_components();
};


template <class comparable>
inline comparable _max_(comparable u, comparable v);

#endif