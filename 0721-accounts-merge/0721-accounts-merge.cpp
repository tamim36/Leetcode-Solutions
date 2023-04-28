class Solution {
public:
    string accountsMerge_find(unordered_map<string, string>& parent, string email) {
    if (!parent.count(email)) {
        parent[email] = email;
        return email;
    }

    if (parent[email] == email)
        return email;
    return parent[email] = accountsMerge_find(parent, parent[email]);
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, string> parent;
    int parent_idx = -1, res_idx = 0;

    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].size() <= 2) {
            string email = accounts[i][1];
            parent[email] = email;
        }
        else {
            for (int j = 2; j < accounts[i].size(); j++) {
                string email1 = accounts[i][j - 1];
                string email2 = accounts[i][j];

                email1 = accountsMerge_find(parent, email1);
                email2 = accountsMerge_find(parent, email2);

                if (email1 != email2)
                    parent[email1] = email2;
            }
        }
    }

    unordered_set<string> new_par;
    for (auto& kvp : parent) {
        new_par.insert(accountsMerge_find(parent, kvp.second));
    }

    int idx = 0;

    unordered_map<string, int> key_mapper;
    for (auto& s : new_par)
        key_mapper[s] = idx++;

    vector<vector<string>> res(idx);
    unordered_set<string> vis;

    for (int i = 0; i < accounts.size(); i++) {
        string name = accounts[i][0];

        for (int j = 1; j < accounts[i].size(); j++) {
            string email = accounts[i][j];
            if (!vis.count(email)) {
                int index = key_mapper[accountsMerge_find(parent, email)];

                if (res[index].empty())
                    res[index].push_back({ name });

                res[index].push_back(email);
                vis.insert(email);
            }
        }
    }


    for (int i = 0; i < res.size(); i++) {
        sort(res[i].begin() + 1, res[i].end());
    }

    return res;
}
};