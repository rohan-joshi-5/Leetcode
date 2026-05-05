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
    ListNode* rotateRight(ListNode* head, int k) {
        // 1. Handle edge cases
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 2. Calculate length and find the tail node
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 3. Optimize k
        k = k % length;
        if (k == 0) return head;

        // 4. Form a circular list
        tail->next = head;

        // 5. Find the new tail: it is at (length - k) position
        ListNode* new_tail = head;
        for (int i = 0; i < length - k - 1; i++) {
            new_tail = new_tail->next;
        }

        // 6. Break the circle
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;

        return new_head;
    }
};