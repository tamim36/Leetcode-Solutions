class Solution {
public:
    void dfsCountCompleteComponents(vector<vector<int>>& graph, int cur, vector<int>& vis, int &node, int &edge) {
    if (vis[cur]) return;

    vis[cur] = 1;
    node++;
    edge += graph[cur].size();

    for (auto neigh : graph[cur]) {
        if (vis[neigh]) continue;

        dfsCountCompleteComponents(graph, neigh, vis, node, edge);
    }
}

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0);

    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    queue<int> q;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i])
            continue;
        int node = 0, edge = 0;
        dfsCountCompleteComponents(adj, i, vis, node, edge);
        cnt += node * (node - 1) == edge;
    }

    return cnt;
}
};