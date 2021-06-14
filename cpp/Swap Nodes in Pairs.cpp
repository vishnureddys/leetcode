/*
24. Swap Nodes in Pairs
Medium

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Constraints:

    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        // We are creating a dummy node here to make it the first node. 
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *current = dummy;
        
        while(current->next && current->next->next) {
            ListNode *first = current->next;
            ListNode *second = current->next->next;
            
            first->next = second->next;
            second->next = first;
            current->next = second;
            current = current->next->next;
        }
        
        return dummy->next;
        
    }
};
