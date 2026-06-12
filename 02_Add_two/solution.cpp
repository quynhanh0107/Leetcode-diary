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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* current = dummy_head;
        int carry = 0;

        // the loop will continue as long as:
        // both lists are not exhausted
        // and there's still carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int total = val1 + val2 + carry;

            carry = total / 10;

            int new_digit = total % 10;

            current->next = new ListNode(new_digit);
            current = current->next;

            // move to the next node if there exists
            if (l1 != nullptr) {
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                l2 = l2->next;
            }

        }
        ListNode* result = dummy_head->next;
        delete dummy_head;

        return result;
    }
};