class Solution {
    struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int>& v) const {
        return v.first * 31 + v.second;
    }
};
public:
    int minReorder(int n, vector<vector<int>>& connections) {
    unordered_set<pair<int, int>, pair_hash> st;
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0);

    for (auto v : connections) {
        st.insert({v[0], v[1]});
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }

    queue<int> q;
    int cnt = 0;
    q.push(0);

    while (!q.empty()) {
        int top = q.front(); q.pop();
        vis[top] = 1;
        
        for (auto node : adj[top]) {
            if (!vis[node]) {
                q.push(node);
                if (!st.count({ node, top }))
                    cnt++;
            }
        }
    }
    return cnt;
    }
};