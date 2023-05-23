class Solution {
public:
    bool recur_PunishmentNumber(string str, int target) {
    if (str == "" && target == 0) return true;
    else if (target < 0) return false;

    bool ans = false;

    for (int i = 0; i < str.size(); i++) {
        string left = str.substr(0, i+1);
        string right = str.substr(i+1);
        int num = stoi(left);

        if (recur_PunishmentNumber(right, target - num)) {
            ans = true;
            break;
        }
    }

    return ans;
}

int punishmentNumber(int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        int val = i * i;
        if (recur_PunishmentNumber(to_string(val), i)) {
            sum += val;
        }
    }

    return sum;
}
};