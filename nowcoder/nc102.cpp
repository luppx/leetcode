#include <vector>
#include <cstddef>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int lowestCommonAncestor(TreeNode* root, int r1, int r2);

private:
    TreeNode* DFS(TreeNode* root, int r1, int r2);
};


//最近公共祖先：
//1.两个节点在一棵树或子树的两侧，则最近的祖先节点即为该树的根节点；
//2.一个节点为另一个节点的祖先节点，则最近公共祖先为该节点
int Solution::lowestCommonAncestor(TreeNode* root, int r1, int r2)
{
    if(root==nullptr) return -1;

    return DFS(root, r1, r2)->val;
}

//自底向上递归
TreeNode* Solution::DFS(TreeNode* root, int r1, int r2)
{
    if(root==nullptr || root->val==r1 || root->val==r2) return root;

    TreeNode* left = DFS(root->left, r1, r2);
    TreeNode* right = DFS(root->right, r1, r2);

    if(left!=nullptr && right!=nullptr) return root; //查找的节点在根节点两侧，则该根节点即为最近公共祖先
    else return left==nullptr ? right : left;  //一个节点为另一个节点的祖先节点，则该节点即为最近公共祖先；或者在该子树的左右子树中都没有找到这两个节点，则left和right都为null，返回哪个都是一样的
}

int main()
{
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(5);
    TreeNode* n3 = new TreeNode(1);
    TreeNode* n4 = new TreeNode(6);
    TreeNode* n5 = new TreeNode(2);
    TreeNode* n6 = new TreeNode(0);
    TreeNode* n7 = new TreeNode(8);
    // TreeNode* n8 = new TreeNode(3);
    // TreeNode* n9 = new TreeNode(3);
    TreeNode* n10 = new TreeNode(7);
    TreeNode* n11 = new TreeNode(4);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    
    n5->left = n10;
    n5->right = n11;

    int r1 = 2;
    int r2 = 4;
    Solution obj;
    int result = obj.lowestCommonAncestor(n1, r1, r2);
    return 0;
}