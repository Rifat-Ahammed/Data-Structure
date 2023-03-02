#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int nodes, edges;

vector<int> adj_list[N];
int parent[N];
int visited[N];
int end, start;

bool cycle_detection(int src)
{

    visited[src] = 1;

    for (auto adj_node : adj_list[src])
    {
        if (parent[src] == adj_node)
            continue;

        if (!visited[adj_node])
        {
            parent[adj_node] = src;
            bool ans = cycle_detection(adj_node);
            if (ans)
                return true;
        }
        else if (visited[adj_node] == 1)
        {
            ::end = src;
            ::start = adj_node;
            return true;
        }
    }

    visited[src] = 2;
    return false;
}

int main()
{
    cin >> nodes >> edges;
    ++nodes;

    for (int i = 1; i <= nodes; i++)
    {
        parent[i] = -1;
    }

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool Cycle_exits = false;

    for (int i = 1; i <= nodes; i++)
    {
        if (cycle_detection(i))
        {
            Cycle_exits = true;
            break;
        }
    }

    if (Cycle_exits)
    {

        int par = ::end;
        vector<int> v;
        while (true)
        {
            v.push_back(par);
            if (par == start)
                break;
            par = parent[par];
        }
        v.push_back(v[0]);
        cout << v.size() << endl;
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
