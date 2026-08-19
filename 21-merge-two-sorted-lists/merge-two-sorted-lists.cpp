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
 // checking push to Github
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val) {
                ptr->next = list1;
                ptr = list1;

                list1 = list1->next;
            }
            else {
                ptr->next = list2;
                ptr = list2;

                list2 = list2->next;
            }
        } 

        if(list1) {
            while(list1) {
                ptr->next = list1;
                ptr = list1;

                list1 = list1->next;
            }
        }
        else {
            while(list2) {
                ptr->next = list2;
                ptr = list2;

                list2 = list2->next;
            }
        }

        return head->next;
        
    }
};