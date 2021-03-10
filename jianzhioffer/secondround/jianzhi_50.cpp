#include <unordered_map>
using namespace std;

class Solution
{
public:
    Solution();
    ~Solution();
    char firstUniqChar(string s);
};

Solution::Solution()
{

}

Solution::~Solution()
{

}

//哈希表。时间复杂度O(N)，空间复杂度O(1)(题目说了字符串中只有小写字母，所以哈希表最多占用O(26)的空间，即空间复杂度为O(1))
char Solution::firstUniqChar(string s)
{
    if(s.empty()) return ' ';
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++)
    {
        map[s[i]]++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if(map[s[i]]==1)
        {
            return s[i];
        }
    }
    return ' ';
}

int main(int argc, char const *argv[])
{
    string s = "abaccdeff";
    Solution obj;
    char result = obj.firstUniqChar(s);
    return 0;
}
