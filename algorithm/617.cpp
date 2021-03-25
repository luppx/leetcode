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
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2);
};

TreeNode* Solution::mergeTrees(TreeNode* root1, TreeNode* root2)
{
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;

        TreeNode* root = new TreeNode(root1->val + root2->val);

        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
}

int main()
{
	return 0;
}

