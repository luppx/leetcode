# include <vector>
# include <unordered_map>
# include <stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归。时间复杂度O(n)
//空间复杂度O(n)(建立了hashmap，最差情况下树退化为链表，递归深度到N，空间复杂度O(n)，最好情况下树为满二叉树，递归深度为logN，空间复杂度O(logN))
// class Solution {
// public:
//     unordered_map<int, int> in_map; //存储中序序列中各个元素值的位置

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         if (preorder.size()==0)
//             return NULL;
//         for (int i = 0; i < inorder.size(); i++)  //建立map，其中key为结点值，value为该值在中序序列中的index
//         {
//             in_map[inorder[i]] = i;
//         }
//         return recur(preorder, inorder, 0, 0, inorder.size()-1);
//     }

//     TreeNode* recur(vector<int>& preorder, vector<int>& inorder, int pre_root_idx, int in_left_bound, int in_right_bound)
//     {
//         if(in_left_bound > in_right_bound) //中序遍历左边界大于右边界，说明已经越过叶节点，返回null
//             return NULL;
//         TreeNode* node = new TreeNode(preorder[pre_root_idx]); //在前序序列中找到根节点的值
//         int in_root_idx = in_map[preorder[pre_root_idx]];  //根据根节点的值找到根节点在中序序列中的索引
        
//         //找左子树的根。左子树的根节点在前序序列中的索引为pre_root_idx+1，左子树在中序序列中的边界为[in_left_bound, in_root_idx-1]
//         node->left = recur(preorder, inorder, pre_root_idx+1, in_left_bound, in_root_idx-1);
//         //找右子树的根。右子树的根节点在前序序列中的索引为：根节点+左子树长度+1，即pre_root_idx+(in_root_idx-in_left_bound)+1
//         //右子树在中序序列中的边界为[in_root_idx+1, in_right_bound]
//         node->right = recur(preorder, inorder, pre_root_idx+(in_root_idx-in_left_bound)+1, in_root_idx+1, in_right_bound);
//         return node;
//     }
// };

//迭代。时间复杂度O(N)，空间复杂度O(N)。速度比递归快得多，leetcode将近双百。
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0)
            return NULL;
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);
        int inorder_idx = 0;
        for (int i = 1; i < preorder.size(); i++)
        {
            int pre_val = preorder[i];
            TreeNode* tmp = s.top();
            if (tmp->val != inorder[inorder_idx])
            {
                tmp->left = new TreeNode(pre_val);
                s.push(tmp->left);
            }
            else
            {
                //TreeNode* node = new TreeNode(-1);
                while (!s.empty() && s.top()->val==inorder[inorder_idx])
                {
                    tmp = s.top();
                    s.pop();
                    inorder_idx++;
                }
                tmp->right = new TreeNode(pre_val);
                s.push(tmp->right);
            }          
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> pre = {3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};
    Solution obj;
    TreeNode* result = obj.buildTree(pre, in);
    return 0;
}
