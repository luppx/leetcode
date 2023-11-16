#include <iostream>
#include <string>
#include <stdio.h>
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
    ListNode *detectCycle(ListNode *head);
};

ListNode* Solution::detectCycle(ListNode *head)
{
    if(head==nullptr || head->next==nullptr) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast) break;
    }

    if(fast==nullptr || fast->next==nullptr) return nullptr;

    ListNode* p1 = head;
    ListNode* p2 = slow;
    while (p1!=p2)
    {
        p1=p1->next;
        p2=p2->next;
    }

    return p1;
}

int main()
{
    return 0;
}