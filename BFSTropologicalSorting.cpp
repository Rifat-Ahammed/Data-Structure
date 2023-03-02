#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int nodes, edges;

vector<int> adj_list[N];
int visited[N];
int indegree[N];
vector<int> topsort;

bool BFS()
{
    for (int i = 1; i <= nodes; i++)
    {
        for (auto adj_node : adj_list[i])
        {
            indegree[adj_node]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= nodes; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        topsort.push_back(top);

        for (auto adj_node : adj_list[top])
        {
            if (--indegree[adj_node] == 0)
            {
                q.push(adj_node);
            }
        }
    }

    bool has_cycle = false;
    for (int i = 1; i <= nodes; i++)
    {
        if (indegree[i] != 0)
            has_cycle = true;
    }

    return !has_cycle;
}

int main()
{
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    if (BFS())
    {
        for (auto i : topsort)
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
