#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    MyQueue();
    void push(int x);
    int pop();
    int peek();
    bool empty();

private:
    stack<int> stack1;
    stack<int> stack2;
};

MyQueue::MyQueue()
{
    stack1 = {};
    stack2 = {};
}

void MyQueue::push(int x)
{
    stack1.push(x);
}

int MyQueue::pop()
{
    if (empty())
    {
        return -1;
    }
    else if(stack2.empty())
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    int res = stack2.top();
    stack2.pop();
    return res;
}

int MyQueue::peek()
{
    int res = pop();
    stack2.push(res);
    return res; 
}

bool MyQueue::empty()
{
    return stack1.empty() && stack2.empty();
}

int main()
{
    return 0;
}