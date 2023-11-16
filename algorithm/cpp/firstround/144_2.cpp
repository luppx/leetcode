#include <vector>
#include <stack>
#include <cstddef>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root);
};

vector<int> Solution::preorderTraversal(TreeNode* root)
{
	if(root==NULL) return {};
	vector<int> res = {};
	stack<TreeNode*> s;

	while(!s.empty() || root!=NULL)
	{
		while(root!=NULL)
		{
			s.push(root);
			res.push_back(root->val);
			root = root->left;
		}
		
		root = s.top();
		s.pop();
		root = root->right;
	}
	return res;
}

int main()
{
	return 0;
}

