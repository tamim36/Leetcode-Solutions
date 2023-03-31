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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
        return head;
    ListNode* cur = head;
    ListNode* rev = head;
    ListNode* temp = head;
    cur = cur->next;
    temp->next = NULL;
    
    while (cur)
    {
        rev = cur;
        cur = cur->next;
        rev->next = temp;
        temp = rev;
    }

    return rev;
    }
};