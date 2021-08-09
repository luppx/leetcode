//每隔K个数反转一次链表，leetcode原题：lc25

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v=0):val(v), next(nullptr) {}
};

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k);
};

ListNode* Solution::reverseKGroup(ListNode* head, int k)
{
    if(head==nullptr || head->next==nullptr) return head;
    
    ListNode* dummyHead = new ListNode(-1);
    dummyHead->next = head;
    
    ListNode* prev = nullptr;
    ListNode* cur = head;
    ListNode* next = nullptr;
    ListNode* prevLast = dummyHead;
    ListNode* curFirst = head;
    int count = 0;
    
    while(cur!=nullptr)
    {
        if(count==0)
        {
            curFirst = cur;
        }
        count++;
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        if(count==k)
        {
            prevLast->next = prev;
            prevLast = curFirst;
            prev = nullptr;
            count = 0;
        }
    }

    if(count<k) prevLast->next = reverseKGroup(prev, count);
    
    head = dummyHead->next;
    delete dummyHead;
    return head;
}

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    int k = 2;

    Solution obj;
    ListNode* result = obj.reverseKGroup(n1, k);

    return 0;
}