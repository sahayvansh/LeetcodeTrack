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
    bool hasCycle(ListNode *head) {
        // Check for edge cases where the list is empty or has only one node
        if (head == NULL || head->next == NULL)
            return false;
        
        // Initialize two pointers
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Traverse the list with two pointers
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;        // Slow pointer moves one step
            fast = fast->next->next;  // Fast pointer moves two steps
            
            // If slow and fast pointers meet, there is a cycle
            if (slow == fast)
                return true;
        }
        
        // If the loop completes, there is no cycle
        return false;
    }
};