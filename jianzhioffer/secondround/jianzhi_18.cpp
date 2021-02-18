#include <cstddef>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

//单指针
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        else if(head->val==val)
            return head->next;
        ListNode* current = head;
        while (current->next!=NULL && current->next->val!=val)
        {
            current = current->next;
        }
        if(current!=NULL)
            current->next = current->next->next;
                
        return head;
    }
};

//双指针
// class Solution {
// public:
//     ListNode* deleteNode(ListNode* head, int val) {
//         if(head == NULL)
//             return NULL;
//         else if(head->val==val)
//             return head->next;
//         ListNode* current = head->next;
//         ListNode* previous = head;
//         while (current!=NULL)
//         {
//             if(current->val==val && current->next!=NULL)
//             {
//                 previous->next = current->next;
//                 break;
//             }
//             else
//                 previous = current;
//                 current = current->next;
//         }
//         return head;
//     }
// };

int main(int argc, char const *argv[])
{
    ListNode n1 = ListNode(4);
    ListNode n2 = ListNode(5);
    ListNode n3 = ListNode(1);
    ListNode n4 = ListNode(9);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    Solution obj;
    ListNode* result = obj.deleteNode(&n1, 5);
    return 0;
}
