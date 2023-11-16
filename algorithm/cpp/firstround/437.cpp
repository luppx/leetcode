#include <cstddef>
#include <unordered_map>
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
        int pathSum(TreeNode* root, int sum);

private:
        void preorder(TreeNode* root, int sum);
        unordered_map<int, int> map;
        int pathnum;
        int target;
};

int Solution::pathSum(TreeNode* root, int sum)
{
        if(root==NULL) return 0;
        map.insert(make_pair(0,1));
        pathnum = 0;
        target = sum;

        preorder(root, 0);
        return pathnum;
}

void Solution::preorder(TreeNode* root, int sum)
{
        if(root==NULL) return;
        int cursum = sum+root->val;
        if(map.count(cursum-target)==1) pathnum += map[cursum-target];

        map[cursum]++;
        preorder(root->left, cursum);
        preorder(root->right, cursum);
        map[cursum]--;
        return;
}


int main()
{
        // TreeNode* n1 = new TreeNode(10);
        // TreeNode* n2 = new TreeNode(5);
        // TreeNode* n3 = new TreeNode(-3);
        // TreeNode* n4 = new TreeNode(3);
        // TreeNode* n5 = new TreeNode(2);
        // TreeNode* n7 = new TreeNode(11);
        // TreeNode* n8 = new TreeNode(3);
        // TreeNode* n9 = new TreeNode(-2);
        // TreeNode* n11 = new TreeNode(1);

        // n1->left = n2;
        // n1->right = n3;
        // n2->left = n4;
        // n2->right = n5;
        // n3->right = n7;
        // n4->left = n8;
        // n4->right = n9;
        // n5->right = n11;

        unordered_map<int, int> m = {};
        m.insert(make_pair(3,2));
        int a = m.count(1);
        int b = m.count(3);
        m[3]--;
        int c = m.count(3);
        m[3]--;
        int d = m.count(3);

        TreeNode* n1 = new TreeNode(1);
        TreeNode* n2 = new TreeNode(2);
        TreeNode* n3 = new TreeNode(3);
        TreeNode* n4 = new TreeNode(4);
        TreeNode* n5 = new TreeNode(5);
        n1->right = n2;
        n2->right = n3;
        n3->right = n4;
        n4->right = n5;

        Solution obj;
        int result = obj.pathSum(n1, 3);

        return 0;
}

