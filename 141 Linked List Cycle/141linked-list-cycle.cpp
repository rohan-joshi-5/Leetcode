/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)   return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast!=NULL && fast->next!=NULL) {
            slow=slow->next;          // Moves 1 steps
            fast=fast->next->next;    // Moves 2 stepppp
            if (slow == fast) return true;
        }
        return false;
    }
};