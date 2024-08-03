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
        int count = 1;
        ListNode* head2 = head;
        while(head->next!=NULL){
            count++;
            head = head->next;
        }
        count = count/2;
        for(int i = 0;i<count;i++){
            head2 = head2->next;
        }
        return head2;
    }
};