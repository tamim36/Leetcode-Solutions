class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

for (auto str : strs) {
    string key = str;
    sort(key.begin(), key.end());

    mp[key].push_back(str);
}

vector<vector<string>> ans;
for (auto kvp : mp) {

    vector<string> group;
    for (auto anagram : kvp.second) {
        group.push_back(anagram);
    }
    ans.push_back(group);
}

return ans;
    }
};