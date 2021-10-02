#include "Boruvka.hpp"


void Boruvka::run()
{
    vector<Edge> edges = this->G.get_edges();

    vector<const Edge*> cheapest_edge_component(N);

    vector<int> component(N);
    for (int i = 0; i < this->N; ++i) component[i] = i;

    int n_trees = this->N;

    vector<bool> updated(this->N, false);

    while (n_trees > 1)
    {
        for (auto edge=begin(edges); edge != end(edges); ++edge)
        {
            int comp_source = component[(*edge).source];
            int comp_dest = component[(*edge).dest];

            if (comp_source == comp_dest) continue;

            if (! cheapest_edge_component[comp_source] || *cheapest_edge_component[comp_source] > *edge)
            {
                cheapest_edge_component[comp_source] = &(*edge);
                updated[comp_source] = true;
            }

            if (! cheapest_edge_component[comp_dest] || *cheapest_edge_component[comp_dest] > *edge)
            {
                cheapest_edge_component[comp_dest] = &(*edge);
                updated[comp_dest] = true;
            }
        }

        // Update the componets
        for (int i = 0; i < this->N; ++i)
        {
            if (updated[i])
            {
                this->prev[i] = (*cheapest_edge_component[i]).source;
                n_trees--;

                for (auto comp = begin(component); comp != end(component); ++comp)
                {
                    if (component[this->prev[i]] == *comp)
                        *comp = i;
                }
            }
        }
        
    }
    
}