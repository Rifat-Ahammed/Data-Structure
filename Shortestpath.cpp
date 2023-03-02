/*
  Write code to solve the single source shortest path problem on a DAG using DFS.
Take both the DAG and the source node as input and output the distance of each node.
(You can choose any graph representation or input format of your choice)

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int nodes, edges;

vector<int> adj_list[N];
int level[N];
int visited[N];

void dfs(int nodes)
{
    visited[nodes] = 1;

    for (auto adj_nodes : adj_list[nodes])
    {
        if (!visited[adj_nodes])
        {
            level[adj_nodes] = level[nodes] + 1;
            dfs(adj_nodes);
        }
        else if (level[adj_nodes] > level[nodes] + 1)
        {
            level[adj_nodes] = level[nodes] + 1;
        }
    }
}

int main()
{
    cin >> nodes >> edges;

    for (int i = 0; i < nodes; i++)
    {
        level[i] = -1;
    }

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    int source;
    cout << "Source: ";
    cin >> source;

    level[source] = 0;
    dfs(source);

    for (int i = 0; i < nodes; i++)
    {
        cout << i << " : " << level[i] << endl;
    }

    return 0;
}
