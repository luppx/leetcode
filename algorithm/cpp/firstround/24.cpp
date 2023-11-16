#include <cstddef>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* swapPairs(ListNode* head);
};

ListNode* Solution::swapPairs(ListNode* head)
{
	if(head==NULL || head->next==NULL) return head;
	ListNode* prev = head;
	ListNode* cur = head;
	ListNode* nx = head->next;
	
	cur->next = nx->next;
	nx->next = cur;
	head = nx;
	prev = cur;

	if(cur->next==NULL || cur->next->next==NULL) return head;
	cur = cur->next;
	nx = cur->next;
	
	while(cur!=NULL && nx!=NULL)
	{
		cur->next = nx->next;
		nx->next = cur;
		prev->next = nx;
		
		prev = cur;
		cur = cur->next;
		nx = (cur!=NULL || cur->next!=NULL) ? cur->next: NULL;
	}
	return head;
}

int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution obj;
	ListNode* result = obj.swapPairs(n1);
	return 0;

}

