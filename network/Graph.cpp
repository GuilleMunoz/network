#include <Graph.hpp>


template <class comparable>
inline comparable _max_(comparable u, comparable v)
{
    return (u > v) ? u: v;
}


/**
 * Adds an edge from u to v with weight w. If their are no enough nodes it 
 * doesn't do anything.
 * 
 * @param u from node
 * @param v to node
 * @param w weight of the edge
 */
void Graph::add_node()
{
    edges.push_back(vector<int>());
    N ++; 
}


/**
 * Adds an edge from u to v with weight w. If their are no enough nodes it 
 * doesn't do anything.
 * 
 * @param u from node
 * @param v to node
 * @param w weight of the edge
 */
void Graph::add_edge(int u, int v, double w)
{
    int m = _max_(u, v);
    while (m > N) add_node();

    edges[u].push_back(v);
    weights[u].push_back(w);

    E++;

    if (!is_directed && u != v) // No loop and not directed
    {
        edges[v].push_back(u);
        weights[v].push_back(w);
    }
}


vector<tuple<int, int, double>> Graph::get_edges() const
{
    vector<tuple<int, int, double>> edges_tups;

    for (int u=0; u < N; ++u)
    {
        for(int i = 0; i < edges[u].size(); ++i)
        {
            // To avoid duplicate edges we store (u, v) if u < v
            if (u > edges[u][i]) continue;
            edges_tups.push_back(make_tuple(u, edges[u][i], weights[u][i]));
        }
    }
    return edges_tups;
}


/**
 * Check if the graph is conected
 * 
 * Space complexity = O(n)
 * Time complexity = O(n)
 */
bool Graph::is_connected()
{
    if (N <= 0) return true;
    if (E < N) return false;

    vector<bool> visited(N, false);
    stack<int> stack;

    stack.push(0); // start dfs at a random node (0 in this case)

    int n_visited = 0;

    while (!stack.empty()) // O(N)
    {
        int u = stack.top();
        stack.pop();

        n_visited++;
        visited[u] = true;

        for (auto const v: edges[u])
        {
            if (visited[v])
                continue;
            else
                stack.push(v);
        }
    }
    
    return n_visited == N;
}


/**
 * Check if the graph is acyclic (doesn't have any cycles).
 * 
 * Space complexity = O(2 * N)
 * Time complexity = O(N)
 */
bool Graph::is_acyclic()
{
    if (N <= 0) return true;
    if (E >= N) return false;

    vector<bool> visited(N, false);
    stack<int> stack;

    for (int u = 0; u < N; ++u)
    {
        if (visited[u])
            return false;
        
        stack.push(u);

        while (!stack.empty())
        {
            int node = stack.top();
            stack.pop();
            visited[node] = true;

            for (auto const v: edges[u])
            {
                if (visited[v])
                    return false; 
                else
                    stack.push(v);
            }
        }
    }
    return true;
}