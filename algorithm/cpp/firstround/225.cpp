#include <iostream>
#include <deque>
using namespace std;

class MyStack
{
public:
    MyStack();

    void push(int x);

    int pop();

    int top();

    bool empty();

private:
    deque<int> q;
};

MyStack::MyStack() : q({}) {}

void MyStack::push(int x)
{
    q.push_back(x);
}

int MyStack::pop()
{
    if(empty()) return -1;
    int size = q.size();
    size--;
    for (int i = 0; i < size; i++)
    {
        q.push_back(q.front());
        q.pop_front();
    }
    int res = q.front();
    q.pop_front();
    return res;
}

int MyStack::top()
{
    return q.back();
}

bool MyStack::empty()
{
    return q.empty();
}

int main()
{
    return 0;
}