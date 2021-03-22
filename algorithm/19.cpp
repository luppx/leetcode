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
        ListNode* removeNthFromEnd(ListNode* head, int n); 
};

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
        if(head==NULL || n<0) return head;
        else if(head->next==NULL && n>0) return NULL;
    
        ListNode* fast = head;
        for(int i=0; i<n; i++)
        {   
                fast = fast->next;
        }   

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
	ListNode* slow = dummy;

        while(fast!=NULL)
        {   
                fast = fast->next;
                slow = slow->next;
        }   
        slow->next = slow->next->next;
        return dummy->next;
}

int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	
	Solution obj;
	ListNode* result = obj.removeNthFromEnd(n1, 2);
	return 0;
}

