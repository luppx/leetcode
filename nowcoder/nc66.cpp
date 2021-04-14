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
    ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2);
};

ListNode* Solution::FindFirstCommonNode(ListNode* h1, ListNode* h2)
{
    if(h1==nullptr) return h1;
    else if(h2==nullptr) return h2;

    ListNode* cur1 = h1;
    ListNode* cur2 = h2;
    while (cur1!=cur2)
    {
        if(cur1==nullptr) cur1 = h2;
        else cur1 = cur1->next;

        if(cur2==nullptr) cur2 = h1;
        else cur2 = cur2->next;
    }
    return cur1;
}

int main()
{
    return 0;
}