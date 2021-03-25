#include <cstddef>
#include <algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

class Solution
{
public:
        Solution():maxPathLen(0) {}
        int diameterOfBinaryTree(TreeNode* root);

private:
        int maxPathLen;
        int postorder(TreeNode* root);
};

int Solution::diameterOfBinaryTree(TreeNode* root)
{
        if(root==NULL || root->left==NULL && root->right==NULL) return 0;
    
        int tmp = postorder(root);
        return maxPathLen;

}

int Solution::postorder(TreeNode* root)
{
        if(root==NULL) return 0;

        int lheight = postorder(root->left); 
        int rheight = postorder(root->right); 
        int pathlen = lheight + rheight;
        if(pathlen>maxPathLen) maxPathLen = pathlen;

        return max(lheight, rheight)+1;

}

int main()
{
	return 0;
}



