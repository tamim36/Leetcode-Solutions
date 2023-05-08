class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> vec(n, 0), ans;
    int cnt = 0;

    for (auto& q : queries) {
        int idx = q[0], col = q[1];
        if (idx > 0 && vec[idx] != 0 && vec[idx] == vec[idx - 1]) cnt--;
        if (idx < n - 1 && vec[idx] != 0 && vec[idx] == vec[idx + 1]) cnt--;

        vec[idx] = col;

        if (idx > 0 && vec[idx] == vec[idx - 1]) cnt++;
        if (idx < n - 1 && vec[idx] == vec[idx + 1]) cnt++;
        
        ans.push_back(cnt);
    }

    return ans;
    }
};