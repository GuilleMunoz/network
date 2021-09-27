#include <Tarjan.hpp>


Tarjan::Tarjan(const Graph &G):
    G(G),
    N(G.get_n_nodes()),

    disc_time(G.get_n_nodes(), -1),
    low(G.get_n_nodes(), -1),

    stack(),
    is_in_stack(G.get_n_nodes(), false),

    components(G.get_n_nodes(), 0),
    n_components(0),

    time(0)
{};


// Utility function
void Tarjan::find_SCC(int u)
{
    this->disc_time[u] = this->low[u] = ++this->time;
    this->stack.push(u);
    this->is_in_stack[u] = true;

    for(const auto v: G.get_neighs(u))
    {
        if (this->disc_time[v] < 0)
        {
            this->find_SCC(v);
            if (this->low[u] > this->low[v]) this->low[u] = this->low[v];

        } else if (this->is_in_stack[v] && this->low[u] > this->disc_time[v])
            this->low[u] = this->disc_time[v];
    }

    if (this->low[u] == this->disc_time[u])
    {
        int w;
        do
        {
            w = this->stack.top();
            this->is_in_stack[w] = false;
            this->components[w] = this->n_components;
            this->stack.pop();
        } while (w != u);
        this->n_components++;
    }
}

/**
 * A strongly conected component (SCC) of a graph is a set of nodes where it exists a path between any pair.
 * This algorithm (Tarjan's) finds the SCC of each node. 
 * 
 * Time complexity = O(N + E)
 * Space complexity = O(N)
 */
void Tarjan::run()
{
    for (int u = 0; u < this->N; ++u)
        if (this->disc_time[u] == -1) this->find_SCC(u);
}
