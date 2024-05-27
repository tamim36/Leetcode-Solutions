class Solution {
public:
    string toHex(int b) {
        long long num = b;
        if (num == 0)
    return "0";
int xor_val = 0;
        long long c = pow(2, 32) - 1;
if (num < 0) {
    num *= -1;
    c ^= num;
    c += 1;
    num = c;
}

string hex = "0123456789abcdef";
string res = "";
int rem = 0;
while (num) {
    rem = num % 16;
    res += hex[rem];
    num /= 16;
}

reverse(res.begin(), res.end());
return res;
    }
};