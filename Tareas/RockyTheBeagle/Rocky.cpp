//Alex Vargas
//A00824525


#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX
#define Edge pair<int, int>
#define Graph vector<vector<Edge> >
#define Vertex pair<int, int> // Distance from source, vertex ID

vector<int> Dijkstra(Graph g, int source)
{
    vector<int> dist;
   
    priority_queue<pair<int, int>,
                   vector<pair<int, int> >,
                   greater<pair<int, int > > >
        q;

    dist.assign(g.size(), INF);
    dist[source] = 0;

    pair<int, int> p(source, 0);
    q.push(p);

    while (!q.empty())
    {
        pair<int, int> top = q.top();
        int u = top.first;
        q.pop();

        for (int i = 0; i < g[u].size(); i++)
        {
            pair<int, int> edge = g[u][i];
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pair<int, int> pp(v, dist[v]);
                q.push(pp);
            }
        }
    }

    return dist;
}

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second > b.second)
    {
        return true;
    }
    else if (a.second == b.second)
    {
        if (a.first < b.first)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int nodes, edges, u, v, w, cases;
    char ch_v, ch_u;
    

    cin >> cases;

    for (int cs = 1; cs <= cases; cs++)
    {
        Graph G;
        // Read from stdin
        cin >> nodes >> edges;
        G.resize(nodes);

        for (int i = 0; i < edges; i++)
        {
            cin >> ch_u >> ch_v >> w;

            u = ch_u - 'A';
            v = ch_v - 'A';

            // Edge from u->v
            Edge edge1(v, w);
            G[u].push_back(edge1);

            // Edge from v->u
            Edge edge2(u, w);
            G[v].push_back(edge2);
        }

        // We run our algorithm
        vector<int> distances = Dijkstra(G, 0);

        //Vector with distances and positions
        vector<pair<int, int> > W;

        for (int i = 0; i < nodes; i++)
        {
            W.push_back(pair<int, int>(i, distances[i]));
        }

        //Sort Vector
        sort(W.begin(), W.end(), sortbysec);

        //Display answer
        char cR = W[0].first + 'A';

        cout << "Case " << cs << ": " << cR << endl;
    }

    return 0;
}

/*
2
5 7
A B 5
A C 4
A D 7
B E 3
C D 2
C E 4
D E 1
4 6
A B 1
A C 1
A D 1
B C 1
B D 1
C D 1
*/