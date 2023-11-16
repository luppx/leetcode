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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if(l1==NULL) return l2;
	else if(l2==NULL) return l1;

	//ListNode* head = l1->val<=l2->val ? l1: l2;
	ListNode* head = new ListNode(-1);
	ListNode* cur = head;

	ListNode* cur1 = l1;
	ListNode* cur2 = l2;

	while(cur1!=NULL && cur2!=NULL)
	{	
		if(cur1->val<=cur2->val)
		{
			//ListNode* next1 = cur1->next;
			cur->next = cur1;
			cur1 = cur1->next;
		}
		else
		{
			//ListNode* next2 = cur2->next;
			cur->next = cur2;
			cur2 = cur2->next;
		}
		cur = cur->next;
	}

	if(cur1!=NULL) cur->next = cur1;
	if(cur2!=NULL) cur->next = cur2;
	return head->next;
}

int main()
{
	ListNode* n11 = new ListNode(1);
	ListNode* n12 = new ListNode(3);
	ListNode* n13 = new ListNode(5);
	
	ListNode* n21 = new ListNode(1);
	ListNode* n22 = new ListNode(2);
	ListNode* n23 = new ListNode(6);
	ListNode* n24 = new ListNode(7);

	n11->next = n12;
	n12->next = n13;
	n21->next = n22;
	n22->next = n23;
	n23->next = n24;

	Solution obj;
	ListNode* result = obj.mergeTwoLists(n11, n21);
	return 0;
}


