#include <FW.hpp>


Floyd_Warshall::Floyd_Warshall(const Graph &G):
    G(G),
    N(G.get_n_nodes()),
    dist(G.get_n_nodes() * G.get_n_nodes(), MAX),
    next(G.get_n_nodes() * G.get_n_nodes(), 0)
{
    vector<Edge> edges = G.get_edges();

    for (auto edge = begin(edges); edge != end(edges); ++edge)
    {
        this->dist[(*edge).source * this->N + (*edge).dest] = (*edge).weight; 
        this->next[(*edge).source * this->N + (*edge).dest] = (*edge).dest;
    }
    for (int u = 0; u < this->N; ++u)
    {
        this->dist[u * this->N + u] = 0; 
        this->next[u * this->N + u] = u;
    }
};


/**
 * Main method of the class. Finds the shortest route from each node to the rest
 * 
 * Time complexity = O(N ^ 3)
 * Space complexity = O(N ^ 2)
 */
void Floyd_Warshall::run()
{
    for(int i = 0; i < this->N; ++i)
    {
        for(int j = 0; j < this->N; ++j)
        {
            for(int k = 0; k < this->N; ++k)
            {
                if (this->dist[j * N + k] < this->dist[j * N + i] + this->dist[i * N + k])
                {
                    this->dist[j * N + k] = this->dist[j * N + i] + this->dist[i * N + k];
                    this->next[j * N + k] = this->next[j * N + i];
                }
            }
        }
    }
}


/** 
 * Construct the minimum path from a node to another
 * 
 * @param const int u: Source node
 * @param const int v: Destination node
 * @return vector<int> such that the path is vec[0] = u -> vec[1] -> ... -> vec[i] -> ... -> vec[-1] = v 
 *         if they are not connected {}
 */
vector<int> Floyd_Warshall::path(const int u, const int v)
{
    if (next[u * N + v] == -1) return {};
    
    vector<int> path = {u};
    int i = u;

    do 
    {
        i = next[i * N + v];
        path.push_back(i);
    } while (i != v);

    return path;
}