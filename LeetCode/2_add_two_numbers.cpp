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

        ListNode* l3 = new ListNode(0);
        ListNode* temp = l3;
        int carry = 0;
        while(l1!=nullptr or l2!=nullptr or carry!=0){
            int a,b;
            (l1==nullptr) ? a = 0: a = l1->val;
            (l2==nullptr) ? b = 0: b = l2->val;
            int c = a+b+carry;
            cout << c<<"\n";
            carry = (c-c%10)/10;
            c = c%10;
            temp->next = new ListNode(c);
            temp = temp->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;

        }
        return l3->next;
    }
};