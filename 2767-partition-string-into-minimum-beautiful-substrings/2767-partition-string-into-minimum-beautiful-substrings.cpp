class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        vector<string> pats{ "11110100001001", "110000110101", "1001110001", "1111101", "11001", "101", "1"};
    int cnt = 0;

    for (int i = 0; i < pats.size(); i++) {
        while (true) {
            size_t pos = s.find(pats[i]);

            if (pos != string::npos && (pos == 0 || s[pos-1] != '0')) {
                s.replace(s.find(pats[i]), pats[i].length(), "2");
                cnt++;
            }
            else 
                break;
        }
    }
    for (auto c : s)
        if (c == '0')
            return -1;

    return cnt == 0 ? -1 : cnt;
    }
};