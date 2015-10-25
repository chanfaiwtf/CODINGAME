#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
string ROW[33];
string ans[33];

int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    for (int i = 0; i < H; i++) 
    {
        getline(cin, ROW[i]);
    }
    
    for (int k = 0; k < T.size(); k ++)
    {
        int num;
        if ('A' <= T[k] && T[k] <= 'Z') num = T[k] - 'A';
        else if ('a' <= T[k] && T[k] <= 'z') num = T[k] - 'a';
        else num = 26;
        for (int i = num*L; i < (num+1)*L; i ++)
        {
            for (int j = 0; j < H; j ++)
                ans[j] += ROW[j][i];
        }
    }
    
    for (int i = 0; i < H; i ++)
    {
        for (int j = 0; j < ans[i].size(); j ++)
            cout << ans[i][j];
        cout << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "answer" << endl;
}