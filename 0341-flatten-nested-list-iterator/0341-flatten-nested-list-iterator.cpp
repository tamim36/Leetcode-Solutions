/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<vector<NestedInteger>::iterator> beginStk, endStk;

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        beginStk.push(nestedList.begin());
        endStk.push(nestedList.end());
    }

    int next() {
        hasNext();
        return (beginStk.top()++)->getInteger();
    }

    bool hasNext() {
        while (!beginStk.empty()) {
            if (beginStk.top() == endStk.top()) {
                beginStk.pop(), endStk.pop();
            }
            else {
                auto x = beginStk.top();
                if (x->isInteger())
                    return true;
                beginStk.top()++;
                beginStk.push(x->getList().begin());
                endStk.push(x->getList().end());
            }
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */