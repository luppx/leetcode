#include <climits>
#include <vector>
using namespace std;

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
    vector<int> findMode(TreeNode* root);

private:
    void inOrder(TreeNode* root);
    vector<int> res;
    int mostCount;
    int curCount;
    int preVal;
};

vector<int> Solution::findMode(TreeNode* root) {
    if(root==nullptr) return res;

    mostCount = 0;
    curCount = 0;
    preVal = INT_MIN;
    inOrder(root);
    return res;
}

void Solution::inOrder(TreeNode* root)
{
    if(root==nullptr) return;

    inOrder(root->left);

    if(preVal==INT_MIN) curCount=1;
    else if(preVal==root->val) curCount++;
    else curCount=1;

    preVal = root->val;

    if(curCount==mostCount)
    {
        res.emplace_back(root->val);
    }
    else if(curCount>mostCount)
    {
        mostCount = curCount;
        res.clear();
        res.emplace_back(root->val);
    } 

    inOrder(root->right);
    return;
}