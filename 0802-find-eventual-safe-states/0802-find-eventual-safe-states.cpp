class Solution {
public:
    bool dfsEventualSafeNodes(vector<vector<int>>& graph, int n, vector<int>& vis, int cur) {
    if (vis[cur] == 0) return false;
    if (vis[cur] == 1) return true;

    vis[cur] = 0;

    for (int i = 0; i < graph[cur].size(); i++) {
        if (!dfsEventualSafeNodes(graph, n, vis, graph[cur][i]))
            return false;
    }
    vis[cur] = 1;
    return true;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n, -1);

    for (int i = 0; i < n; i++) {
        if (vis[i] == -1)
            dfsEventualSafeNodes(graph, n, vis, i);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 1) ans.push_back(i);
    }

    return ans;
}
};