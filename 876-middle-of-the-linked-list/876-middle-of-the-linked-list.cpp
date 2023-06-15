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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* original_head = head;
        while (head) {
            count++;
            head = head->next;
        }
        int mid = (count/2);
        ListNode* mid_node = original_head;
        while (mid--) {
            mid_node = mid_node->next;
        }
        return mid_node;
    }
};