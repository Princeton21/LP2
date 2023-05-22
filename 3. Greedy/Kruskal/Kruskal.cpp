#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    vector<Edge> edges;

    Graph(int v, int e)
    {
        V = v;
        E = e;
    }
};

bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int findParent(int v, vector<int> &parent)
{
    if (parent[v] == -1)
        return v;
    return findParent(parent[v], parent);
}

void unionSets(int x, int y, vector<int> &parent)
{
    parent[x] = y;
}

void kruskalMST(Graph graph)
{
    vector<Edge> result;
    vector<int> parent(graph.V, -1);

    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    int edge_count = 0, index = 0;
    while (edge_count < graph.V - 1)
    {
        Edge next_edge = graph.edges[index++];

        int x = findParent(next_edge.src, parent);
        int y = findParent(next_edge.dest, parent);

        if (x != y)
        {
            result.push_back(next_edge);
            unionSets(x, y, parent);
            edge_count++;
        }
    }

    int min_cost = 0;
    for (const Edge &edge : result)
    {
        printf("Edge %d:(%d, %d) cost: %d\n",
               edge_count++, edge.src, edge.dest, edge.weight);
        min_cost += edge.weight;
    }

    printf("\nMinimum cost = %d\n", min_cost);
}

int main()
{
    int n, e;
    cin >> n >> e;
    Graph graph(n, e);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge edge;
        edge.src = u;
        edge.dest = v;
        edge.weight = w;
        graph.edges.push_back(edge);
    }

    kruskalMST(graph);

    return 0;
}
