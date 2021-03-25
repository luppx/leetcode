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
        bool hasPathSum(TreeNode* root, int targetSum);
};

bool Solution::hasPathSum(TreeNode* root, int targetSum)
{
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL) return root->val==targetSum;
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
}

int main()
{
	return 0;
}

