struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x=0): val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head);
};

ListNode* Solution::deleteDuplicates(ListNode* head)
{
    if(head==nullptr || head->next==nullptr) return head;

    ListNode* prev = head;
    ListNode* cur = head->next;
    while (cur!=nullptr)
    {
        if(cur->val==prev->val)
        {
            prev->next = cur->next;
        }
        else
        {
            prev = cur;
        }
        cur = cur->next;
    }
    return head;
}

int main()
{
    return 0;
}