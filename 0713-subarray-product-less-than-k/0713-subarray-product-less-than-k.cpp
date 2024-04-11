class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long preProd = 1;
int cnt = 0, n = nums.size();

for (int i = 0, j = 0; i < n; i++) {
    while (j < i && preProd * nums[i] >= k){
        preProd /= nums[j++];
        if (preProd == 0) preProd = 1;
    }
        
    if (i < n && preProd * nums[i] < k) {
        cout << i << " : "  << j << endl;
        cnt += (i - j + 1);
        preProd *= nums[i];
    }
    else 
        j++;
    
    
}

return cnt;
    }
};