class Solution {
public:
    string addBinary(string a, string b) {
       int carry = 0;
string res = "";
int minLen = min(a.size(), b.size());
int i = a.size() - 1, j = b.size() - 1;

for (; i >= 0 || j >= 0; i--, j--) {
    int ai = i >= 0 ? a[i] - '0' : 0;
    int bi = j >= 0 ? b[j] - '0' : 0;

    int r = 0;
    if (ai && bi) {
        if (carry)
            r = 1;
        else
            carry = 1;
    }
    else if (ai || bi) {
        if (!carry) {
            r = 1;
            carry = 0;
        }
    }
    else {
        if (carry) {
            r = 1;
            carry = 0;
        }
    }

    res.push_back(r + '0');
}

if (carry)
    res.push_back('1');

reverse(res.begin(), res.end());
return res;
    }
};