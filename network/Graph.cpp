#include "Graph.hpp"


ostream & operator<<(ostream &out, const Edge edge)
{
    out << edge.source << ' ' << edge.dest << ' ' << edge.weight;
    return out;
}


/**
 * Adds a node to the graph
 */
void Graph::add_node()
{
    edges.push_back(vector<int>());
    weights.push_back(vector<double>());
    N++;
}


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
void Graph::add_edge(int u, int v, double w)
{
    int m = _max_(u, v);
    if (m > N) resize(m);

    edges[u].push_back(v);
    weights[u].push_back(w);

    E++;

    if (!is_directed && u != v) // No loop and not directed
    {
        edges[v].push_back(u);
        weights[v].push_back(w);
    }
}


/**
 * Resizes a graph so that it contains n nodes
 *
 * @param n Number of nodes
 */
void Graph::resize(int n)
{
    if (n < this-> N)
    {
        // TODO: N Smaller. We have to loop through all the edges and delete those that have a node (U) such as U >= n
    }else
    {
        for (int i = this->N; i < n; ++i) this->add_node();
    }
    this->N = n;
}


/**
 * Loads a graph from a file (fname) with the following format:
 *
 * Line 1: N\n <number of nodes>
 * Line 2: IS_DIRECTED\n <1 if directed 0 if undirected>
 * Line 3: E1_source E1_dest E1_weight\n <edge 1>
 * Line 4: E2_source E2_dest\n <edge 2 with default weight (1)>
 * ...
 * Line i: Ei_source Ei_dest Ei_weight\n <edge i - 2>
 * ...
 *
 * @param fname (string) The name of the file to be read
 */
void Graph::read(const string &fname)
{
    ifstream graph(fname); // Open file
    string line;

    if (getline(graph, line)) // Number of nodes
    {
        if (line.size() <= 0) return;
        int n = stoi(line);
        this->resize(n);
    }
    if (getline(graph, line)) // If the graph is directed or not
    {
        if (line.size() <= 0) return;
        this->is_directed = stoi(line) == 1;
    }

    int pos_source, pos_dest;
    double weight;

    while (getline(graph, line))
    {
        if ((pos_source = line.find(" ")) < 0) return;

        if ((pos_dest = line.find(" ", pos_source + 1)) < 0)
        {
            if (pos_source == line.size()) continue; // No destination
            weight = 1.; // Default weight
            pos_dest = line.size() - 1;
        }
        else
            weight = stod(line.substr(pos_dest + 1, line.size()));

        int source = stoi(line.substr(0, pos_source));
        int dest = stoi(line.substr(pos_source, pos_dest));

        this->add_edge(source, dest, weight);
    }
}


/**
 * Gets the edges of the graph.
 *
 * @return vector<Edge> the edges of the graph
 */
vector<Edge> Graph::get_edges() const
{
    vector<Edge> edges;

    for (int u=0; u < N; ++u)
    {
        for(int i = 0; i < this->edges[u].size(); ++i)
        {
            // To avoid duplicate edges we store (u, v) if u < v
            if (! this->is_directed && u > this->edges[u][i]) continue;

            Edge edge = Edge(u, this->edges[u][i], weights[u][i]);
            edges.push_back(edge);
        }
    }
    return edges;
}


/**
 * Check if the graph is conected
 * 
 * Space complexity = O(n)
 * Time complexity = O(n)
 *
 * @return True if the graph is connected else False
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
 *
 * @return True if the graph doesn't have cycles else False
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