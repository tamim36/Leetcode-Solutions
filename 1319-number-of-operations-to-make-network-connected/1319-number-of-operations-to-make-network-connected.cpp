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

    if (u == v) return 1;

    if (rank[u] > rank[v]) {
        parent[u] = v;
        rank[u] += rank[v];
    }
    else {
        parent[v] = u;
        rank[v] += rank[u];
    }
    
    return 0;
}

int makeConnected(int n, vector<vector<int>>& connections) {
    vector<int> parent(n, 0), rank(n, 0);
    int remain = 0;

    for (int i = 0; i < n; i++) {
        rank[i] = 1;
        parent[i] = i;
    }

    for (auto& edge : connections) {
        int u = edge[0];
        int v = edge[1];

        remain += makeConnected_union(parent, rank, u, v);
    }

    int need = 0;
    for (int i = 1; i < n; i++) {
        if (!makeConnected_union(parent, rank, 0, i))
            need++;
    }

    //cout << remain << " "  << need << endl;
    return remain - need >= 0 ? need : -1;
}
};