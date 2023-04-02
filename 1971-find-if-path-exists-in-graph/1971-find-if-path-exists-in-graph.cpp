class Solution {
public:
    unordered_set<int> vis;
vector<vector<int>> adjacencyList(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto edge : edges) {
        int a = edge[0], b = edge[1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return adj;
}

bool is_has_validPath(vector<vector<int>>& adj, int src, int dst) {
    if (src == dst) return true;
    if (vis.count(src)) return false;

    vis.insert(src);

    for (auto node : adj[src])
        if (is_has_validPath(adj, node, dst))
            return true;

    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    auto adj = adjacencyList(n, edges);
    return is_has_validPath(adj, source, destination);
}
};