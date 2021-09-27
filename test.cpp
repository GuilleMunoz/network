#include <iostream>

#include <vector>
#include <tuple>

#include "Graph.hpp"

#include "Kruskal.hpp"
#include "Dijkstra.hpp"
#include "FW.hpp"
#include "Tarjan.hpp"
#include "Prim.hpp"


using namespace std;

int main()
{
    Graph g(5);

    g.add_edge(1, 0);
    g.add_edge(0, 2, 100);
    g.add_edge(2, 1);
    g.add_edge(0, 3);
    g.add_edge(3, 4);

    Kruskal kruskal(g);
    Tarjan tarjan(g);
    Dijkstra dijkstra(g);
    Floyd_Warshall fw(g);
    Prim prim(g);


    kruskal.run();
    fw.run();
    tarjan.run();
    dijkstra.run(0);
    prim.run();

    cout << kruskal << endl;
    cout << prim << endl;
}

