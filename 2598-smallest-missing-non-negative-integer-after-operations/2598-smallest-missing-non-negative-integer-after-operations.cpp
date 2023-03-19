class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        set<int> s;
    long long mx = INT_MIN, mn = INT_MAX;
    unordered_map<int, long long> mp;

    for (auto num : nums) {
        long long posv = 0;
        if (num >= 0) posv = num % value;
        else {
            num %= value;
            //cout << num << endl;
            if (num < 0) { num += value; posv = num; }
        }

        if (s.count(posv) && value == 1) posv = mx + 1;

        int key = posv;
        if (s.count(posv)) posv = mp[posv] + value;
        while (s.count(posv))
        {
            posv += value;
        }
        mx = max(mx, posv);
        mn = min(mn, posv);
        //cout << "in  " << posv << endl;
        mp[key] = posv;
        s.insert(posv);
    }

    int prev = -1, cnt = 0;
    for (auto num : s) {
        if (++prev != num) return prev;
        cnt = num;
    }
    return ++cnt;
    }
};