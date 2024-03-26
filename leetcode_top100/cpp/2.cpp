#include <vector>
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
	ListNode*  addTwoNumbers(ListNode* l1, ListNode* l2);
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if(l1==NULL || l2==NULL) return NULL;
	ListNode* cur1=l1;
	ListNode* cur2=l2;
	
	ListNode* head3 = new ListNode(0);
	ListNode* cur3 = head3;
	
	int x=0; //表示产生进位
	while(cur1!=NULL && cur2!=NULL)
	{
		int sum = cur1->val + cur2->val + x;
		cur3->val = sum%10;
		x= sum>9 ? 1:0;
		
		if(cur1->next!=NULL && cur2->next!=NULL)
		{
			cur3->next = new ListNode(0);
			cur3 = cur3->next;
		}
		else if(cur1->next==NULL && cur2->next==NULL && x>0)
		{
			cur3->next = new ListNode(x);
		}
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	
	if(cur1!=NULL)
	{
		cur3->next = cur1;
		while(cur1!=NULL)
		{
			int sum = cur1->val + x;
			cur1->val = sum%10;
			x= sum>9 ? 1:0;
			if(cur1->next==NULL && x>0)
			{
				cur1->next = new ListNode(x);
				break;
			}
			else cur1 = cur1->next;
		}
	}
	else if(cur2!=NULL)
	{
		cur3->next = cur2;
		while(cur2!=NULL)
		{
			int sum = cur2->val + x;
			cur2->val = sum%10;
			x= sum>9 ? 1:0;
			if(cur2->next==NULL && x>0)
			{
				cur2->next = new ListNode(x);
				break;
			}
			else cur2 = cur2->next;
		}
	}
	return head3;
}

int main()
{
	ListNode* n11 = new ListNode(2);
	ListNode* n12 = new ListNode(4);
	ListNode* n13 = new ListNode(9);
	//ListNode* n14 = new ListNode(9);
	//ListNode* n15 = new ListNode(9);
	//ListNode* n16 = new ListNode(9);
	//ListNode* n17 = new ListNode(9);

	n11->next = n12;
	n12->next = n13;
	//n13->next = n14;
	//n14->next = n15;
	//n15->next = n16;
	//n16->next = n17;
	
	ListNode* n21 = new ListNode(5);
	ListNode* n22 = new ListNode(6);
	ListNode* n23 = new ListNode(4);
	ListNode* n24 = new ListNode(9);

	n21->next = n22;
	n22->next = n23;
	n23->next = n24;

	Solution obj;
	ListNode* result = obj.addTwoNumbers(n11, n21);
	return 0;
}
