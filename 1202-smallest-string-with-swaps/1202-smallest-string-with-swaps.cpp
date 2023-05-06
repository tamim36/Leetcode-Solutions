class Solution {
public:
    int find_smallestStringWithSwaps(vector<int>& par, int val) {
    if (par[val] == val) 
        return val;
    return par[val] = find_smallestStringWithSwaps(par, par[val]);
}

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.size();
    if (n == 1 || pairs.empty())
        return s;
    vector<int> par(n);
    unordered_set<int> unique_idx;

    for (int i = 0; i < n; i++)
        par[i] = i;

    for (auto& p : pairs) {
        if (!unique_idx.count(p[0]))
            unique_idx.insert(p[0]);

        if (!unique_idx.count(p[1]))
            unique_idx.insert(p[1]);

        int a = find_smallestStringWithSwaps(par, p[0]);
        int b = find_smallestStringWithSwaps(par, p[1]);

        if (a != b)
            par[a] = b;
    }

    unordered_map<int, vector<int>> mp;
    for (auto& idx : unique_idx) {
        int p_idx = find_smallestStringWithSwaps(par, idx);
        mp[p_idx].push_back(idx);
    }

    char* ans = s.data();
    for (auto& kv : mp) {
        vector<char> chrs;
        vector<int> idx_sort;

        for (int i = 0; i < kv.second.size(); i++) {
            chrs.push_back(s[kv.second[i]]);
            idx_sort.push_back(kv.second[i]);
        }
            
        sort(idx_sort.begin(), idx_sort.end());
        sort(chrs.begin(), chrs.end());

        for (int i = 0; i < idx_sort.size(); i++) {
            ans[idx_sort[i]] = chrs[i];
        }
    }

    string ansstr = "";
    for (int i = 0; i < s.size(); i++) {
        ansstr += ans[i];
    }

    return ansstr;
}
};