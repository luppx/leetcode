#include <cstddef>

#include <algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(NULL), right(NULL) {}
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution
{
public:
	bool isBalanced(TreeNode* root);

private:
	int height(TreeNode* root);
};

bool Solution::isBalanced(TreeNode* root)
{
	if(root==NULL) return true;
	return height(root)==-1 ? false : true;
}

int Solution::height(TreeNode* root)
{
	if(root==NULL) return 0;
	int leftHeight = height(root->left);
	if(leftHeight==-1) return -1;  //如果左子树已经是不平衡树了，提前返回
	int rightHeight = height(root->right);
	if(rightHeight==-1) return -1;  //如果右子树已经是不平衡树了，提前返回
	if(abs(leftHeight-rightHeight)>1) return -1;

	return max(leftHeight, rightHeight)+1;
}

int main()
{
	return 0;
}

