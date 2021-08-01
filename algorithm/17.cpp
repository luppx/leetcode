#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits);

private:
    void recur(int index, int n);
    unordered_map<char, string> umap;
    vector<string> res;
    vector<string> digitToLetterVector;
    string cur;
};

vector<string> Solution::letterCombinations(string digits) {
    if(digits.empty() || digits=="1") return {};

    umap['2'] = "abc";
    umap['3'] = "def";
    umap['4'] = "ghi";
    umap['5'] = "jkl";
    umap['6'] = "mno";
    umap['7'] = "pqrs";
    umap['8'] = "tuv";
    umap['9'] = "wxyz";
    for(auto digit: digits)
    {
        if(umap.find(digit)!=umap.end()) digitToLetterVector.emplace_back(umap[digit]);
    }
    recur(0, digitToLetterVector.size());
    return res;
}

void Solution::recur(int index, int n)
{
    if(cur.size()==n)
    {
        res.emplace_back(cur);
        return;
    }
    if(index==n) return;

    for(int i=0; i<digitToLetterVector[index].size(); i++)
    {
        cur.push_back(digitToLetterVector[index][i]);
        recur(index+1, n);
        cur.pop_back();
    }
    return;
}