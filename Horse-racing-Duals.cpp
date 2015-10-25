#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<int> a;

int main()
{
    int n;
    cin >> n; cin.ignore();
    a.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; cin.ignore();
    }
    
    sort(a.begin(), a.end());
    int ans = 999999999;
    for (int i = 0; i < n-1; i ++)
    {
        int diff = a[i+1] - a[i];
        if (diff < ans)
            ans = diff;
    }
    cout << ans << endl;
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    //cout << "answer" << endl;
}
















































