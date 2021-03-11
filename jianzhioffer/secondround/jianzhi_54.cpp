#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {};
};

class Solution
{
public:
    int kthLargest(TreeNode* root, int k);

private:
    void inorder(TreeNode* root);
    int count;
    int res;
};

//中序遍历+数组存储节点。时间复杂度O(N)，空间复杂度O(N)
// int Solution::kthLargest(TreeNode* root, int k)
// {
//     if(root==NULL) return 0;
//     nodes = {};
//     inorder(root);
//     if(nodes.size()<k) return 0;
//     return nodes[nodes.size()-k];
// }

// void Solution::inorder(TreeNode* root)
// {
//     if(root==NULL) return;
//     inorder(root->left);
//     nodes.push_back(root->val);
//     inorder(root->right);
//     return ;
// }


//优化，中序遍历的倒序。即先遍历root->right,再遍历root，最后遍历root->left
//时间复杂度O(N)，空间复杂度O(1)
int Solution::kthLargest(TreeNode* root, int k)
{
    if(root==NULL) return 0;
    count = k;
    res = 0;
    inorder(root);
    return res;
}

void Solution::inorder(TreeNode* root)
{
    if(root==NULL) return;
    inorder(root->right);
    if(count==0) return;
    count--;
    if(count==0)
    {
        res = root->val;
    }
    inorder(root->left);
    return ;
}


int main(int argc, char const *argv[])
{
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(4);
    TreeNode* n4 = new TreeNode(2);

    n1->left = n2;
    n1->right = n3;
    n2->right = n4;
    Solution obj;
    int result = obj.kthLargest(n1, 1);
    return 0;
}
