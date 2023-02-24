/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ansList = new ListNode(-100001);

    for (int i = 0; i < lists.size(); i++) {
        ListNode* ansHead = ansList;
        ListNode* cur = lists[i];

        while (cur) {
            // for the rest of the nodes
            if (!ansHead->next) {
                ansHead->next = cur;
                break;
            }
            // for middle nodes
            else if (cur->val <= ansHead->next->val){
                auto temp = ansHead->next;
                ansHead->next = cur;
                cur = cur->next;
                ansHead->next->next = temp;
                ansHead = ansHead->next;
            }
            else {
                ansHead = ansHead->next;
            }
        }
    }
    return ansList->next;
    }
};