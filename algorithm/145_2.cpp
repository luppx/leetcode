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
	vector<int> postorderTraversal(TreeNode* root);
};

vector<int> Solution::postorderTraversal(TreeNode* root)
{
	if(root==NULL) return {};
	vector<int> res = {};
	stack<TreeNode*> s;
	TreeNode* prev = NULL;

	while(!s.empty() || root!=NULL)
	{
		while(root!=NULL)
		{
			s.push(root);
			root = root->left;
		}

		root = s.top();
		s.pop();
		if(root->right==NULL || prev==root->right)
		{
			res.push_back(root->val);
			prev = root;
			root = NULL;
		}
		else
		{
			s.push(root);
			root = root->right;
		}
	}
	return res;
}

int main()
{
	return 0;
}

