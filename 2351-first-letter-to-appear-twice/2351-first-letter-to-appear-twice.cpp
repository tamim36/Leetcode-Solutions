class Solution {
public:
    char repeatedCharacter(string s) {
        int appear = 0;
for (auto c : s) {
    int mask = (1 << (c - 'a'));
    if (appear & mask)
        return c;
    appear |= mask;
}

return '0';
    }
};