class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> sources;
    vector<int> vis(n, 0);
    for (auto& edge : edges) {
        int src = edge[0], des = edge[1];
        if (!vis[src])
            sources.insert(src);
        if (sources.count(des))
            sources.erase(sources.find(des));
        vis[src] = 1;
        vis[des] = 1;
    }

    vector<int> ans;
    for (auto& s : sources)
        ans.push_back(s);

    return ans;
    }
};