class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<int> indg(n, 0);
    vector<vector<int>> adj(n);
    queue<int> q;

    for (auto v : prerequisites) {
        adj[v[1]].push_back(v[0]);
        indg[v[0]]++;
    }

    for (int i = 0; i < n; i++)
        if (!indg[i]) q.push(i);

    int cnt = 0;
    vector<int> ans;
    vector<int> emptyVec;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        indg[cur]--; cnt++;

        for (auto neigh : adj[cur])
            if (!--indg[neigh])
                q.push(neigh);
    }

    return cnt == n ? ans : emptyVec;
}
};