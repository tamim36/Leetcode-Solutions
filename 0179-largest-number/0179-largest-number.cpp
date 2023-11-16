class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
vector<string> nStr;

for (int i = 0; i < n; i++) {
    nStr.push_back(to_string(nums[i]));
}

sort(nStr.begin(), nStr.end(), [](const string s1, const string s2) {
    return s1 + s2 < s2 + s1;
    });
string ans = "";
        
for (int i = n - 1; i >= 0; i--) {
    
    ans += nStr[i];
}

return ans[0] == '0' ? "0" : ans;
    }
};