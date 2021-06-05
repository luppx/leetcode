#include <iostream>
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if(l1==nullptr) return l2;
	else if(l2==nullptr) return l1;

	ListNode* l = new ListNode(0);
	int carry = 0;
	ListNode* cur1 = l1;
	ListNode* cur2 = l2;
	ListNode* cur = l;
	
	while(cur1!=nullptr && cur2!=nullptr)
	{
		int num = cur1->val + cur2->val + carry;
		ListNode* node = new ListNode(num%10);
		carry = num/10;

		cur->next = node;
		cur = cur->next;
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	while(cur1!=nullptr)
	{
		if(carry)
		{
			int num = cur1->val + carry;
			ListNode* node = new ListNode(num%10);
			carry = num/10;

			cur->next = node;
			cur = cur->next;
			cur1 = cur1->next;
		}
		else
		{
			cur->next = cur1;
			break;
		}
	}

	while(cur2!=nullptr)
	{
		if(carry)
		{
			int num = cur2->val + carry;
			ListNode* node = new ListNode(num%10);
			carry = num/10;

			cur->next = node;
			cur = cur->next;
			cur2 = cur2->next;
		}
		else
		{
			cur->next = cur2;
			break;
		}
	}
	
	if(carry)
	{
	       	ListNode* node = new ListNode(carry);
		cur->next = node;
	}
	
	ListNode* head = l->next;
	delete l;
	return head;
}

int main()
{
	return 0;
}
