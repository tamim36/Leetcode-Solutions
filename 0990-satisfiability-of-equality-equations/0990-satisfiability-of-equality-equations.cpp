class Solution {
public:
    int find_equationsPossible(vector<int>& par, int val) {
    if (val == par[val])
        return val;

    return par[val] = find_equationsPossible(par, par[val]);
}

bool equationsPossible(vector<string>& equations) {
    vector<int> par(26);
    for (int i = 0; i < 26; i++) par[i] = i;

    sort(equations.begin(), equations.end(), [](const auto& s1, const auto& s2) {
        return s1[1] > s2[1];
        });
    
    for (auto& eq : equations) {
        int a = eq[0] - 'a', b = eq[3] - 'a';
        char x = eq[1];
        int ap = find_equationsPossible(par, a);
        int bp = find_equationsPossible(par, b);
        if ( (ap == bp) && (x == '!'))
            return false;
        if (x == '=')
            par[ap] = bp;
    }

    return true;
}
};