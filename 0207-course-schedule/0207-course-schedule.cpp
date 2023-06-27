class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<int> vis(n), indg(n, 0);
    vector<vector<int>> adj(n);
    queue<int> q;

    for (auto v : prerequisites)
        adj[v[1]].push_back(v[0]);

    for (auto childs : adj)
        for (auto child : childs)
            indg[child]++;

    for (int i = 0; i < n; i++) {
        if (!indg[i]) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        vis[cur] = 1;

        for (auto neigh : adj[cur])
            if (!--indg[neigh] && !vis[neigh]) {
                q.push(neigh);
                vis[neigh] = 1;
            }
    }

    int tot = 0;
    for (int i = 0; i < n; i++)
        if (vis[i]) tot++;

    return tot == n;
}
};