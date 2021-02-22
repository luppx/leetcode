#include <cstddef>
#include <vector>
#include <queue>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// //递归判断树的左子树和右子树是否完全一样
// //时间复杂度O(N)，空间复杂度O(N)
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(root==NULL) return true;
//         return dfs(root->left, root->right);
//     }

//     bool dfs(TreeNode* root1, TreeNode* root2)
//     {
//         if(root1==NULL && root2==NULL) return true;
//         else if(root1==NULL || root2==NULL || root1->val!=root2->val) return false;
//         else return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
//     }
// };

//迭代法，时间复杂度O(N)，空间复杂度O(N)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty())
        {
            TreeNode* nodeLeft = que.front();
            que.pop();
            TreeNode* nodeRight = que.front();
            que.pop();
            if(nodeLeft==NULL && nodeRight==NULL) continue;
            else if(nodeLeft==NULL || nodeRight==NULL || nodeLeft->val!=nodeRight->val)
            {
                return false;
            }
            que.push(nodeLeft->left);
            que.push(nodeRight->right);
            que.push(nodeLeft->right);
            que.push(nodeRight->left);
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode t11 = TreeNode(1);
    TreeNode t12 = TreeNode(2);
    TreeNode t13 = TreeNode(2);
    TreeNode t14 = TreeNode(3);
    //TreeNode t15 = TreeNode(4);
    TreeNode t16 = TreeNode(3);
    //TreeNode t17 = TreeNode(3);

    t11.left = &t12;
    t11.right = &t13;
    t12.left = &t14;
    //t12.right = &t15;
    t13.left = &t16;
    //t13.right = &t17;

    Solution obj;
    bool result = obj.isSymmetric(&t11);
    return 0;
}