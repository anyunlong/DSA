/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param head: a ListNode
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode * removeElements(ListNode * head, int val) {
        // write your code here
        
        if (head == NULL) {
            return NULL;
        }
        
        while (head->val == val) {
            head = head->next;
            if (head == NULL) {
                return NULL;
            }
        }
        
        ListNode *result = head;
        
        while (head->next != NULL) {
            if (head->next->val == val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        
        return result;
    }
};
