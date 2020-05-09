#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX
#define Graph vector<vector<pair<int, int> > >

vector<int> Dijkstra(Graph &G, int source)
{
    vector<int> Dist;

    priority_queue<pair<int, int>,
                   vector<pair<int, int> >,
                   greater<pair<int, int> > >
        Q;

    Dist.assign(G.size(), INF);
    Dist[source] = 0;

    pair<int, int> p(0, source);
    Q.push(p);

    while (!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        for (int i = 0; i < G[u].size(); i++)
        {
            pair<int, int> edge = G[u][i];
            int v = edge.first;
            int w = edge.second;

            if (Dist[v] > Dist[u] + w)
            {
                Dist[v] = Dist[u] + w;
                pair<int, int> pp(Dist[v],v);
                Q.push(pp);
            }
        }
    }

    return Dist;
}

int main()
{
    int nodes, edges, source, u, v, w;

    Graph G;

    //Read
    cin >> nodes >> edges >> source;
    G.resize(nodes);

    for (int i = 0; i < edges; i++)
    {

        cin >> u >> v >> w;

        //u->v
        pair<int, int> edge1(v - 1, w);
        G[u-1].push_back(edge1);

        //v->u
        pair<int, int> edge2(u - 1, w);
        G[v-1].push_back(edge2);
    }

    //The interesting part
    vector<int> distances = Dijkstra(G, source - 1);

    //Output
    cout << endl << "Min distances: " << endl;

    for (int i = 0; i < nodes; i++)
    {
        if (i != source - 1)
        {
             cout << source << " -> " << i+1 << " : ";
            if (distances[i] == INF)
            {
                cout << "INFINITY" << endl;
            }
            else
            {
                cout << distances[i] << endl;
            }
        }
    }

    return 0;
}

/*
5 8 1
1 2 2
1 3 12
1 4 10
2 3 9
2 5 5
3 4 6
3 5 3
4 5 7
*/