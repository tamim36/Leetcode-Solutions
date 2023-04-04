class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
    int n = 0;
    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
        n = max(n, edge[0]);
        n = max(n, edge[1]);
    }

    for (auto kv : adj) {
        if (adj[kv.first].size() == n - 1)
            return kv.first;
    }

    return -1;
    }
};