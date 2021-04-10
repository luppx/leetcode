#include <iostream>
#include <cstddef>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
};

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    if(n<1) return head;
    
    ListNode* fast = head;
    for (int i = 0; i < n-1; i++)
    {
        if(fast==NULL) break;
        fast = fast->next;
    }
    if(fast==NULL) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* slow = head;
    while (fast->next!=NULL)
    {
        prev = prev->next;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = slow->next;
    prev = dummy->next;
    delete dummy;
    return prev;
}

int main()
{
    return 0;
}