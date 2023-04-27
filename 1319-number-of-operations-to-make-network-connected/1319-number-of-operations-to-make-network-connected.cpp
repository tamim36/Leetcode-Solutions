class Solution {
public:
    int makeConnected_find(vector<int>& parent, int u) {
    if (parent[u] == u)
        return u;

    return parent[u] = makeConnected_find(parent, parent[u]);
}

int makeConnected_union(vector<int>& parent, vector<int>& rank, int u, int v) {
    u = makeConnected_find(parent, u);
    v = makeConnected_find(parent, v);

    if (u == v) return 0;

    if (rank[u] > rank[v]) {
        parent[u] = v;
        rank[u] += rank[v];
    }
    else {
        parent[v] = u;
        rank[v] += rank[u];
    }
    
    return 1;
}

int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;
    vector<int> parent(n, 0), rank(n, 0);
    int component = 0;

    for (int i = 0; i < n; i++) {
        rank[i] = 1;
        parent[i] = i;
    }

    for (auto& edge : connections) {
        int u = edge[0];
        int v = edge[1];

        component += makeConnected_union(parent, rank, u, v);
    }

    return n - component - 1;
}
};