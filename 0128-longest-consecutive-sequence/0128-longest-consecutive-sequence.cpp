class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
for (auto num : nums)
    st.insert(num);

int mxLen = 0;
for (auto num : nums) {
    if (st.count(num)) {
        int cnt = 1;
        int n1 = num, n2 = num;
        while (st.count(--n1)) {
            st.erase(n1);
            cnt++;
        }

        while (st.count(++n2)) {
            st.erase(n2);
            cnt++;
        }

        mxLen = max(mxLen, cnt);
    }
}

return mxLen;
    }
};