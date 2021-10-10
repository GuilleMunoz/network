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
 * Finds the minimum spanning tree (MST) using Kruskal's algorithm.
 * 
 * Time complexity = O(E * log(V))
 * Space complexity = O(max(E, N))
 */
void Kruskal::run()
{
    vector<Edge> edges = this->G.get_edges(); // O(E)

    // O(E * log(E)) <= O(E * log(N*N)) = O(2 * E * log(N))
    sort(edges.begin(), edges.end());

    int n_edges = 0;

    // if we used more than n edges break
    for(auto edge = begin(edges); n_edges <= N && edge != end(edges); ++edge) // O(E)
    {

        int root_u = this->find((*edge).source); // log(V) ??
        int root_v = this->find((*edge).dest); // log(V) ??

        if (root_u != root_v)
        {
            n_edges++;
            this->merge((*edge).source, (*edge).dest, root_u, root_v);
        }
    }
}
