class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<int, int> occurrence_count, w1_count, w2_count;
if (word1.size() != word2.size())
    return false;

for (auto c : word1)
    w1_count[c - 'a']++;

for (auto cnt1 : w1_count)
    occurrence_count[cnt1.second]++;

for (auto c : word2) {
    if (!w1_count[c - 'a'])
        return false;
    w2_count[c - 'a']++;
}

for (auto cnt2 : w2_count)
    occurrence_count[cnt2.second]--;

for (auto occ : occurrence_count)
    if (occ.second != 0)
        return false;


return true;
    }
};