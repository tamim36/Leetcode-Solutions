class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mp;
vector<int> ans;

for (auto word : words) {
    int mask = 0;
    for (auto ch : word)
        mask |= (1 << (ch - 'a'));

    mp[mask]++;
}

for (auto puzzle : puzzles) {
    int mask = 0;
    for (auto ch : puzzle)
        mask |= (1 << (ch - 'a'));

    int submask = mask, count = 0;
    int first = (1 << (puzzle[0] - 'a'));
    while (submask) {
        if (first & submask)
            count += mp[submask];

        submask = (submask - 1) & mask;
    }

    ans.push_back(count);
}

return ans;
    }
};