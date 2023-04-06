class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
    queue<vector<int>> q;
    int des = graph.size()-1, src = 0;
    q.push({0});

    while (!q.empty()) {
        auto top = q.front(); q.pop();
        int curDes = top[top.size() - 1];
        if (curDes == des) {
            ans.push_back(top);
            continue;
        }
        for (auto edge : graph[curDes]) {
            top.push_back(edge);
            q.push(top);
            top.pop_back();
        }
    }
    return ans;
    }
};