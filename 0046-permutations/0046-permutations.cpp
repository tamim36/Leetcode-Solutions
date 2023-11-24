class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int sz = nums.size();
vector<vector<int>> ans;
if (sz <= 1) {
    ans.push_back(nums);
    return ans;
}

vector<int> vec;
vec.push_back(nums[0]);
ans.push_back(vec);


for (int i = 1; i < sz; i++) {
    vector<vector<int>> tmp;
    while (!ans.empty()){
        auto v = ans.back();
        ans.pop_back();

        for (int j = 0; j <= i; j++) {
            vector<int> vt(v);
            vt.insert(vt.begin() + j, nums[i]);
            tmp.push_back(vt);
        }
    }
    ans = tmp;
}

return ans;
    }
};