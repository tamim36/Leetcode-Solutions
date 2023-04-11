class Solution {
public:
    long long getDistanceVal(vector<long long>& prefixSum, int i, unordered_map<int, int>& index_map) {
    if (prefixSum.size() == 1)
        return 0ll;

    int prefixInd = index_map[i] + 1;
    long long preVal = 0;
    if (prefixInd)
        preVal = ( (i*1ll) * (prefixInd * 1ll) ) - prefixSum[prefixInd-1];

    int rem_sz = prefixSum.size() - prefixInd;
    long long postVal = prefixSum[prefixSum.size()-1] - prefixSum[prefixInd-1] - ( (i*1ll) * (rem_sz * 1ll));

    return preVal + postVal;
}
    
    vector<long long> getDistances(vector<int>& nums) {
         // prefix-sum
    unordered_map<int, vector<long long>> mp;
    unordered_map<int, int> in_pre;

    for (int i = 0; i < nums.size(); i++) {
        int sz = mp[nums[i]].size();
        long long val = 0; 
        if (!mp[nums[i]].empty())
            val = mp[nums[i]][sz - 1];

        mp[nums[i]].push_back(val + i*1ll);
        in_pre[i] = sz;
    }

    vector<long long> ansVec;
    for (int i = 0; i < nums.size(); i++) {
        ansVec.push_back(getDistanceVal(mp[nums[i]], i, in_pre));
    }

    return ansVec;
    }
};