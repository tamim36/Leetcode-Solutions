class Solution {
public:
    void iterative_generateParenthesis(int n, vector<string>& results, unordered_set<string>& st) {
    int curIdx = 1;

    queue<string> sofar;
    sofar.push("()");
    string parenthesis = "()";
    while (curIdx < n){
        int sz = sofar.size();
        for (int i = 0; i < sz; i++) {
            string cur_pt = sofar.front(); sofar.pop();

            for (int j = 0; j < cur_pt.size(); j++) {
                string new_pt = cur_pt; 
                new_pt.insert(j, parenthesis);
                if (!st.count(new_pt)) {
                    sofar.push(new_pt);
                    st.insert(new_pt);

                    if (new_pt.size() == n * 2) {
                        results.push_back(new_pt);
                    }
                }
            }
        }

        curIdx++;
    }

}

vector<string> generateParenthesis(int n) {
    if (n == 1)
        return { "()" };

    vector<string> results;
    unordered_set<string> st;
    iterative_generateParenthesis(n, results, st);

    return results;
}
};