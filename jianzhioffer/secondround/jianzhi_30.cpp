#include <stack>
using namespace std;

//创建两个栈，一个数据栈，一个辅助栈。数据栈正常存储数据，辅助栈存储每个x进入数据栈后，数据栈中已有元素的最小值（即辅助栈的top()始终存放着当前数据栈的最小值）。
//两个栈中的元素个数始终保持相同
//时间复杂度都是题目要求的O(1)，空间复杂度O(N)
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || s2.top()>x)
        {
            s2.push(x);
        }
        else
        {
            int min = s2.top();
            s2.push(min);
        }
        
        
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int min() {
        return s2.top();
    }

private:
    stack<int> s1, s2;
};

int main(int argc, char const *argv[])
{

    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->min();
 
    return 0;
}
