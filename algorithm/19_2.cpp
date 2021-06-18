#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x=0): val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
};

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    ListNode* dummyhead = new ListNode(0);
    dummyhead->next = head;
    ListNode* prev = dummyhead;
    ListNode* fast = head;
    ListNode* slow = head;

    for (int i = 0; i < n; i++)
    {
        if (fast==nullptr)
        {
            return head;
        }
        fast = fast->next;
    }
    
    while (fast!=nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = slow->next;
    head = dummyhead->next;
    delete dummyhead;
    return head;
}

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    
    int n = 2;
    
    Solution obj;
    ListNode* result = obj.removeNthFromEnd(n1, 2);
    return 0;
}