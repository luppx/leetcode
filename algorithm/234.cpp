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
	bool isPalindrome(ListNode* head);

private:
	ListNode* FindEndOfFirstHalf(ListNode* head);
	ListNode* ReverseList(ListNode* head);
};

bool Solution::isPalindrome(ListNode* head)
{
	if(head==NULL || head->next==NULL) return true;

	ListNode* FirstHalfEnd = FindEndOfFirstHalf(head);
	ListNode* LastHalfHead = ReverseList(FirstHalfEnd->next);  //上一条语句已经找到了后半部分的头节点，这里把后半部分的链表反转，这样就可以比较前半部分和后半部分是否相同了，比较结束之后再把后半部分反转回来，以不改变原链表的结构

	ListNode* cur1 = head;
	ListNode* cur2 = LastHalfHead;
	bool res = true;
	
	while(cur2!=NULL)
	{
		if(cur1->val!=cur2->val)
		{
			res = false;
			break;
		}
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	LastHalfHead = ReverseList(LastHalfHead); //将后半部分链表反转回来，以不改变原链表的结构

	return res;
}

ListNode* Solution::FindEndOfFirstHalf(ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;

	while(fast->next!=NULL && fast->next->next!=NULL) //如果链表长度为奇数，则循环结束时slow指向最中间的节点，即前一半比后一半多一个节点；若为偶数，则指向前一半的尾节点。
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

ListNode* Solution::ReverseList(ListNode* head)
{
	ListNode* prev = NULL;
	while(head!=NULL)
	{
		ListNode* node = head->next;
		head->next = prev;
		prev = head;
		head = node;
	}
	return prev;
}

int main()
{
	return 0;
}

