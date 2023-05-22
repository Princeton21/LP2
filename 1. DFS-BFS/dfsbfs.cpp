#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &G)
{
    stack<int> s;
    vector<bool> vis(G.size(), false);
    s.push(0);
    cout << "The given dfs is : ";
    while (!s.empty())
    {
        int top = s.top();
        vis[top] = true;
        cout << top << " ";
        s.pop();
        for (auto child : G[top])
        {
            if (!vis[child])
                s.push(child);
        }
    }
}

void bfs(vector<vector<int>> &G)
{
    queue<int> q;
    q.push(0);
    vector<bool> vis(G.size(), false);
    cout << "Therefore the given bfs is : \n";
    while (!q.empty())
    {
        int top = q.front();
        cout << top << " ";
        vis[top] = true;
        q.pop();
        for (auto child : G[top])
        {
            if (!vis[child])
                q.push(child);
        }
    }
}
void recursiveDFS(int vertex, vector<vector<int>> &G, vector<bool> &vis)
{
    cout << vertex << " ";
    vis[vertex] = true;
    for (auto child : G[vertex])
    {
        if (!vis[child])
            recursiveDFS(child, G, vis);
    }
}

void recursiveBFS(queue<int> &q, vector<bool> &vis, vector<vector<int>> &G)
{
    if (q.empty())
        return;

    int top = q.front();
    vis[top] = true;
    cout << top << " ";
    q.pop();

    for (auto &child : G[top])
    {
        if (!vis[child])
        {
            q.push(child);
        }
    }

    recursiveBFS(q, vis, G); // Move this line to the beginning of the function
}

void menu(vector<vector<int>> &G)
{
    int n;

    cout << " Choose and option\n";
    cout << " 1. DFS\n";
    cout << " 2. BFS\n";
    cout << " 3. Recursive DFS\n";
    cout << " 4. Recursive BFS\n";

    cin >> n;
    vector<bool> vis(G.size(), false);
    if (n == 1)
        dfs(G);
    else if (n == 2)
        bfs(G);
    else if (n == 3)
        recursiveDFS(0, G, vis);
    else if (n == 4)
    {
        queue<int> q;
        q.push(0);
        recursiveBFS(q, vis, G);
    }
}

int main()
{
    vector<vector<int>> G;
    cout << "Enter number of vertices\n";
    int v;
    cin >> v;
    cout << "Enter number of edges\n";
    int e;
    cin >> e;
    cout << "Give the edges\n";

    G.resize(v);

    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[v].push_back(u);
        G[u].push_back(v);
    }

    menu(G);
    cout << "\nDo you want to continue : ";
    string s;
    cin >> s;
    while (s == "yes")
    {
        menu(G);
        cout << "\nDo you want to continue : ";
        cin >> s;
    }
    cout << "Thank you\n";
}