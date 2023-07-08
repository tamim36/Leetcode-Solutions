class Solution {
public:
    vector<int> dfs_findMHT(vector<vector<int>>& graph, vector<bool>& vis, int cur) {
    vector<int> longestPath, path;
    vis[cur] = true;

    for (auto adj : graph[cur])
        if (!vis[adj])
            if (size(path = dfs_findMHT(graph, vis, adj)) > size(longestPath))
                longestPath = move(path);

    vis[cur] = false;
    longestPath.push_back(cur);
    return longestPath;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> vec;
    int sz = vec.size();
    int sz1 = size(vec);
    if (n == 1) return { 0 };
    vector<vector<int>> graph(n);
    vector<bool> vis(n);

    for (auto edge : edges)
        graph[edge[0]].push_back(edge[1]),
        graph[edge[1]].push_back(edge[0]);

    auto path = dfs_findMHT(graph, vis, dfs_findMHT(graph, vis, 0)[0]);
    if (size(path) % 2)
        return { path[size(path) / 2] };

    return {path[size(path)/2], path[size(path)/2 - 1]};
}
};