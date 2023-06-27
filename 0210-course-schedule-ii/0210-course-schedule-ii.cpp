class Solution {
public:
    bool dfsFindOrder(int n, vector<vector<int>>& adj, stack<int>& stk,
                vector<int>& vis, vector<int>& curPath, int cur) {
    if (curPath[cur]) return false;
    if (vis[cur]) return true;

    curPath[cur] = vis[cur] = 1;
    for (int i = 0; i < adj[cur].size(); i++) {
        if (!dfsFindOrder(n, adj, stk, vis, curPath, adj[cur][i]))
            return false;
    }
    
    stk.push(cur);
    curPath[cur] = 0;
    return true;
}

vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<int> vis(n, 0), curPath(n, 0);
    vector<vector<int>> adj(n);
    stack<int> stk;

    for (auto v : prerequisites)
        adj[v[1]].push_back(v[0]);

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!vis[i] && !dfsFindOrder(n, adj, stk, vis, curPath, i))
            return ans;
    }

    while (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}
};