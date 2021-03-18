#include <cstddef>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
};

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if(root==NULL || p==NULL || q==NULL) return NULL;
	TreeNode* result = root;
	while(result!=NULL)
	{
		if((result->val > p->val) && (result->val > q->val)) result = result->left;  //该树是二叉搜索树。如果节点值比p和q都大，说明p、q都在其左子树
		else if((result->val < p->val) && (result->val < q->val)) result = result->right;  //如果比p、q都小，说明p q都在其右子树
		else break; //此时有两种情况：p、q分别在节点的左右两侧，即节点是距离p、q最近的分岔点；或者节点就是p、q中的一个，按照题目定义，此时节点就是最近公共祖先。两种情况下，节点肯定都是最近的公共祖先
	}
	return result;	
}

int main()
{
	return 0;
}
