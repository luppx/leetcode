#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canConstruct(string& ransomNote, string& magazine);
};

bool Solution::canConstruct(string& ransomNote, string& magazine)
{
    if(ransomNote.empty() || magazine.empty()) return false;

    unordered_map<char, int> umap;
    for (char s : magazine)
    {
        umap[s]++;
    }
    
    for(char s : ransomNote)
    {
        if(umap.find(s)==umap.end() || umap[s]==0)
        {
            return false;
        }
        umap[s]--;
    }
    return true;
}

int main()
{
    return 0;
}