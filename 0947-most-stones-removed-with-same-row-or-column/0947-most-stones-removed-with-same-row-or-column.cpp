class Solution {
    struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int>& v) const {
        return v.first * 31 + v.second;
    }
};
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
    unordered_set<pair<int, int>, pair_hash> vis;
    unordered_map<int, vector<int>> row, col;

    for (int i = 0; i < stones.size(); i++) {
        int x = stones[i][0], y = stones[i][1];
        row[x].push_back(y);
        col[y].push_back(x);
    }

    int sum = 0, val = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        int x = stones[i][0], y = stones[i][1];
        if (!vis.count({x, y})) {
            q.push({ x, y });
            vis.insert({x, y});
            val = 0;

            while (!q.empty()) {
                int a = q.front().first, b = q.front().second; q.pop();
                val++;

                for (int j = 0; j < row[a].size(); j++) {
                    if (!vis.count({a, row[a][j]})) {
                        q.push({ a, row[a][j] });
                        vis.insert({ a, row[a][j] });
                    }
                }
                for (int j = 0; j < col[b].size(); j++) {
                    if (!vis.count({ col[b][j], b })) {
                        q.push({col[b][j], b});
                        vis.insert({ col[b][j], b });
                    }
                }
            }

            sum += val - 1;
        }
    }

    return sum;
    }
};