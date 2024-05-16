class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int bit_num = ceil(log2(n + 1));
int all_one = pow(2, bit_num) - 1;
int xor_val = all_one ^ n;
       // cout << "Bit_Num: " << bit_num << " all_one: " << all_one << endl;
return xor_val;
    }
};