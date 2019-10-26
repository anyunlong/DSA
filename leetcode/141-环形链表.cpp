/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while (fast != slow) {
        slow = slow->next;
        if (fast->next == NULL) {
            return false;
        } else {
            fast = fast->next;
        }
        if (fast->next == NULL) {
            return false;
        } else {
            fast = fast->next;
        }
    }
    return true;
}
