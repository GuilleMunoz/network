#include <Kruskal.hpp>

Kruskal::Kruskal(const Graph &G):
    G(G),
    N(G.get_n_nodes()),
    rank(G.get_n_nodes(), 0),
    prev(G.get_n_nodes()),
    root(G.get_n_nodes())
{
    int i = 0;
    for (int u = 0; u < this->N; ++u) this->prev[u] = this->root[u] = u;
    
};


/**
 * Auxiliary function used in Kruscal algorithm to find the root of the vertex u.
 * 
 * @param const int u
 * @return Root "node" in the current MST 
 */
int Kruskal::find(const int u)
{
    if (this->root[u] == u) return u;
    return this->find(root[u]);
}


/**
 * Auxiliary function used in Kruscal algorithm, performs the union between two trees (by rank).
 */
inline void Kruskal::merge(int u, int v, int root_u, int root_v)
{

    if (this->rank[root_u] < this->rank[root_v])
    {
        swap(u, v);
        swap(root_u, root_v);
    }
    this->prev[v] = u;
    this->root[root_v] = root_u;

    if (this->rank[root_u] == this->rank[root_v])
        this->rank[root_u]++;

}


/** 
 * Compares (basing in the weight) two edges represented as a tuple (u, v, w) where u is the source, v the destination 
 * and w the weight.
 * 
 * @return true if e1 is heavier than e2.
 */
inline bool cmp_edge(const tuple<int, int, double>& e1, const tuple<int, int, double>& e2)
{
    return (get<2>(e1) < get<2>(e2));
}


/**
 * Finds the minimum spanning tree (MST) using Kruskal's algorithm.
 * 
 * Time complexity = O(E * log(V))
 * Space complexity = O(max(E, N))
 * 
 * @return A vector where the ith element is the node previous to i in the tree
 */
void Kruskal::run()
{
    vector<tuple<int, int, double>> edges = this->G.get_edges(); // O(E)

    // O(E * log(E)) <= O(E * log(N*N)) = O(2 * E * log(N))
    sort(edges.begin(), edges.end(), cmp_edge);

    int n_edges = 0;
    int u, v;

    // if we used more than n edges break
    for(auto it = begin(edges); n_edges <= N && it != end(edges); ++it) // O(E)
    {
        tie(u, v, ignore) = *it;

        int root_u = this->find(u); // log(V) ??
        int root_v = this->find(v); // log(V) ??

        if (root_u != root_v)
        {
            n_edges++;
            this->merge(u, v, root_u, root_v);
        }
    }
}


ostream & operator<<(ostream &out, const Kruskal &kruskal)
{
    for (auto u: kruskal.prev)
        out << u << " ";

    return out;
}