#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string s;
    getline(cin, s);
    
    string ans = "";
    for (int i = 0; i < s.size(); i ++)
    {
        char c = s[i];
        int a = c;
        cerr << a << " " << char(a) << endl;
        string t = "";
        while (a != 0)
        {
            int x = a % 2;
            a = a / 2;
            t += char(x+'0');
        }
        for (int j = t.size(); j < 7; j ++)
            t += '0';
        reverse(t.begin(), t.end());
        ans += t;
    }
    
    cerr << ans << endl;
    
    int x = 0;
    while (x < ans.size())
    {
        int num = 1;
        for (int i = x+1; ; i ++)
        {
            if (ans[i] != ans[x])
                break;
            num ++;
        }
        if (ans[x] == '0') cout << "00 ";
        else cout << "0 ";
        for (int i = 0; i < num; i ++)
            cout << 0;
        if (x+num != ans.size()) cout << " ";
        x += num;
    }
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "answer" << endl;
}