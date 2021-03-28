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
	vector<int> inorderTransversal(TreeNode* root);
};

vector<int> Solution::inorderTransversal(TreeNode* root)
{
	if(root==NULL) return {};
	vector<int> res = {};
	stack<TreeNode*> s;

	while(!s.empty() || root!=NULL)
	{
		while(root!=NULL)
		{
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		res.push_back(root->val);
		root = root->right;
	}
	return res;
}

int main()
{
	return 0;
}

