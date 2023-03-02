#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int nodes, edges;

vector<int> adj_list[N];
int parent[N];
int visited[N];
queue<int> q;
int end, start;

bool cycle_detection(int src)
{

    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {

        int top = q.front();
        q.pop();

        for (auto adj_node : adj_list[top])
        {
            if (!visited[adj_node])
            {
                parent[adj_node] = top;
                visited[adj_node] = 1;
                q.push(adj_node);
            }
            else if (parent[top] != adj_node)
            {
                start = adj_node;
                return true;
            }
        }
    }

    return false;
}

void path_find(int src)
{
    visited[src] = 1;

    for (auto adj_node : adj_list[src])
    {
        if (parent[src] == adj_node)
            continue;

        if (!visited[adj_node])
        {
            parent[adj_node] = src;
            path_find(adj_node);
        }
        else if (visited[adj_node] == 1)
        {
            start = adj_node;
            ::end = src;
        }
    }

    visited[src] = 2;
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

    bool has_cycle = false;

    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i] && cycle_detection(i))
        {
            has_cycle = true;
            break;
        }
    }
    if (has_cycle)
    {
        for (int i = 1; i <= nodes; i++)
        {
            parent[i] = -1;
            visited[i] = 0;
        }

        path_find(start);

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
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
