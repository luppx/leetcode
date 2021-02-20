#include <cstddef>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//快慢指针，快指针比慢指针先走k步，则快指针走到链表最后一个节点的下一个节点(NULL)时，慢指针指向倒数第k个节点
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < k; i++)
        {
            if(fast == NULL && i<k)  //如果快指针为空，说明链表长度小于k，不存在倒数第k个节点，返回NULL
                return NULL;
            fast = fast->next;

        }
        while (fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(int argc, char const *argv[])
{
    ListNode l1 = ListNode(1);
    ListNode l2 = ListNode(2);
    ListNode l3 = ListNode(3);
    ListNode l4 = ListNode(4);
    ListNode l5 = ListNode(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    Solution obj;
    ListNode* result = obj.getKthFromEnd(&l1, 5);
    return 0;
}
