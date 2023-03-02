#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int nodes, edges;

vector<int> adj_list[N];
int parent[N];
int visited[N];
queue<int> q;
int end, start;

void bfs(int src)
{
    q.push(src);
    visited[src] = 1;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (auto adj_nodes : adj_list[top])
        {
            if (!visited[adj_nodes])
            {
                q.push(adj_nodes);
                visited[adj_nodes] = 1;
            }
        }
    }
}

int main()
{
    cin >> nodes >> edges;

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

    int count = 0;
    vector<int> v;
    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            v.push_back(i);
            count++;
            bfs(i);
        }
    }

    if (count != 1)
    {
        cout << --count << endl;
        for (int i = 0; i < count; i++)
        {
            cout << v[i] << " " << v[i + 1] << endl;
        }
    }
    else
    {
        cout << "0" << endl;
    }

    return 0;
}
