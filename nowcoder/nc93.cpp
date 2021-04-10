#include <cstddef>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
    int key, val;
    Node* prev;
    Node* next;
    Node(int k, int v): key(k), val(v), prev(NULL), next(NULL) {}
};

class Solution
{
public:
    Solution();
    ~Solution();
    vector<int> LRU(vector<vector<int>>& ops, int k);


private:
    void set(int key, int val);
    int get(int key);
    void moveToHead(Node* node);
    void removeTail();
    void insertToFirst(Node* node);

    unordered_map<int, Node*> m;
    int max_size;
    int cur_size;
    Node* head;
    Node* tail;
};

Solution::Solution(): max_size(0), cur_size(0)
{
    head = new Node(-1,-1);
    tail = new Node(-1,-1);
    head->next = tail;
    tail->prev = head;
}

Solution::~Solution()
{
    delete head;
    delete tail;
}

vector<int> Solution::LRU(vector<vector<int>>& ops, int k)
{
    if(k<1) return {};
    max_size = k;

    vector<int> res = {};
    for (int i = 0; i < ops.size(); i++)
    {
        if(ops[i].front()==1)
        {
            set(ops[i][1], ops[i][2]);
        }
        else if(ops[i].front()==2)
        {
            res.push_back(get(ops[i].back()));
        }
    }
    return res;
}

void Solution::set(int key, int val)
{
    if(m.find(key)!=m.end()) moveToHead(m[key]);  //访问的页面已经在缓存中，则将其移至表头
    else  //不在缓存中，则需调入页面
    {
        Node* node = new Node(key, val);
        m[key] = node;
        if(cur_size==max_size)
        {
            removeTail();
            cur_size--;
        }
        insertToFirst(node);
        cur_size++;
    }
     
    return ;    
}

int Solution::get(int key)
{
    if(m.find(key)!=m.end())
    {
        moveToHead(m[key]);
        return m[key]->val;
    }
    else return -1;

}

void Solution::moveToHead(Node* node)
{
    if(head==node) return;
    node->prev->next = node->next;
    node->next->prev = node->prev;

    insertToFirst(node);
    return;
}

void Solution::removeTail()
{
    if(tail->prev==head) return;  //如果链表为空，直接返回
    Node* tmp = tail->prev;
    tmp->prev->next = tail;
    tail->prev = tmp->prev;
    m.erase(tmp->key);
    delete tmp;
    return;
}

void Solution::insertToFirst(Node* node)
{
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    return ;
}

int main()
{
    Solution obj;
    return 0;
}
