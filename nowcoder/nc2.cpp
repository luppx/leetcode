#include <vector>
#include <cstddef>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution
{
public:
    void reorderList(ListNode* head);
};

// //使用辅助数组，时间复杂度O(N)，空间复杂度O(N)
// void Solution::reorderList(ListNode* head)
// {
//     if(head==nullptr || head->next==nullptr) return;

//     vector<ListNode*> v;
//     ListNode* cur = head;
//     while (cur!=nullptr)
//     {
//         v.push_back(cur);
//         cur = cur->next;
//     }
//     if(v.size()<3) return ;

//     int i=0, j=v.size()-1;
//     while (i<j-1)
//     {
//         v[i]->next = v[j];
//         v[j]->next = v[i+1];
//         v[j-1]->next = nullptr;
//         i++;
//         j--;
//     }
//     return ;
// }

//原地算法。1.快慢指针将链表分为2个短链表；2.反转第二个链表；3.将第二个链表依次插入到第一个链表中
//时间复杂度O(N)，空间复杂度O(1)
void Solution::reorderList(ListNode* head)
{
    if(head==nullptr || head->next==nullptr) return;

    //1.将链表一分为二
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* head2 = slow->next;
    slow->next = nullptr;

    //2.反转第二个链表
    ListNode* prev = nullptr;
    ListNode* cur = head2;
    ListNode* nxt = nullptr;
    while (cur!=nullptr)
    {
        nxt = cur->next;
        cur->next = prev;

        prev = cur;
        cur = nxt;
    }
    head2 = prev;

    //3.将第二个链表插入到第一个链表中
    ListNode* cur1 = head;
    ListNode* cur2 = head2;
    ListNode* nxt1 = nullptr;
    ListNode* nxt2 = nullptr;
    while (cur2!=nullptr)
    {
        nxt1 = cur1->next;
        nxt2 = cur2->next;

        cur1->next = cur2;
        cur2->next = nxt1;

        cur1 = nxt1;
        cur2 = nxt2;
    }

    return ;
}

int main()
{
    return 0;
}