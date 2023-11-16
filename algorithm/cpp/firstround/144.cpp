#include <cstddef>
#include <vector>
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

private:
	void preorder(TreeNode* root);
	vector<int> res;
};

vector<int> Solution::preorderTraversal(TreeNode* root)
{
	if(root==NULL) return {};
	res = {};
	preorder(root);
	return res;
}

void Solution::preorder(TreeNode* root)
{
	if(root==NULL) return;
	res.push_back(root->val);
	preorder(root->left);
	preorder(root->right);
	return;
}

int main()
{
	return 0;
}

