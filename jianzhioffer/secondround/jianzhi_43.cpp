class Solution
{
public:
    Solution();
    ~Solution();
    int countDigitOne(int);
};

Solution::Solution()
{

}

Solution::~Solution()
{

}

int Solution::countDigitOne(int num)
{
    long digit = 1;
    int cur = num % 10;
    int high = num/10;
    int low = 0;
    int res = 0;
    while (cur!=0 || high!=0)
    {
        if(cur==0)
        {
            res += high*digit;
        }
        else if(cur==1)
        {
            res += high*digit + low + 1;
        }
        else
        {
            res += (high+1)*digit;
        }
        low += cur*digit;
        digit *= 10;
        cur = high % 10;
        high /= 10;
        
    }
    return res;
}

int main(int argc, char const *argv[])
{
    Solution obj;
    int result = obj.countDigitOne(13);
    return 0;
}
