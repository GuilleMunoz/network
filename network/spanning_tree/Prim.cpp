#include <Prim.hpp>


Prim::Prim(const Graph &G):
    G(G),
    N(G.get_n_nodes()),
    prev(G.get_n_nodes(), -1)
{
    for(int i = 0; i < N; ++i) this->weights.push_back(make_tuple(MAX, i));
}


/**
 * Update the weights vector and the set.
 * 
 * @param const int u the node to add to the MST
 */
void Prim::update(const int u)
{

    this->prev[u] = get<1>(this->weights[u]);
    
    auto w = begin(this->G.get_weights(u));

    // Iterate through the neighboors of u and try to update the weights of each neighboor.
    for (int v: this->G.get_neighs(u))
    {
        // if prev[v] < 0 v is not in the tree as prev is initialized to -1
        if (prev[v] < 0 && *w < get<0>(this->weights[v]))
        {
            get<0>(this->weights[v]) = *w;
            get<1>(this->weights[v]) = u;
        }
        ++w;
    }
}


/**
 * Finds the minimum spanning tree (MST).
 * 
 * We build the tree node by node and at each step we have to update weights vector
 * 
 * Time Complexity = O(N * N)
 * Space Complexity = O(N)
 */
void Prim::run(int u)
{

    for (int n_edges = 0; n_edges < this->N; ++n_edges)
    {
        double min = MAX; 
        this->update(u);

        for (int v = 0; v < this->N; ++v)
        {
            // if prev[v] >= 0 v is in the tree
            if (prev[v] >= 0) continue;

            if (min > get<0>(this->weights[v]))
            {
                min = get<0>(this->weights[v]); 
                u = v;
            }
        }
    }
}