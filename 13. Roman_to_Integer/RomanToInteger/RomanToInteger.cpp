// RomanToInteger

#include <iostream>

using namespace std;

int romanToInt(string s) {
    int res = 0;
    int i = 0;
    const int len = s.length();
    
    while ((s[i] == 'M') && (i < len)) 
    {
        res += 1000;
        i++;
    }
    if (i == len) return res;

    if (s[i] == 'D')
    {
        res += 500;
        i++;
    }
    if (i == len) return res;

    if ((s[i] == 'C') && ((i+1) < len))
    {
        if (s[i + 1] == 'D') 
        {
            res += 400;
            i += 2;
        }
        else if (s[i + 1] == 'M')
        {
            res += 900;
            i += 2;
        }
    }
    while ((s[i] == 'C') && (i < len))
    {
        res += 100;
        i++;
    }
    if (i == len) return res;


    if (s[i] == 'L')
    {
        res += 50;
        i++;
    }
    if (i == len) return res;


    if ((s[i] == 'X') && ((i + 1) < len))
    {
        if (s[i + 1] == 'C')
        {
            res += 90;
            i += 2;
        }
        else if (s[i + 1] == 'L')
        {
            res += 40;
            i += 2;
        }
    }
    while ((s[i] == 'X') && (i < len))
    {
        res += 10;
        i++;
    }
    if (i == len) return res;



    if (s[i] == 'V')
    {
        res += 5;
        i++;
    }
    if (i == len) return res;



    if ((s[i] == 'I') && ((i+1) < len)) 
    {
        if (s[i + 1] == 'V')
        {
            res += 4;
            i += 2;
        }
        else if (s[i + 1] == 'X')
        {
            res += 9;
            i += 2;
        }
    }
    while ((s[i] == 'I') && (i < len))
    {
        res += 1;
        i++;
    }
    return res;
}

int main()
{
    // 3
    int ans = romanToInt("III");
    cout << ans;
    // 621
    ans = romanToInt("DCXXI");
    cout << ans;
    // 58
    ans = romanToInt("LVIII");
    cout << ans;
    // 1994
    ans = romanToInt("MCMXCIV");
    cout << ans;
}


