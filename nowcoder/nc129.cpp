class Solution
{
public:
    long long thenumberof0(long long n);
};


//Reference: https://leetcode-cn.com/problems/factorial-trailing-zeroes/solution/xiang-xi-tong-su-de-si-lu-fen-xi-by-windliang-3/
long long Solution::thenumberof0(long long n)
{
    long long res = 0;
    while (n>=5)
    {
        n /= 5;
        res += n; 
    }
    
    return res;
}

int main()
{
    long long n = 1000000000;
    // long long n = 5;
    Solution obj;
    long long result = obj.thenumberof0(n);
    return 0;
}