class Solution {
public:
    bool dfsCanFinish(int n, vector<vector<int>>& adj, int cur, vector<int>& vis, unordered_set<int>& st) {
    if (st.count(cur))
        return false;
    if (vis[cur])
        return true;

    vis[cur] = 1;
    st.insert(cur);

    for (int i = 0; i < adj[cur].size(); i++) {
        int neigh = adj[cur][i];
        if (!dfsCanFinish(n, adj, neigh, vis, st))
            return false;
    }
    st.erase(st.find(cur));
    return true;
}

bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n);
    for (auto v : prerequisites)
        adj[v[1]].push_back(v[0]);

    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            unordered_set<int> st;
            if (!dfsCanFinish(n, adj, i, vis, st))
                return false;
        }
    }

    return true;
}
};