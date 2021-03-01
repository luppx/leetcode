<<<<<<< HEAD
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

//树的层序遍历，或BFS，时间复杂度O(N)，空间复杂度O(N)
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode* node = que.front();
            que.pop(); //去除队首元素
            res.push_back(node->val);
            if(node->left!=NULL) que.push(node->left);
            if(node->right!=NULL) que.push(node->right);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    TreeNode t3 = TreeNode(3);
    // TreeNode t4 = TreeNode(4);
    // TreeNode t5 = TreeNode(5);
    TreeNode t6 = TreeNode(6);
    TreeNode t7 = TreeNode(7);

    t1.left = &t2;
    t1.right = &t3;
    // t2.left = &t4;
    // t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;

    Solution obj;
    vector<int> result = obj.levelOrder(&t1);
    return 0;
=======
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

//树的层序遍历，或BFS，时间复杂度O(N)，空间复杂度O(N)
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode* node = que.front();
            que.pop(); //去除队首元素
            res.push_back(node->val);
            if(node->left!=NULL) que.push(node->left);
            if(node->right!=NULL) que.push(node->right);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    TreeNode t3 = TreeNode(3);
    // TreeNode t4 = TreeNode(4);
    // TreeNode t5 = TreeNode(5);
    TreeNode t6 = TreeNode(6);
    TreeNode t7 = TreeNode(7);

    t1.left = &t2;
    t1.right = &t3;
    // t2.left = &t4;
    // t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;

    Solution obj;
    vector<int> result = obj.levelOrder(&t1);
    return 0;
>>>>>>> c02bd06644e6a77d7bfda85f1876d137906a27bd
}