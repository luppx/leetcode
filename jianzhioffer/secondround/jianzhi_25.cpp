#include <cstddef>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL) return NULL;
        else if(l1==NULL && l2!=NULL) return l2;
        else if(l1!=NULL && l2==NULL) return l1;

        ListNode* head = new ListNode(-1);
        ListNode* current = head;
        while (l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        current->next = l1 ? l1:l2;
        return head->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode l1 = ListNode(1);
    ListNode l2 = ListNode(2);
    ListNode l3 = ListNode(4);
    ListNode l4 = ListNode(1);
    ListNode l5 = ListNode(3);
    ListNode l6 = ListNode(4);
    l1.next = &l2;
    l2.next = &l3;

    l4.next = &l5;
    l5.next = &l6;

    Solution obj;
    ListNode* result = obj.mergeTwoLists(&l1, &l4);
    return 0;
}