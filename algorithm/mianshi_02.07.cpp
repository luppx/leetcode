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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
};

ListNode* Solution::getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if(headA==nullptr || headB==nullptr) return nullptr;

    ListNode* curA = headA;
    ListNode* curB = headB;

    bool bianliA = false;
    bool bianliB = false;

    while (curA!=nullptr || curB!=nullptr)
    {
        if (curA==curB)
        {
            return curA;
        }
        
        curA = curA->next;
        curB = curB->next;

        if (curA==nullptr && bianliA==false)
        {
            curA = headB;
            bianliA = true;
        }
        
        if (curB==nullptr && bianliB==false)
        {
            curB = headA;
            bianliB = true;
        }        
    }
    return nullptr;
}

int main()
{
    return 0;
}