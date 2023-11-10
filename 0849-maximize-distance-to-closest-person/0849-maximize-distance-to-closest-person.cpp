class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int cur = 1, mx = 0;
bool st = true;

for (auto seat : seats) {
    if (seat) {
        if (st)
            mx = max(cur - 1, mx), st = false;
        else
            mx = max(cur / 2, mx);

        cur = 1;
    }
    else
        cur++;
}

return max(cur - 1, mx);
    }
};