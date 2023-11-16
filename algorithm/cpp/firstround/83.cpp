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
	ListNode* deleteDuplicates(ListNode* head);
};

ListNode* Solution::deleteDuplicates(ListNode* head)
{
	if(head==NULL || head->next==NULL) return head;
	ListNode* cur=head;
	while(cur!=NULL && cur->next!=NULL)
	{
		if(cur->val==cur->next->val)
		{
			cur->next = cur->next->next;
		}
		else cur = cur->next;
	}
	return head;
}

int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(1);
	ListNode* n3 = new ListNode(2);
	ListNode* n4 = new ListNode(3);
	ListNode* n5 = new ListNode(3);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution obj;
	ListNode* result = obj.deleteDuplicates(n1);
	return 0;

}


