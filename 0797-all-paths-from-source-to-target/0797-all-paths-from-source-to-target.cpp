class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // edges cases:
        if (graph.empty()) {
            return {};
        }
        
        // build di-graph
        unordered_map<int, vector<int>> d;
        for (int i = 0; i < graph.size(); i++) {
            d[i] = graph[i]; // one-way link
        }
        
        // apply DFS on DAG
        int n = graph.size();
        vector<pair<int, vector<int>>> stack = {{0, {0}}}; // - store both the (node, and the path leading to it)
        vector<vector<int>> res;
        while (!stack.empty()) {
            int node = stack.back().first;
            vector<int> path = stack.back().second;
            stack.pop_back();
            // check leaf
            if (node == n - 1) {
                res.push_back(path);
            }
            // traverse rest
            for (int nei : d[node]) {
                path.push_back(nei);
                stack.push_back({nei, path});
                path.pop_back();
            }
        }
        return res;
    }
};