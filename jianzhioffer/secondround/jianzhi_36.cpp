#include <cstddef>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

//中序遍历，时间复杂度O(N)，空间复杂度O(1)
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return NULL;
        prev = NULL;
        DFS(root);
        head->left = prev;
        prev->right = head;
        return head;    
    }

    void DFS(Node* node)
    {
        if(node==NULL) return;
        DFS(node->left);
        if (prev!=NULL)
        {
            prev->right = node;
            node->left = prev;
        }
        else
        {
            head = node;
        }
        prev = node;
        DFS(node->right);
        
    }

private:
    Node* head;
    Node* prev;
};