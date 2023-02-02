class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> oDict(26, 0);

    for (int i = 0; i < order.size(); i++) 
        oDict[order[i] - 'a'] = i;

    for (int i = 1; i < words.size(); i++) {
        string a = words[i - 1], b = words[i];
        for (int j = 0; j < a.size(); j++) {
            if (j >= b.size()) 
                return false;
            if (a[j] != b[j]) {
                if (oDict[a[j] - 'a'] > oDict[b[j] - 'a'])
                    return false;
                else
                    break;
            }
        }
    }

    return true;
    }
};