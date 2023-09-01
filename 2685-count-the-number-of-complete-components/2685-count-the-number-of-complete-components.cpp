class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
    vector<int> vis(n, 0);

    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    queue<int> q;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            q.push(i);
            vis[i] = 1;
            int con_nodes = adj[i].size();
            bool is_connected = true;
            int num_of_nodes = 0;

            while (!q.empty())
            {
                int cur = q.front(); q.pop();
                num_of_nodes++;

                if (is_connected && adj[cur].size() != con_nodes)
                    is_connected = false;

                for (auto nei : adj[cur]) {
                    if (!vis[nei]) {
                        q.push(nei);
                        vis[nei] = 1;
                    }
                }
            }
            if (num_of_nodes - 1 == con_nodes && is_connected)
                cnt++;
        }
    }

    return cnt;
    }
};