#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

bool a[33][33];
int n = 0;
int w, h;
string line[33];

vector<int> neighbor(int x, int y)
{
    vector<int> ans;
    if (x == w-1)
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    else
    {
        bool flag = true;
        for (int i = x+1; i < w; i ++)
            if (a[y][i] == 1)
            {
                flag = false;
                ans.push_back(i);
                ans.push_back(y);
                break;
            }
        if (flag == true)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
    }
    if (y == h-1)
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    else
    {
        bool flag = true;
        for (int i = y+1; i < h; i ++)
            if (a[i][x] == 1)
            {
                flag = false;
                ans.push_back(x);
                ans.push_back(i);
                break;
            }
        if (flag == true)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
    }
    return ans;
}

int main()
{
    //int w; // the number of cells on the X axis
    cin >> w; cin.ignore();
    //int h; // the number of cells on the Y axis
    cin >> h; cin.ignore();
    memset(a, 0, sizeof a);
    for (int i = 0; i < h; i++) {
        //string line; // width characters, each either 0 or .
        cin >> line[i];
        for (int j = 0; j < line[i].size(); j ++)
            if (line[i][j] == '0')
            {
                a[i][j] = 1;
                n ++;
            }
    }
    
    for (int i = 0; i < h; i ++)
    {
        for (int j = 0; j < line[i].size(); j ++)
        {
            if (n == 0) break;
            if (a[i][j] == 0) continue;
            n --;
            cout << j << " " << i << " ";
            vector<int> nei;
            nei = neighbor(j, i);
            for (int k = 0; k < nei.size(); k ++)
                cout << nei[k] << " ";
            cout << endl;
        }
        if (n == 0) break;
    }
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    //cout << "0 0 1 0 0 1" << endl; // Three coordinates: a node, its right neighbor, its bottom neighbor
}
















































