#include <cstddef>
#include <vector>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//时间复杂度O(N)，空间复杂度O(N)(辅助数组存储遍历过的结点)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL; //空链表
        else if(head->next==NULL) return head;  //链表只有一个节点
        vector<ListNode*> tmp;
        while (head->next!=NULL)
        {
            tmp.push_back(head);
            head = head->next;
        }

        ListNode* current = head;
        while (!tmp.empty())
        {
            ListNode* node = tmp.back();
            tmp.pop_back();
            node->next = NULL;
            current->next = node;
            current = current->next;
        }
        
        return head;
    }
};

//优化，双指针法，分别记录当前结点的前一个结点和后一个结点。时间复杂度O(N)，空间复杂度O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL; //空链表
        else if(head->next==NULL) return head;  //链表只有一个节点
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current!=NULL)
        {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    
        return prev;
    }
};

int main(int argc, char const *argv[])
{
    ListNode l1 = ListNode(1);
    ListNode l2 = ListNode(2);
    ListNode l3 = ListNode(3);
    ListNode l4 = ListNode(4);
    ListNode l5 = ListNode(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    Solution obj;
    ListNode* result = obj.reverseList(&l1);
    return 0;
}