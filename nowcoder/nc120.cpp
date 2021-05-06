class Solution
{
public:
    int NumberOf1(int n);
};

int Solution::NumberOf1(int n)
{
    int res = 0;
    while(n!=0)
    {
        res++;
        n = n & (n-1);
    }
    return res;
}

int main()
{
    int n = -1;
    Solution obj;
    int result = obj.NumberOf1(n);
    return 0;
}