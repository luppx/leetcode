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
	Solution(): sum(0) {}
	int sumOfLeftLeaves(TreeNode* root);

private:
	int sum;
	void preorder(TreeNode* root);
};

int Solution::sumOfLeftLeaves(TreeNode* root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL)) return 0;
	preorder(root);
	return sum;
}

void Solution::preorder(TreeNode* root)
{
	if(root==NULL) return;
	
	if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
	{
		sum += root->left->val;
	}
	else preorder(root->left);
	
	preorder(root->right);
	return;
}

int main()
{
	return 0;
}

