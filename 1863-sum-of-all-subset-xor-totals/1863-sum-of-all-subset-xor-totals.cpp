class Solution {
public:
        int xorSumSubsetCount = 0;
void getSubsetsXORSum(int curIdx, vector<int>& sofar, vector<int>& nums) {
    int curTotal = 0;
for (int i = 0; i < sofar.size(); i++)
    curTotal = (curTotal ^ sofar[i]);

xorSumSubsetCount += curTotal;
    for (int i = curIdx; i < nums.size(); i++) {
        sofar.push_back(nums[i]);
        getSubsetsXORSum(i + 1, sofar, nums);
        sofar.pop_back();
    }
}

int subsetXORSum(vector<int>& nums) {
    vector<int> sofar;
    getSubsetsXORSum(0, sofar, nums);
    return xorSumSubsetCount;
}
};