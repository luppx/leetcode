 #include <vector>
 #include <cmath>
 using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//前序遍历的回溯法。想到了前序遍历+递归，但回溯这里的代码实现没有写出来。
//时间复杂度O(N)
//空间复杂度O(N)。最坏情况下二叉树退化为链表，path数组在遍历过程中可能需要存储链表的所有节点，占用O(N)空间
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL) return res;
        obj_num = sum;
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int cur)
    {
        if(root==NULL) return;
        cur += root->val;
        path.push_back(root->val);

        if(cur==obj_num && root->left==NULL && root->right==NULL)
        {
            res.push_back(path);
            path.pop_back();
            return;
        }
        dfs(root->left, cur);
        dfs(root->right, cur);
        path.pop_back();
        return ;
    }

private:
    int obj_num;
    vector<vector<int>> res;
    vector<int> path;
};

int main(int argc, char const *argv[])
{
    TreeNode t1 = TreeNode(5);
    TreeNode t2 = TreeNode(4);
    TreeNode t3 = TreeNode(8);
    TreeNode t4 = TreeNode(11);
    //TreeNode t5 = TreeNode(5);
    TreeNode t6 = TreeNode(13);
    TreeNode t7 = TreeNode(4);
    TreeNode t8 = TreeNode(7);
    TreeNode t9 = TreeNode(2);
    TreeNode t10 = TreeNode(5);
    TreeNode t11 = TreeNode(1);

    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    // t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;
    t4.left = &t8;
    t4.right = &t9;
    t7.left = &t10;
    t7.right = &t11;

    Solution obj;
    vector<vector<int>> result = obj.pathSum(&t1, 22);
    return 0;
}