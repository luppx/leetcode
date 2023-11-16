#include <cstddef>
#include <algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int findSecondMinimumValue(TreeNode* root);

private:
    int postorder(TreeNode* root);
    int minest;

};

int Solution::findSecondMinimumValue(TreeNode* root) 
{
        if(root==NULL || (root->left==NULL && root->right==NULL)) return -1;
        minest = root->val;
        return postorder(root);
}

int Solution::postorder(TreeNode* root)
{
    if(root==NULL) return -1;

    int l = postorder(root->left);
    int r = postorder(root->right);
    
    if(root->val!=minest) return root->val;

    if(l==-1 && r==-1) return -1;
    else if(l==-1) return r;
    else if(r==-1) return l;
    else return min(l,r);
}

int main()
{
	return 0;
}

