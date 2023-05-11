class Solution {
public:
    int find_smallestEquivalentString(vector<int>& par, int val) {
    
        if (par[val] == val)
            return val;

    return par[val] = find_smallestEquivalentString(par, par[val]);
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
    vector<int> par(26);
    for (int i = 0; i < 26; i++) par[i] = i;

    for (int i = 0; i < s1.length(); i++) {
        int a = find_smallestEquivalentString(par, s1[i] - 'a');
        int b = find_smallestEquivalentString(par, s2[i] - 'a');

        if (a < b) par[b] = a;
        else
            par[a] = b;
    }

    string ans = "";
    for (int i = 0; i < baseStr.size(); i++) {
        ans += par[find_smallestEquivalentString(par, baseStr[i] - 'a')] + 'a';
    }

    return ans;
}
};