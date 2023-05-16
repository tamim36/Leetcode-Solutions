class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> edges(n);
    int mx = 0;

    for (int i = 0; i < n; i++) {
        if (i == headID) continue;
        //edges[i].push_back(manager[i]);
        edges[manager[i]].push_back(i);
    }

    queue<int> q;
    q.push(headID);
    while (!q.empty())
    {
        int sz = q.size();

        for (int i = 0; i < sz; i++) {
            int m = q.front(); q.pop();

            for (int j = 0; j < edges[m].size(); j++) {
                int e = edges[m][j];
                    q.push(e);
                    informTime[e] += informTime[m];
                    mx = max(informTime[e], mx);
            }
        }
    }

    return mx;
    }
};