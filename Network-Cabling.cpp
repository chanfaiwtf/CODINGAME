#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

long long a[100010][2];

int main()
{
    long long ans = 0, sumy = 0;
    long long n;
    long long maxx = 0, minx = 2000000000, xx;
    cin >> n; cin.ignore();
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        if (a[i][0] < minx) minx = a[i][0];
        if (a[i][0] > maxx) maxx = a[i][0];
        sumy += a[i][1];
    }
    xx = maxx - minx;
    sumy = sumy / n;
    
    long long mind = 0, yy = 0;
    for (int i = 0; i < n; i ++)
    {
        long long tmp = abs(a[i][1]-sumy);
        if (i == 0 || tmp < mind)
        {
            mind = tmp;
            yy = a[i][1];
        }
    }
    
    ans = xx;
    for (int i = 0; i < n; i ++)
        ans += abs(a[i][1] - yy);
    
    cout << ans << endl;
    
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    // cout << "answer" << endl;
}