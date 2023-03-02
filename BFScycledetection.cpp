#include <bits/stdc++.h>
using namespace std;

#define N (int)1e7
int nodes, edges;

vector<int> agj_list[N];
int visited[N];
int indegree[N];

bool cycle_detection()
{

    for (int i = 1; i <= nodes; i++)
    {
        for (auto adj_node : agj_list[i])
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

        for (auto adj_node : agj_list[top])
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
    return has_cycle;
}

int main()
{
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        agj_list[u].push_back(v);
    }

    if (cycle_detection())
    {
        cout << "Cycle Exits" << endl;
    }
    else
    {
        cout << "No Cycle Exits" << endl;
    }

    return 0;
}
