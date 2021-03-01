#include <vector>
using namespace std;

//二叉搜索树：左节点值<根节点<右节点
//题目已假设输入的数组的任意两个数字都互不相同。
//方法一，递归
//时间复杂度O(N^2)，每次递归完成都会减去一个根节点，所以总共要递归N次；最差情况下，二叉搜索树退化为链表，则每次递归都要遍历链表的所有节点，需要O(N)，故总时间复杂度为O(N^2)
//空间复杂度O(N)，最差情况下，当二叉搜索树退化为链表时，递归深度为N。
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty()) return true;
        return recur(postorder, 0, postorder.size()-1);
    }

    bool recur(vector<int>& postorder, int left, int right)
    {
        if(left>=right) return true;
        int current = left;
        while (current<=right && postorder[current]<postorder[right]) current++;  //左子树
        int pivot = current-1;
        while(current<=right && postorder[current]>postorder[right]) current++;  //右子树
        //左子树边界为[left, pivot]，右子树边界为[pivot+1, current-1](如果循环结束后current!=right，则该序列不是二叉搜索树的后序遍历序列)
        return current == right && recur(postorder, left, pivot) && recur(postorder, pivot+1, current-1);      
    }
private:
    int current, size;
};


int main(int argc, char const *argv[])
{
    vector<int> order = {1,3,2,6,5};
    Solution obj;
    bool res = obj.verifyPostorder(order);
    return 0;
}
