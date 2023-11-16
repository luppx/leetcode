class Solution {
public:
    double myPow(double x, int n) {
        if(x==0 || n==1) return x;
        else if(n==0) return 1;

        long num = n;
        if(n<0)
        {
            x = 1/x;
            num = -1*num;
        }
        double res = 1;
        while(num)
        {
            if(num&1) res *= x;
            num = num>>1;
            x *= x;
        }
        return res;
    }
};