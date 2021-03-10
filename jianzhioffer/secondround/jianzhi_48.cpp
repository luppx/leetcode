#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    Solution();
    ~Solution();
    int lengthOfLongestSubstring(string s);
};

Solution::Solution()
{

}

Solution::~Solution()
{

}

// //暴力线性遍历。时间复杂度O(N^3)，空间复杂度O(N)
// int Solution::lengthOfLongestSubstring(string s)
// {
//     if(s.empty()) return 0;
//     string longestSubString = "";
//     int length = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         for (int j = i; j < s.size(); j++)
//         {
//             if (longestSubString.find_last_of(s[j])==string::npos)
//             {
//                 longestSubString += s[j];
//             }
//             else break;
//         }
//         length = max(length, (int)longestSubString.size());
//         longestSubString.clear();
//         if(length>=s.size()-i-1) break; //如果当前最长无重复子字符串的长度大于等于剩下的字符个数，则当前长度即为最大无重复子字符串的长度，不用再遍历
//     }
//     return length;
// }

//方法二，动态规划+哈希表。
//设dp[j]表示以s[j]结尾的最长不重复字符串的长度。
//设i为j左边第一个与s[j]重复(即s[i]==s[j])的元素，则j-i表示以s[j]结尾的最长无重复字符串的长度
//1.如果i<0，说明没有重复字符，则dp[j] = dp[j-1]+1
//2.如果j-i>dp[j-1]，说明s[i]的位置还在现有无重复子字符串左边界的左边，即在子字符串dp[j-1]的区间之外，则dp[j]=dp[j-1]+1
//3.如果j-i<=dp[j-1]，说明s[i]在dp[j-1]的区间之内，则dp[j]=j-i
//判断时条件1和2可以合并。最后遍历dp数组找出最大值即可。优化：用max_length存储dp的最大值，则省去dp数组占的O(N)空间。
//用哈希表存储字符x最后一次出现的位置，计算dp[j]查找i的位置时查找哈希表即可。遍历哈希表的时间复杂度O(N)，空间复杂度O(1)(因为字符的ASCII码在0-127，哈希表最多存储127个键值对，所以空间复杂度O(1))
//综上，时间复杂度O(N)，空间复杂度O(1)
// int Solution::lengthOfLongestSubstring(string s)
// {
//     if(s.empty()) return 0;
//     unordered_map<char, int> map;
//     map.insert(pair<char, int>(s[0], 0));
//     int length = 1;  //存储最长无重复子字符串的长度
//     int tmp = 1;  //令tmp存储dp[j-1]
//     for (int j = 1; j < s.size(); j++)
//     {
//         if(map.find(s[j])==map.end()) map[s[j]] = -1;  //如果哈希表中未出现目标字符，则令map[s[j]]=-1,保证j-i>dp[j-1]
//         if (j-map[s[j]]>tmp)
//         {
//             tmp++;
//         }
//         else
//         {
//             tmp = j - map[s[j]];
//         }
//         map[s[j]] = j;
//         length = max(length, tmp);
//     }
//     return length;
// }

//方法三，滑动窗口+哈希表。窗口表示以s[j]结尾的最长无重复子字符串。
//i,j分别为窗口的左右边界，让窗口内的字符串无重复，如果有重复，则窗口左边界i需右移，直到不重复
//length = max(length, j-i)
//时间复杂度O(N)，空间复杂度O(1)
int Solution::lengthOfLongestSubstring(string s)
{
    if(s.empty()) return 0;
    unordered_map<char,int> map;
    int length = 0;
    int i = -1;
    for (int j = 0; j < s.size(); j++)
    {
        if(map.find(s[j])!=map.end())
        {
            //考虑map[s[j]]在i左侧的情况。比如abba，当遍历到最后一个a时，此时i=2,j=3，map['a']还等于0，
            //如果没有max，则i会更新为0，最终计算出的length=3，错误。
            i = max(i, map[s[j]]);          
        }
        map[s[j]] = j;
        length = max(length, j-i);
    }
    return length;
}

int main(int argc, char const *argv[])
{
    string s = "abba";
    Solution obj;
    int result = obj.lengthOfLongestSubstring(s);
    return 0;
}
