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
	TreeNode* invertTree(TreeNode* root);
};

TreeNode* Solution::invertTree(TreeNode* root)
{
	if(root==NULL) return NULL;

	TreeNode* l = invertTree(root->left);
	TreeNode* r = invertTree(root->right);
	root->left = r;
	root->right = l;
	return root;
}

int main()
{
	return 0;
}

