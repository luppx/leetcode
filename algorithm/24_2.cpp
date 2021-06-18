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
    ListNode* swapPairs(ListNode* head);
};

ListNode* Solution::swapPairs(ListNode* head)
{
    if(head==nullptr || head->next==nullptr) return head;

    ListNode* dummyhead = new ListNode(0);
    dummyhead->next = head;
    ListNode* cur = dummyhead;
    ListNode* nextNode = nullptr;
    ListNode* tmp = nullptr;

    while (cur->next!=nullptr && cur->next->next!=nullptr)
    {
        nextNode = cur->next;
        tmp = cur->next->next->next;
        
        cur->next = cur->next->next;
        cur->next->next = nextNode;
        nextNode->next = tmp;
        cur = nextNode;
    }
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
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    Solution obj;
    ListNode* result = obj.swapPairs(n1);
    return 0;
}