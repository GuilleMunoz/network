#include <Dijkstra.hpp>


Dijkstra::Dijkstra(const Graph &G):
    G(G),
    N(G.get_n_nodes()),
    dist(G.get_n_nodes(), MAX),
    prev(G.get_n_nodes(), -1)
{};


inline double Dijkstra::distance_to(int u)
{
    return this->dist[u];
}
    
    
inline double Dijkstra::distance_to(int u) const
{
    return this->dist[u];
}


/**
 * Finds the shortest distance between the node source and the rest of the nodes.
 * 
 * Space complexity = O(N)
 * Time complexity = O(n * log(N))
 * 
 * @param source the source node
 * @param dist an array where the i-th element is the shortest distance from source to i
 * @param prev an array where the i-th element is the node previous to i in the shortest path
 * @return -1 if the source is not a node else 1
 */
void Dijkstra::run(const int source)
{   
    assert(source < N);

    this->dist[source] = 0.0;

    priority_queue <tup, vector<tup>, greater<tup> > pq;
    pq.push(make_pair(0.0, source));

    double curr_dist;
    int u;

    while (!pq.empty())
    {
        tie(curr_dist, u) = pq.top(); // O(1)
        pq.pop(); // O(log(N))

        auto w = begin(this->G.get_weights(u));
        for(auto v = begin(this->G.get_neighs(u)); v != end(this->G.get_neighs(u)); ++v)
        {   
            double alt = curr_dist + *w++;

            if (alt < this->dist[*v])
            {
                this->dist[*v] = alt;
                this->prev[*v] = u;
                pq.push(make_tuple(alt, *v)); // O(log(N))
            }
        }
    }
}
