#include <bits/stdc++.h>
using namespace std;

#define N (int)1000
int n, m;
int maze[N][N];
int visited[N][N];
pair<int, int> parent[N][N];
vector<pair<int, int>> coord;

pair<int, int> last;

bool is_valid(int row, int col)
{
    if (row >= 0 && row < n && col >= 0 && col < m)
        return true;
    return false;
}

bool is_safe(int row, int col)
{
    if (maze[row][col] == 0)
        return true;
    return false;
}

bool dfs(pair<int, int> src)
{
    if (src.first == 0 || src.second == 0 || src.first == n - 1 || src.second == m - 1)
    {
        last = src;
        return true;
    }

    visited[src.first][src.second] = 1;

    int row = src.first;
    int col = src.second;

    int diff_x[4] = {0, 0, 1, -1};
    int diff_y[4] = {1, -1, 0, 0};

    for (int j = 0; j < coord.size(); j++)
    {
        int row = coord[j].first;
        int col = coord[j].second;

        for (int i = 0; i < 4; i++)
        {
            int new_row = row + diff_x[i];
            int new_col = col + diff_y[i];

            if (is_valid(new_row, new_col) && is_safe(new_row, new_col))
            {
                maze[row][col] = 0;
                maze[new_row][new_col] = -1;
                break;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int new_row = row + diff_x[i];
        int new_col = col + diff_y[i];
        if (is_valid(new_row, new_col) && is_safe(new_row, new_col) && !visited[new_row][new_col])
        {
            pair<int, int> new_src = {new_row, new_col};
            parent[new_row][new_col] = {row, col};
            bool istrue = dfs(new_src);
            if (istrue)
                return true;
        }
    }

    return false;
}

char get_direction(pair<int, int> curr, pair<int, int> next)
{
    int x = curr.first;
    int y = curr.second;
    int new_x = next.first;
    int new_y = next.second;

    if (x > new_x)
        return 'U';
    else if (x < new_x)
        return 'D';
    else if (y > new_y)
        return 'L';
    return 'R';
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            parent[i][j] = {-1, -1};
        }
    }

    pair<int, int> src;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < m; j++)
        {
            if (input[j] == '.')
                maze[i][j] = 0;
            else if (input[j] == '#')
                maze[i][j] = -1;
            else if (input[j] == 'A')
            {
                src = {i, j};
                maze[i][j] = 0;
            }
            else
            {
                coord.push_back({i, j});
                maze[i][j] = -1;
            }
        }
    }
    bool a = dfs(src);
    if (a)
    {
        cout << "Yes\n";
        pair<int, int> l = last;
        vector<pair<int, int>> v;
        while (l.first != src.first || l.second != src.second)
        {
            v.push_back(l);
            l = parent[l.first][l.second];
        }

        reverse(v.begin(), v.end());
        int len = v.size();
        cout << len << endl;

        pair<int, int> curr = src;
        for (int i = 0; i < len; i++)
        {
            char direction = get_direction(curr, v[i]);
            cout << direction;
            curr = v[i];
        }
        cout << endl;
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}
