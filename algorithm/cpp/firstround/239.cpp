#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

class MyQueue
{
public:
    void push(int x);
    void pop(int x);
    int front();

private:
    deque<int> q;
};

void MyQueue::push(int x)
{
    while(!q.empty() && q.back()<x)
    {
        q.pop_back();
    }
    q.push_back(x);
    return;
}

void MyQueue::pop(int x)
{
    if(!q.empty() && q.front()==x)
    {
        q.pop_front();
    }
    return;
}

int MyQueue::front()
{
    return q.front();
}

class Solution : public MyQueue
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k);
};

vector<int> Solution::maxSlidingWindow(vector<int>& nums, int k)
{
    if(nums.empty() || k<1) return {};

    vector<int> res = {};

    int left=0;
    int right = min(k, (int)nums.size());
    MyQueue q;
    for(int i=0; i<right; i++)
    {
        q.push(nums[i]);
    }
    res.emplace_back(q.front());
    left++;
    right++;

    while(left<right && right<=nums.size())
    {
        q.pop(nums[left-1]);
        q.push(nums[right-1]);
        res.emplace_back(q.front());
        left++;
        right++;
    }
    return res;
}

int main()
{
    return 0;
}