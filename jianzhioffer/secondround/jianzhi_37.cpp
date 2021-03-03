#include <string>
#include <queue>
using namespace std;

 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// //序列化、反序列化的时间复杂度、空间复杂度都是O(N)
// //方法一，层序遍历，把空节点"NULL"也加入到序列化的返回结果中。这样每个节点的左右孩子都知道了，反序列化很容易就能重构出树了。
// //反序列化时采用BFS遍历
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if(root==NULL) return "";

//         queue<TreeNode*> q;
//         q.push(root);
//         string res = "";
//         while (!q.empty())
//         {
//             TreeNode* node = q.front();
//             q.pop();
//             if(node==NULL)
//             {
//                 res += "NULL,";
//             }
//             else
//             {
//                 res += to_string(node->val);
//                 res += ",";
//                 q.push(node->left);
//                 q.push(node->right);
//             }
//         }
//         return res;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         if(data=="") return NULL;
        
//         vector<string> nodes;

//         for(int i=0,j=0; i<data.size(); i++)
//         {
//             while(data[i]!=',')
//             {
//                 i++;
//             }
//             nodes.push_back(data.substr(j, i-j));
//             j = i+1;
//         }

//         TreeNode* root = new TreeNode(stoi(nodes[0]));
//         queue<TreeNode*> Q;
//         Q.push(root);
//         int idx = 1;
//         while (!Q.empty())
//         {
//             TreeNode* node = Q.front();
//             Q.pop();
//             if (nodes[idx]!="NULL")
//             {
//                 node->left = new TreeNode(stoi(nodes[idx]));
//                 Q.push(node->left);
//             }
//             idx++;
//             if(nodes[idx]!="NULL")
//             {
//                 node->right = new TreeNode(stoi(nodes[idx]));
//                 Q.push(node->right);
//             }
//             idx++;
//         }
//         return root;
//     }
// };

//序列化、反序列化的时间复杂度、空间复杂度都是O(N)
//方法二，采用DFS遍历
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "NULL";

        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        queue<string> nodes;
        for(int i=0,j=0; i<data.size(); i++)
        {
            if(data[i]!=',')
            {
                continue;
            }
            else
            {
                nodes.push(data.substr(j, i-j));
                j = i+1;
            }
        }

        TreeNode* root = DFS(nodes);
        return root;
    }

private:
    TreeNode* DFS(queue<string>& q)
    {
        if (!q.empty())
        {
            string tmp = q.front();
            q.pop();
            if(tmp=="NULL") return NULL;

            TreeNode* node = new TreeNode(stoi(tmp));
            node->left = DFS(q);
            node->right = DFS(q);
            return node;
        }

        return NULL;
    }
};


int main(int argc, char const *argv[])
{
    // Your Codec object will be instantiated and called as such:
    // Codec codec;
    // codec.deserialize(codec.serialize(root));
    // TreeNode n1 = TreeNode(1);
    // TreeNode n2 = TreeNode(2);
    // TreeNode n3 = TreeNode(3);
    // TreeNode n4 = TreeNode(4);
    // TreeNode n5 = TreeNode(5);
    // n1.left = &n2;
    // n1.right = &n3;
    // n3.left = &n4;
    // n3.right = &n5;

    TreeNode n1 = TreeNode(1);
    TreeNode n2 = TreeNode(2);
    TreeNode n3 = TreeNode(3);
    // TreeNode n4 = TreeNode(3);

    TreeNode n6 = TreeNode(4);
    TreeNode n7 = TreeNode(5);
    n1.left = &n2;
    n1.right = &n3;
    // n2.left = &n4;
    n3.left = &n6;
    n3.right = &n7;

    Codec obj;
    string result1 = obj.serialize(&n1);

    TreeNode* result2 = obj.deserialize(result1);

    return 0;
}

