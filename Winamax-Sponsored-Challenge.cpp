#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int StrToNum(string s)
{
    int ans = 0;
    bool flag = true;
    for (int i = 0; i < s.size()-1; i ++)
        if ('0' <= s[i] && s[i] <= '9')
        {
            flag = false;
            ans = ans*10 + s[i] - '0';
        }
    if (flag == true)
    {
        if (s[0] == 'A') ans = 14;
        else if (s[0] == 'K') ans = 13;
        else if (s[0] == 'Q') ans = 12;
        else if (s[0] == 'J') ans = 11;
    }
    return ans;
}

queue<int> p[3];
queue<int> d[3];

int main()
{
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string cardp1; // the n cards of player 1
        cin >> cardp1; cin.ignore();
        p[1].push(StrToNum(cardp1));
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++)
    {
        string cardp2; // the m cards of player 2
        cin >> cardp2; cin.ignore();
        p[2].push(StrToNum(cardp2));
    }
    
    int r = 0;
    while (true)
    {
        if (p[1].empty())
        {
            cout << 2 << " " << r << endl;
            return 0;
        }
        if (p[2].empty())
        {
            cout << 1 << " " << r << endl;
            return 0;
        }
        
        bool flag = true;
        int c1, c2;
        while (flag == true)
        {
            flag = false;
            d[1].push(p[1].front());
            d[2].push(p[2].front());
            c1 = p[1].front();
            c2 = p[2].front();
            p[1].pop();
            p[2].pop();
            
            cerr << c1 << " " << c2 << endl;
            if (c1 > c2)
            {
                while (!d[1].empty())
                {
                    p[1].push(d[1].front());
                    d[1].pop();
                }
                while (!d[2].empty())
                {
                    p[1].push(d[2].front());
                    d[2].pop();
                }
            }
            else if (c1 < c2)
            {
                while (!d[1].empty())
                {
                    p[2].push(d[1].front());
                    d[1].pop();
                }
                while (!d[2].empty())
                {
                    p[2].push(d[2].front());
                    d[2].pop();
                }
            }
            else if (c1 == c2)
            {
                if (p[1].size() < 4 || p[2].size() < 4)
                {
                    cout << "PAT" << endl;
                    return 0;
                }
                d[1].push(p[1].front());
                p[1].pop();
                d[1].push(p[1].front());
                p[1].pop();
                d[1].push(p[1].front());
                p[1].pop();
                d[2].push(p[2].front());
                p[2].pop();
                d[2].push(p[2].front());
                p[2].pop();
                d[2].push(p[2].front());
                p[2].pop();
                flag = true;
            }
        }
        r ++;
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    //cout << "PAT" << endl;
}
































