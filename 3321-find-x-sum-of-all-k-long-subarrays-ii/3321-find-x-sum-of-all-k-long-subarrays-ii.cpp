class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> freq;
vector<long long> ans;
set<pair<long long, int>, greater<pair<long long, int>>> top, bottom;
long long xsum = 0;

for (int i = 0; i < nums.size(); i++) {
    long long cnt = freq[nums[i]];
    if (cnt) {
        if (auto it = bottom.find({ cnt, nums[i] }); it != end(bottom))
            bottom.erase(it);
        else {
            top.erase({cnt, nums[i]});
            xsum -= (cnt * nums[i]);
        }
    }

    freq[nums[i]]++;
    top.insert({ cnt + 1, nums[i] });
    xsum += ((cnt + 1) * nums[i]);

    if (top.size() > x) {
        auto it_top = prev(end(top));
        xsum -= (it_top->first * it_top->second);
        bottom.insert({it_top->first, it_top->second});
        top.erase(it_top);
    }

    if (i >= k) {
        cnt = freq[nums[i - k]];
        if (auto it = bottom.find({ cnt, nums[i-k] }); it != end(bottom))
            bottom.erase(it);
        else {
            it = top.find({cnt, nums[i - k] });
            xsum -= (it->first * it->second);
            top.erase(it);
        }

        if (cnt > 1)
            bottom.insert({cnt - 1, nums[i-k]});

        --freq[nums[i - k]];
        if (top.size() < x) {
            if (auto it = begin(bottom); it != end(bottom)) {
                xsum += (it->first * it->second);
                top.insert({it->first, it->second});
                bottom.erase(it);
            }
        }

    }
    
    if (i + 1 >= k)
        ans.push_back(xsum);
}

return ans;
    }
};