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
    ListNode* removeElements(ListNode* head, int val);
};

ListNode* Solution::removeElements(ListNode* head, int val)
{
    if(head==nullptr) return head;
    
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* cur = head;
    while (cur!=nullptr)
    {
        if(cur->val==val)
        {
            prev->next = cur->next;
        }
        else
        {
            prev = cur;           
        }
        cur = cur->next;
    }
    
    head = dummy->next;
    delete dummy;
    return head;
}

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    n1->next = n2;
    int val = 1;
    Solution obj;
    ListNode* result = obj.removeElements(n1, val);
    ListNode* cur=result;
    while (cur->next!=nullptr)
    {
        cout<<cur->val<<"->";
        cur = cur->next;
    }
    cout<<cur->val<<endl;
    return 0;
}