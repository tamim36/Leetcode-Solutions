class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        vector<pair<int, int>> dt;
int n = damage.size();

long long totDamage = 0;
for (int i = 0; i < n; i++) {
    totDamage += damage[i];
    dt.push_back({damage[i], ceil((double)health[i] / power)});
}

sort(dt.begin(), dt.end(), [](pair<int, int> pi, pair<int, int> pj) {
    return (1ll * pi.second* pj.first) < (1ll * pi.first* pj.second);
    });

long long minDamage = 0;
for (int i = 0; i < dt.size(); i++) {
    minDamage += (dt[i].second * totDamage * 1ll);
    totDamage -= dt[i].first;
}

return minDamage;
    }
};