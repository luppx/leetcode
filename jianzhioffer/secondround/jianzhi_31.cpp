#include <vector>
#include <stack>
using namespace std;

//时间复杂度O(N)，空间复杂度O(N)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty() && popped.empty()) return true;
        if(pushed.empty() || popped.empty()) return false;
        int push_count = 0;
        int pop_count = 0;
        stack<int> push_stack;
        push_stack.push(pushed[0]);
        push_count++;
        while(pop_count<popped.size())
        {
            if(!push_stack.empty() && push_stack.top()==popped[pop_count])
            {
                push_stack.pop();
                pop_count++;
            }
            else if(push_count<pushed.size())
            {
                push_stack.push(pushed[push_count]);
                push_count++;
            }
            else
                return false;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> pushed, popped;
    pushed = {1,0};
    popped = {1,0};
    Solution obj;
    bool result = obj.validateStackSequences(pushed, popped);
    return 0;
}
