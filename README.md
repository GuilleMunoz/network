# network

Simple implementation of a graph data structure and multiple algorithms in C++.

### Data Structures

---
#### Graph

The main class, Graph, is where the data structure core is implemented.
The most commonly used representation of a graph are:
- Adjacency matrix
- Adjacency list

The former has a space complexity of `O(N^2)` whereas the latter's complexity is `O(E)` (where `E` is the number of edges).
Only considering space, the main advantage of the matrix representation is that the matrix can be stored in a continuous array in memory.

The main advantage of the matrix representation is that the complexity of checking whether an edge between two nodes exists
is `O(1)` while the complexity of the other is `O(N)`.
On the opposite, adding a node to the graph has a complexity of `O(N)` for the matrix form and `O(1)` for the alternative.

For this project, we decide to represent graphs with adjacency list representation.

#### Edge

A class used to represent edges in a graph: 
- A source node
- A destination node
- Weight

### Algorithms

All the algorithms will be implemented in their own class, which will have a run function.

---
### Strongly Connected Components

A component is said to be Strongly Connected if for every pair of nodes `u, v`, it exists a path `u > u_1 > ... > v` that connects `u` and `v`.

#### [Tarjan](https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm)

This algorithm work with a directed edge. The output of the algorithm is the vector `Tarjan.components`. 
Two nodes `u` and `v` are in the same SCC if and only if `Tarjan.components[u] == Tarjan.components[v]`.

It has a time complexity of `O(N + E)` and a space complexity `O(N)`.

---
### Shortest Path

#### [Dijkstra](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)

This may well be one of the most famous graph algorithms. 
It finds the shortest path from a source node to the rest. 
The output of the graph is a vector (`Dijstra.prev`) of `N` elements. 
If the shortest path from `u` to `v` is `u > u_1 > ... > u_i > v`, then

``
prev[v] = u_i,
prev[u_i] = u_{i-1}, 
...,
prev[u_1] = u
``

It has a time complexity of `O(N * log(N))` and a space complexity `O(N)`.

#### [Floyd-Warshall](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm)

This algorithm finds the shortest path form every node to the rest.
It works with directed graph with positive or negative edges (but no negative cycles).
The class method `FW.path(u, v)` reconstructs the path form `u` to `v` and returns a vector of ints where 
``
u = vec[0] > vec[1] > ... > vec[-1] = v
``.

It has a time complexity of `O(N^3)` and a space complexity `O(N^2)`.

---
### Minimum Spanning Tree

A Minimum Spanning Tree (MST) is a subset of edges such that their exists no cycles and the minimum possible total edge weight.

#### [Kruskal](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm)

The output of the graph is a vector (`Kuskal.prev`) of `N` elements, where the ith element is the parent of `i` in the MST for the `root` node, `prev[root] = root`.

It has a time complexity of `O(E * log(N))` and a space complexity of `O(max(E, N))`.

#### [Prim](https://en.wikipedia.org/wiki/Prim%27s_algorithm)

Again (like in Kruskal algorithm), the output is a vector (`Prim.prev`) of `N` elements.

It has a time complexity of `O(N^2)` and a space complexity of `O(N)`.

#### [Boruvka](https://en.wikipedia.org/wiki/Borůvka%27s_algorithm)

Like in Kruskal algorithm, the output is a vector (`Boruvka.prev`) of `N` elements.
