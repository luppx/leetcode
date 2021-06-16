#include <iostream>
using namespace std;

struct Listnode
{
    int val;
    Listnode* next;
    Listnode* prev;
    Listnode(int x=0): val(x), prev(nullptr), next(nullptr) {}
};

class MyLinkedList
{
public:
    MyLinkedList();
    ~MyLinkedList();
    int get(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);

private:
    void printList();
    int mLen;
    Listnode* head;
    Listnode* tail;
};

MyLinkedList::MyLinkedList(): mLen(0)
{
    head = new Listnode(-1);
    tail = new Listnode(-1);
    head->next = tail;
    tail->prev = head;
}

MyLinkedList::~MyLinkedList()
{
    Listnode* cur = head;
    Listnode* tmp = cur;
    while (cur!=nullptr)
    {
        tmp = cur;
        cur = cur->next;
        delete tmp;
    }
}

int MyLinkedList::get(int index)
{
    if(index<0 || index>=mLen) return -1;
    Listnode* cur = head->next;
    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
    }
    return cur->val;
}

void MyLinkedList::addAtHead(int val)
{
    Listnode* node = new Listnode(val);
    node->prev = head;
    node->next = head->next;
    head->next = node;
    node->next->prev = node;
    mLen++;
    printList();
    return;
}

void MyLinkedList::addAtTail(int val)
{
    Listnode* node = new Listnode(val);
    node->prev = tail->prev;
    node->next = tail;
    node->prev->next = node;
    tail->prev = node;
    mLen++;
    printList();
    return;
}

void MyLinkedList::addAtIndex(int index, int val)
{
    if(index>mLen) return;
    else if(index<=0) addAtHead(val);
    else if(index==mLen) addAtTail(val);
    else
    {
        Listnode* node = new Listnode(val);
        Listnode* cur = head->next;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        node->prev = cur->prev;
        node->next = cur;
        node->prev->next = node;
        cur->prev = node;
        mLen++;
        printList();
    }

    return;
}

void MyLinkedList::deleteAtIndex(int index)
{
    if(index<0 || index>=mLen) return;

    Listnode* cur = head->next;
    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    mLen--;
    printList();
    return;
}

void MyLinkedList::printList()
{
    Listnode* cur = head->next;
    while (cur->next!=tail)
    {
        cout<<cur->val<<"->";
        cur = cur->next;
    }
    cout<<cur->val<<endl;
    return;
}


int main()
{
    MyLinkedList* linkedlist = new MyLinkedList();
    linkedlist->addAtHead(7);
    linkedlist->addAtHead(2);
    linkedlist->addAtHead(1);
    linkedlist->addAtIndex(3,0);
    linkedlist->deleteAtIndex(2);
    linkedlist->addAtHead(6);
    linkedlist->addAtTail(4);
    cout<<linkedlist->get(4)<<endl;
    linkedlist->addAtHead(4);
    linkedlist->addAtIndex(5,0);
    linkedlist->addAtHead(6);
    
    delete linkedlist;
    return 0;
}