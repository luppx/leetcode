#include <cstdio>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root);

private:
    void handle(Node*& prev, Node*& cur, Node*& nextStart);
};

Node* Solution::connect(Node* root)
{
    if(root==nullptr) return root;

    Node* start = root;
    while(start!=nullptr)
    {
        Node* prev = nullptr;
        Node* nextStart = nullptr;
        Node* cur = start;
        while(cur!=nullptr)
        {
            if(cur->left)
            {
                handle(prev, cur->left, nextStart);
            }
            if(cur->right)
            {
                handle(prev, cur->right, nextStart);
            }
            cur = cur->next;
        }
        start = nextStart;
    }
    return root;
}

void Solution::handle(Node*& prev, Node*& cur, Node*& nextStart)
{
    if(prev!=nullptr)
    {
        prev->next = cur;
    }
    if(nextStart==nullptr)
    {
        nextStart = cur;
    }
    prev = cur;
}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n6 = new Node(6);
    Node * n7 = new Node(7);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n6;
    n3->right = n7;

    Solution obj;
    Node* result = obj.connect(n1);
    return 0;
}