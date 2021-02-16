#include <cmath>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        else if(n==3) return 2;
        int a,b;
        int p = 1000000007;
        a = n / 3;
        b = n % 3;
        if(b==0) return (int)(remainder(3,a,p) % p);
        else if(b==1) return (int)(remainder(3,a-1,p)*4 % p);
        else return (int)(remainder(3,a,p)*2 % p);
        return 0;
    }

private:
    long remainder(int x, int a, int p)
    {
        long rem = 1;
        for (int i = 0; i < a; i++)
        {
            rem = (rem*x) % p;
        }
        return rem;
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;
    int result = obj.cuttingRope(1000);
    return 0;
}