class Solution {
public:
    bool isvalidIpAddress(string address, int idx, int sofarCnt, int tot_sz) {
    if (address.size() == 0) return false;
    if (((4 - sofarCnt) * 3) < (tot_sz - idx)) return false;

    if (address.size() > 1 && address[0] == '0') return false;
    //cout << address << endl;
    int val = stoi(address);
    if (val > 255) return false;
    return true;
}

string vectorToIpAddress(vector<string> sofar) {
    string ipAddress = "";
    int row = 0;
    while (row < sofar.size()) {
        for (int i = 0; i < sofar[row].size(); i++) {
            ipAddress.push_back(sofar[row][i]);
        }

        row++;
        if (row < sofar.size())
            ipAddress.push_back('.');
    }
    return ipAddress;
}

void recur_restoreIpAddresses(int curIdx, string s, vector<string>& sofar, vector<string>& results) {
    if (curIdx == s.size() && sofar.size() == 4) {
        string ipAddress = vectorToIpAddress(sofar);
        results.push_back(ipAddress);
        return;
    }
    if (sofar.size() == 4) return;

    for (int i = curIdx; i < curIdx + 3 && i < s.size(); i++) {
        string newstr = s.substr(curIdx, i - curIdx + 1);
        if (!isvalidIpAddress(newstr, i + 1, sofar.size() + 1, s.size()))
            continue;
        //cout << newstr << endl;
        sofar.push_back(newstr);
        recur_restoreIpAddresses(i + 1, s, sofar, results);
        sofar.pop_back();
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> results, sofar;
    recur_restoreIpAddresses(0, s, sofar, results);
    return results;
}
};