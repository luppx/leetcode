#include <cstddef>
#include <climits>
#include <vector>
#include <queue>
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
    vector<bool> judgeIt(TreeNode* root);

private:
    bool isSearchBinaryTree(TreeNode* root, int low_bound, int up_bound);
    bool isCompleteBinaryTree(TreeNode* root);
};

vector<bool> Solution::judgeIt(TreeNode* root)
{
    vector<bool> res = {true, true};
    if(root==NULL) return res;
    res[0] = isSearchBinaryTree(root, INT_MIN, INT_MAX);
    res[1] = isCompleteBinaryTree(root);
    return res;
}

bool Solution::isSearchBinaryTree(TreeNode* root, int low_bound, int up_bound)
{
    if(root==NULL) return true;
    
    if(root->val<low_bound || root->val>up_bound) return false;

    return isSearchBinaryTree(root->left, low_bound, root->val) && isSearchBinaryTree(root->right, root->val, up_bound);
}

bool Solution::isCompleteBinaryTree(TreeNode* root)
{
    if(root==NULL) return false;

    queue<TreeNode*> q;
    q.push(root);

    bool find_first_leaf = false;
    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if(node->left==NULL && node->right!=NULL)
            return false;  //无左孩子，有右孩子，肯定不是完全二叉树
        else if(find_first_leaf && (node->left || node->right))
            return false;  //已经找到第一个叶节点，则之后必须都是叶节点，否则不是完全二叉树

        if(find_first_leaf==false && ((node->left==NULL && node->right==NULL) || (node->left!=NULL && node->right==NULL)))
            find_first_leaf=true;
        
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    
    return true;
}

int main()
{
    return 0;
}