#include <cstddef>
#include <algorithm>
#include <climits>
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
        int minDepth(TreeNode* root);
private:
        int postorder(TreeNode* root);
};

int Solution::minDepth(TreeNode* root)
{
    if(root==NULL) return 0;
    return postorder(root);
}

int Solution::postorder(TreeNode* root)
{
        if(root==NULL) return INT_MAX;

        if(root->left==NULL && root->right==NULL) return 1;
        return min(postorder(root->left), postorder(root->right))+1;
}

int main()
{
	return 0;
}

