// CSES 1666 - Building Roads
// https://cses.fi/problemset/task/1666
// Mövzu: graphs, dfs, connected components
// İdeya:
// Mürəkkəblik: O(n + m)
// Upsolve: no

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v])
        if (!visited[u]) dfs(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> leaders;
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            leaders.push_back(v);
            dfs(v);
        }
    }

    cout << leaders.size() - 1 << "\n";
    for (int i = 1; i < (int)leaders.size(); i++)
        cout << leaders[i - 1] << " " << leaders[i] << "\n";
}
