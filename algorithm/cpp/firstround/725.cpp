#include <cstddef>
#include <vector>
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
	vector<ListNode*> splitListToParts(ListNode* root, int k);
};

vector<ListNode*> Solution::splitListToParts(ListNode* root, int k)
{
        int length = 0;
        ListNode* cur = root;
        while(cur!=NULL)
        {   
                length++;
                cur = cur->next;
        }   
    
        int numOfParts = length/k;
        int rest = length%k;

        vector<ListNode*> res = {}; 
        cur = root;
        for(int i=0; i<k; i++)
        {   
                res.push_back(cur);
                for(int j=1; j<numOfParts; j++)
                {   
                        cur = cur->next;
                }   
    
                if(rest>0 && numOfParts>0)
                {   
                        cur = cur->next;
                        rest--;
                }   
                
                if(cur!=NULL)
                {
                    ListNode* prev = cur;
                    cur = cur->next;
                    prev->next = NULL;
                }
                
        }   
        return res;

}

int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	n1->next = n2;
	n2->next = n3;

	Solution obj;
	vector<ListNode*> result = obj.splitListToParts(n1, 5);

	return 0;
}


