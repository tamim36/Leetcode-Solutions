class Solution {
public:
    char findTheDifference(string s, string t) {
        long long sbit = 0;

for (auto c : s)
    sbit ^= c;
for (auto c : t)
    sbit ^= c;

return sbit;
    }
};