#include <vector>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v=0, ListNode* n=nullptr) : val(v), next(n) {}
};

class MyHashSet
{
public:
    MyHashSet();
    void add(int key);
    bool contains(int key);
    void remove(int key);

private:
    vector<ListNode*> hashSet;
    static int base;
    static int hash(int key);
};

int MyHashSet::base = 769;

MyHashSet::MyHashSet()
{
    hashSet = vector<ListNode*>(769, nullptr);
}

void MyHashSet::add(int key)
{
    if(contains(key)) return;

    int idx = hash(key);

    ListNode* node = new ListNode(key);

    if(hashSet[idx]==nullptr)
    {
        hashSet[idx] = new ListNode(0, node);
    }
    else
    {
        ListNode* it = hashSet[idx]->next;
        while (it->next!=nullptr)
        {
            it = it->next;
        }
        it->next = node;
    }
    return;
}

bool MyHashSet::contains(int key)
{
    int idx = hash(key);
    
    if(hashSet[idx]==nullptr) return false;

    ListNode* it = hashSet[idx]->next;
    while (it!=nullptr)
    {
        if(it->val==key) return true;
        it = it->next;
    }
    return false;
}

void MyHashSet::remove(int key)
{
    if(!contains(key)) return;

    int idx = hash(key);
    
    ListNode* cur = hashSet[idx]->next;
    ListNode* pre = hashSet[idx];
    
    if(cur->val==key && cur->next==nullptr)
    {
        hashSet[idx] = nullptr;
        delete cur;
        delete pre;
        return;
    }

    while(cur!=nullptr)
    {
        if(cur->val==key)
        {
            pre->next = cur->next;
            delete cur;
            return;
        }
        pre = cur;
        cur = cur->next;
    }
    return;
}


int MyHashSet::hash(int key)
{
    return key % base;
}

int main()
{
    MyHashSet obj;
    obj.add(2);
    obj.remove(2);
    obj.add(2);
    return 0;
}