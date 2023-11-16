#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int daysBetweenDates(string& date1, string& date2);

private:
    int dateToInt(string& date);
    bool isLeapYear(int year);
};

int Solution::daysBetweenDates(string& date1, string& date2) {
    return abs(dateToInt(date2) - dateToInt(date1));
}

int Solution::dateToInt(string& date)
{
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

    int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int res = day;
    
    while(month!=0)
    {
        month--;
        res += m[month];
        if(month==2 && isLeapYear(year)) res++;
    }

    res += (year-1971)*365;
    res += (year-1)/4 - 1971/4;
    res -= (year-1)/100 - 1971/100;
    res += (year-1)/400 - 1971/400;
    return res;
}

bool Solution::isLeapYear(int year)
{
    return ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0));
}


int main()
{
    string date1 = "2019-06-29";
    string date2 = "2019-06-30";
    Solution obj;
    int result = obj.daysBetweenDates(date1, date2);
    cout<<result<<endl;
    return 0;
}