#include <cstddef>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {};

};

class Solution
{
public:
    Solution();
    ~Solution();
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
};

Solution::Solution() {}

Solution::~Solution() {}

//时间复杂度O(M+N)，空间复杂度O(1)
ListNode* Solution::getIntersectionNode(ListNode* headA, ListNode* headB)
{
    if(headA==NULL || headB==NULL) return NULL;
    ListNode* curA = headA;
    ListNode* curB = headB;
    while (curA!=curB)
    {
        if(curA!=NULL) curA = curA->next;
        else curA = headB;

        if(curB!=NULL) curB = curB->next;
        else curB = headA;
    }
    return curA;
}


int main(int argc, char const *argv[])
{
    ListNode l11 = ListNode(4);
    ListNode l12 = ListNode(1);
    ListNode l21 = ListNode(5);
    ListNode l3 = ListNode(8);
    ListNode l4 = ListNode(4);
    l11.next = &l12;
    l12.next = &l3;
    // l21.next = &l3;
    l3.next = &l4;

    Solution obj;
    ListNode* result = obj.getIntersectionNode(&l11, &l21);
    return 0;
}
