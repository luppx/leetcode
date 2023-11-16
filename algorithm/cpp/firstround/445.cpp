#include <stack>
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
        Solution(): s1(), s2() {}; 
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
private:
        stack<int> s1, s2; 
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) 
{
        if(l1==NULL) return l2; 
        else if(l2==NULL) return l1; 

        ListNode* cur1=l1;
        ListNode* cur2=l2;
        while(cur1!=NULL)
        {   
                s1.push(cur1->val);
                cur1= cur1->next;
        }

        while(cur2!=NULL)
        {
            s2.push(cur2->val);
            cur2 = cur2->next;
        }

        int carry = 0;
        ListNode* head = NULL;
        while(!s1.empty() && !s2.empty())
        {
                int sum = s1.top()+s2.top()+carry;
                s1.pop();
                s2.pop();

                ListNode* node = new ListNode(sum%10);
                carry = sum/10;

                node->next = head;
                head = node;
        }

        while(!s1.empty())
        {
                int sum = s1.top()+carry;
                s1.pop();

                ListNode* node = new ListNode(sum%10);
                carry = sum/10;

                node->next = head;
                head = node;
        }

        while(!s2.empty())
        {
                int sum = s2.top()+carry;
                s2.pop();

                ListNode* node = new ListNode(sum%10);
                carry = sum/10;

                node->next = head;
                head = node;
        }

        if(carry>0)
        {
                ListNode* node = new ListNode(carry);
                node->next = head;
                head = node;
        }
        return head;
}

int main()
{
	return 0;
}


