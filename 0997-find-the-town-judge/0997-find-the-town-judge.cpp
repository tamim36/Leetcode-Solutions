class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n+1);

    for (auto t : trust) {
        int s = t[0], d = t[1];
        adj[s].push_back(d);
    }

    int judge = 0;
    for (int i = 1; i < adj.size(); i++) {
        if (!adj[i].size()) {
            judge = i;
            break;
        }
    }
    if (!judge) return -1;
    for (int i = 1; i < adj.size(); i++) {
        if (judge == i)
            continue;
        if (adj[i].empty())
            return -1;

        bool hasConn = false;
        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == judge) {
                hasConn = true;
                break;
            }
        }
        if (!hasConn)
            return -1;
    }

    return judge;
    }
};