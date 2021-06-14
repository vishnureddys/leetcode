/*
25. Reverse Nodes in k-Group
Hard

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/
class Solution {
public:
    int getCount(ListNode *head){
        int count = 0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head == NULL || head->next == NULL || getCount(head) < k){
            return head;
        }
        
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        
        int count = 0;
        while(count < k && curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count ++;
        }
        
        head->next = reverseKGroup(next, k);
        return prev;
    }
};
