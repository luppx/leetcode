#include <deque>
#include <queue>
using namespace std;

class Solution
{
public:
	Solution():q(), aux_q() {}
	int max_value();
	void push_back(int value);
	int pop_front();

private:
	queue<int> q;
	deque<int> aux_q;
};

int Solution::max_value()
{
	if(q.empty()) return -1;
	return aux_q.front();
}

int Solution::pop_front()
{
	if(q.empty()) return -1;
	int tmp=q.front();
	if(tmp==aux_q.front()) aux_q.pop_front();
	q.pop();
	return tmp;
}

void Solution::push_back(int value)
{
	while(!aux_q.empty() && aux_q.back()<value) aux_q.pop_back();

	q.push(value);
	aux_q.push_back(value);
	return;
}

int main()
{
	Solution obj;
	obj.push_back(1);
	obj.push_back(2);
	int p1 = obj.max_value();
	int p2 = obj.pop_front();
	int p3 = obj.max_value();
	return 0;
}
