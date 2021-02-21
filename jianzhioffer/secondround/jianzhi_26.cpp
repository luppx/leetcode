#include <cstddef>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//先序遍历树A，当遍历到树B的根节点时，进入递归判断树B是否为树A的子结构
//时间复杂度O(MN)，先序遍历树A花费O(M)，递归判断需遍历树B的所有节点，花费O(N)
//空间复杂度O(M)
//递归判断函数自己已经写出来了，但没有想到先序遍历找到树B根节点再进行递归判断这一步的代码实现。
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL || B==NULL) return false;
        bool res = recur(A,B) || isSubStructure(A->left, B) || isSubStructure(A->right, B); //首先先序遍历树A，找到子结构的根节点B在树A中的位置
        return res;
    }

private:
    bool recur(TreeNode* l1, TreeNode* l2)
    {
        if(l2==NULL) return true;
        else if(l1==NULL && l2!=NULL) return false;

        if (l1->val == l2->val)
        {
            return recur(l1->left, l2->left) && recur(l1->right, l2->right);
        }
        else
            return false;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode t11 = TreeNode(3);
    TreeNode t12 = TreeNode(4);
    TreeNode t13 = TreeNode(5);
    TreeNode t14 = TreeNode(1);
    TreeNode t15 = TreeNode(2);

    t11.left = &t12;
    t11.right = &t13;
    t12.left = &t14;
    t12.right = &t15;

    TreeNode t21 = TreeNode(4);
    TreeNode t22 = TreeNode(1);
    t21.left = &t22;

    Solution obj;
    bool result = obj.isSubStructure(&t11, &t21);
    return 0;
}
