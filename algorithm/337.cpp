#include <cstddef>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

struct status
{
	int selected;
	int unselected;
};

class Solution
{
public:
	int rob(TreeNode* root);

private:
	status postorder(TreeNode* root);
};

int Solution::rob(TreeNode* root)
{
	if(root==NULL) return 0;
	status st = postorder(root);
	return max(st.selected, st.unselected);
}

status Solution::postorder(TreeNode* root)
{
	if(root==NULL) return {0,0};

	status l = postorder(root->left);
	status r = postorder(root->right);
	
	int selected = root->val + l.unselected + r.unselected;
	int unselected = max(l.selected, l.unselected) + max(r.selected, r.unselected);
	return {selected, unselected};
}

int main()
{
	return 0;
}

