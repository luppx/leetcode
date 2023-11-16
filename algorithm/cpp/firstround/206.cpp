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
	ListNode* reverseList(ListNode* head);
};

ListNode* Solution::reverseList(ListNode* head)
{
	if(head==NULL || head->next==NULL) return head;
	ListNode* cur = head;
	vector<ListNode*> tmp = {};
	
	while(cur!=NULL)
	{
		tmp.push_back(cur);
		cur=cur->next;
	}
	
	ListNode* head2 = tmp.back();
	cur = head2;
	tmp.pop_back();
	

	while(!tmp.empty())
	{
		ListNode* node = tmp.back();
		tmp.pop_back();
		cur->next = node;
		node->next = NULL;
		cur=cur->next;
	}
	return head2;
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
	ListNode* result = obj.reverseList(n1);
	return 0;

}
