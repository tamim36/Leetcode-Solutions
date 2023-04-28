class Solution {
public:
    int makeConnected_helperDfs(vector<vector<int>>& graph, vector<int>& vis, int node) {
    if (vis[node]) return 0;

    vis[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        makeConnected_helperDfs(graph, vis, graph[node][i]);
    }

    return 1;
}

int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;
    vector<int> vis(n, 0);
    vector<vector<int>> graph(n);
    int component = 0;

    for (auto& edge : connections) {
        int u = edge[0];
        int v = edge[1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        component += makeConnected_helperDfs(graph, vis, i);
    }

    return component - 1;
}
};