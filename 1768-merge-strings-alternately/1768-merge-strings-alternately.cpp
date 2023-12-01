class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

for (int i = 0, x = 0, y = 0; i < word1.size() + word2.size(); i++) {
    if (i % 2  == 0) {
        if (x < word1.size())
            ans += word1[x++];
        else
            ans += word2[y++];
    }
    else {
        if (y < word2.size())
            ans += word2[y++];
        else
            ans += word1[x++];
    }
}

return ans;
    }
};