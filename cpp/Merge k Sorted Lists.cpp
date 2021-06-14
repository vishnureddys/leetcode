/*
23. Merge k Sorted Lists
Hard
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
    k == lists.length
    0 <= k <= 10^4
    0 <= lists[i].length <= 500
    -10^4 <= lists[i][j] <= 10^4
    lists[i] is sorted in ascending order.
    The sum of lists[i].length won't exceed 10^4.
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }else if(l2 == NULL){
            return l1;
        }
        
        ListNode* result;
        
        if(l1->val <= l2->val){
            result = l1;
            result->next = mergeTwoLists(l1->next, l2);
        }
        else if(l1->val > l2->val){
            result = l2;
            result->next = mergeTwoLists(l1, l2->next);
        }
        
        return result;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 1){
            return lists[0];
        }
        else if(lists.size() == 0) {
            return NULL;
        }
        ListNode* result = mergeTwoLists(lists[0], lists[1]);
        for(int i = 2; i < lists.size(); i++) {
            result = mergeTwoLists(result, lists[i]);
        }
        return result;
    }
};
