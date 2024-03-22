class Solution {
public:
    void recur_letterCombinations(int curIdx, string digits, string sofar, vector<string>& results, unordered_map<int, vector<char>>& mp) {
    if (sofar.size() == digits.size()) {
        results.push_back(sofar);
        return;
    }

    for (auto ch : mp[digits[curIdx] - '0']) {
        sofar.push_back(ch);

        recur_letterCombinations(curIdx + 1, digits, sofar, results, mp);

        sofar.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> results;
    if (digits.empty())
        return results;
    
    unordered_map<int, vector<char>> mp;
    mp.insert({ 2, {'a','b','c'} });
    mp.insert({ 3, {'d','e','f'} });
    mp.insert({ 4, {'g','h','i'} });
    mp.insert({ 5, {'j','k','l'} });
    mp.insert({ 6, {'m','n','o'} });
    mp.insert({ 7, {'p','q','r','s'} });
    mp.insert({ 8, {'t','u','v'} });
    mp.insert({ 9, {'w','x','y','z'} });

    recur_letterCombinations(0, digits, "", results, mp);

    return results;
}
};