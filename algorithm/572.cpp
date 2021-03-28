#include <cstddef>
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
	bool isSubtree(TreeNode* s, TreeNode* t);

private:
	bool preorder(TreeNode* s, TreeNode* t);
	bool check(TreeNode* s, TreeNode* t);
};

bool Solution::isSubtree(TreeNode* s, TreeNode* t)
{
	return preorder(s,t);
}

bool Solution::check(TreeNode* s, TreeNode* t)
{
	if(s==NULL && t==NULL) return true;
	else if((s==NULL && t!=NULL) || (s!=NULL && t==NULL) || (s->val!=t->val)) return false;
	return check(s->left, t->left) && check(s->right, t->right);
}

bool Solution::preorder(TreeNode* s, TreeNode* t)
{
	if(s==NULL) return false;
	return check(s,t) || preorder(s->left, t) || preorder(s->right, t);
}

int main()
{
	return 0;
}

