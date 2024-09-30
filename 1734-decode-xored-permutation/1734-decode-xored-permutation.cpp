class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int sz = encoded.size();
        vector<int> ans(sz + 1);
        if (sz < 2)
            return ans;

        int tot_xor_a = 0;

        for (int i = 0; i < sz; i++) {
            tot_xor_a ^= i + 1;
            if (i % 2)
                tot_xor_a ^= encoded[i];
        }

        int ini_val = tot_xor_a ^ (sz + 1);
        ans[0] = ini_val;

        for (int i = 1; i < sz + 1; i++) {
            ans[i] = ans[i - 1] ^ encoded[i - 1];
        }

        return ans;
    }
};