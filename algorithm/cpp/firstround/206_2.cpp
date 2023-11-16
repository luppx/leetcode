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
    ListNode* reverseList(ListNode* head);
};

ListNode* Solution::reverseList(ListNode* head)
{
    if(head==nullptr || head->next==nullptr) return head;

    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur!=nullptr)
    {
        ListNode* tmp = cur;
        cur = cur->next;
        tmp->next = prev;
        prev = tmp;
    }
    return prev;
}

int main()
{
    return 0;
}