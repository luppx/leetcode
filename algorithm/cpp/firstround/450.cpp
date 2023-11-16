struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;

        TreeNode* dummyHead = new TreeNode(-1);
        dummyHead->right = root;
        TreeNode* prev = dummyHead;
        TreeNode* cur = root;
        while(cur!=nullptr)
        {
            if(cur->val==key) break;
            prev = cur;
            if(cur->val>key) cur = cur->left;
            else cur = cur->right;
        }
        
        if(cur==nullptr) return root; //二叉搜索树中未找到该key，无需删除，直接返回原root

        if(prev->val>key)
        {
            if(cur->left==nullptr)
            {
                prev->left = cur->right;
            }
            else
            {
                prev->left = cur->left;
                TreeNode* tmp = cur->left;
                while(tmp->right!=nullptr) tmp = tmp->right;
                tmp->right = cur->right;
            }
        }
        else if(prev->val<key)
        {
            if(cur->right==nullptr) prev->right = cur->left;
            else
            {
                prev->right = cur->right;
                TreeNode* tmp = cur->right;
                while(tmp->left!=nullptr) tmp = tmp->left;
                tmp->left = cur->left;
            }
        }
        root = dummyHead->right;
        delete dummyHead;
        return root;
    }
};