# include <stack>
using namespace std;

class CQueue {
public:
    stack<int> s1, s2;
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
        {
            return -1;
        }
        else
        {
            int head = s2.top();
            s2.pop();
            return head;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    /**
     * Your CQueue object will be instantiated and called as such:
     * CQueue* obj = new CQueue();
     * obj->appendTail(value);
     * int param_2 = obj->deleteHead();
     */
    CQueue* obj = new CQueue();
    int p1 = obj->deleteHead();
    obj->appendTail(5);
    obj->appendTail(2);
    int p2 = obj->deleteHead();
    int p3 = obj->deleteHead();
    int p4 = obj->deleteHead();
    return 0;
}
